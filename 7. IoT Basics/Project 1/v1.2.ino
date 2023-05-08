#include <Arduino.h>
#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>

// false == No phoneNumber | true == With phoneNumber
bool currentState;
String ownersPhoneNumber = "";
void initProgram();

#define EEPROM_size 30
#define EEPROM_magicNumber 13
#define EEPROM_magicIdx 0
#define EEPROM_phoneNumberLengthIdx 1
void saveToEEPROM(const String &_str, const byte &_from);
bool loadFromEEPROM(String &_str, const byte &_from);

#define SSID "Smart Door"
#define PASSWORD "a1b2c3d4"
bool WiFiConfig();

ESP8266WebServer server(80);
#define PARAM_INPUT1 "phoneNumber"
#define PARAM_INPUT2 "code"
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>Smart Door Input Form</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  </head><body>
  <form action="/get">
    Your Phone Number: <input type="text" name="phoneNumber">
    <input type="submit" value="Submit">
  </form><br>
</body></html>)rawliteral";
const char valid_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>Smart Door Input Form</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  </head><body>
  <form action="/valid">
    A code has been sent to you to validate your phone number, please enter it: <input type="text" name="code">
    <input type="submit" value="Submit">
  </form><br>
</body></html>)rawliteral";
String validationCode;
void serverConfig();
void handleClient();
String generateCode(String &_str, const byte &_codeSize);
void handleGet();
void handleValid();
void handleNotFound();

/*
D1 TX
D2 RX

D5 ring
D6 DTR
D7 digital out
*/

SoftwareSerial mySerial(D1, D2);
#define BAUD_RATE 9600

String receiveFromSim()
{
  String temp = "";
  while (mySerial.available())
  {
    temp += mySerial.readString();
  }
  if (temp != "" && temp.indexOf("+CMT") > 0)
  {
    mySerial.println("AT+CMGR=1\r\n");
    while (mySerial.available())
    {
      temp += mySerial.readString();
    }
    Serial.println(temp);
  }
  return temp;
}

void updateSerial()
{
  delay(500);
  while (Serial.available())
  {
    mySerial.write(Serial.read()); // Forward what Serial received to Software Serial Port
  }
  while (mySerial.available())
  {
    Serial.write(mySerial.read()); // Forward what Software Serial received to Serial Port
  }
}

void sendSMS(const String &number, const String &text)
{
  mySerial.print("AT+CMGDA=\"DEL ALL\"\r\n"); // delete sms
  updateSerial();
  mySerial.print(F("AT+CMGS=\"")); // command to send sms
  mySerial.print(number);
  mySerial.print(F("\"\r"));
  updateSerial();
  mySerial.print(text); // text content
  updateSerial();
  mySerial.write(26);
}
void runCommand(const String &command)
{
  if (command.indexOf("open") > 0)
  {
    digitalWrite(LED_BUILTIN, LOW); // on
    Serial.println("\n*** LED is On ***\n");
    sendSMS(ownersPhoneNumber, "Your Command is Run");
  }
  else if (command.indexOf("close") > 0)
  {
    digitalWrite(LED_BUILTIN, HIGH); // off
    Serial.println("\n*** LED is Off ***\n");
    sendSMS(ownersPhoneNumber, "Your Command is Run");
  }
  else if (command.indexOf("status") > 0)
  {
    bool value = digitalRead(LED_BUILTIN);
    Serial.println("\n*** status ***\n");
    if (value == true)
      sendSMS(ownersPhoneNumber, "door is open");
    else
      sendSMS(ownersPhoneNumber, "door is close");
  }
  else if (command.indexOf("reset") > 0)
  {
    ///
    EEPROM.write(EEPROM_phoneNumberLengthIdx, 0);
    delay(1);
    EEPROM.commit();
    delay(1);
    ///
    sendSMS(ownersPhoneNumber, "reset factory");
    Serial.println("\n*** restart ***\n");
    ESP.restart();
  }
  else
  {
    sendSMS(ownersPhoneNumber, "Your Command is Wrong");
    Serial.println("Command Error");
  }
}

bool checkSenderValid(const String &command)
{
  if (command.indexOf(ownersPhoneNumber) > 0)
    return true;
  return false;
}

String mySMS = "";
void setup()
{
  initProgram();
  if (currentState == false)
  {
    if (WiFiConfig() == true)
    {
      serverConfig();
    }
  }
  else
  {
    pinMode(D7, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);

    mySerial.begin(BAUD_RATE);
    mySerial.setTimeout(10000);
    mySerial.println("AT"); // Once the handshake test is successful, it will back to OK
    updateSerial();
    mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
    updateSerial();
  }
}
void loop()
{
  if (currentState == false)
  {
    server.handleClient();
  }
  else
  {
    mySMS = receiveFromSim();
    if (mySMS != "" && checkSenderValid(mySMS) == true)
    {
      runCommand(mySMS);
    }
    
  }
}

void saveToEEPROM(const String &_str, const byte &_from)
{
  EEPROM.write(_from, _str.length());
  delay(1);
  byte j = 0;
  for (byte i = _from + 1; i < _from + _str.length() + 1; i++)
  {
    EEPROM.write(i, _str[j++]);
    delay(1);
  }
  EEPROM.commit();
  delay(1);
}
bool loadFromEEPROM(String &_str, const byte &_from)
{
  byte phoneNumberLength = EEPROM.read(_from);
  delay(1);
  if (phoneNumberLength == 0)
  {
    return false;
  }
  else
  {
    _str = "";
    for (byte i = _from + 1; i < _from + phoneNumberLength + 1; i++)
    {
      _str += (char)EEPROM.read(i);
      delay(1);
    }
    return true;
  }
}

void initProgram()
{
  Serial.begin(BAUD_RATE);
  EEPROM.begin(EEPROM_size);
  delay(1);

  if (EEPROM.read(EEPROM_magicIdx) != EEPROM_magicNumber)
  {
    EEPROM.write(EEPROM_magicIdx, EEPROM_magicNumber);
    delay(1);
    EEPROM.write(EEPROM_phoneNumberLengthIdx, 0);
    delay(1);
    EEPROM.commit();
    delay(1);
    currentState = false;
  }
  else
  {
    bool sw = loadFromEEPROM(ownersPhoneNumber, EEPROM_phoneNumberLengthIdx);
    if (sw == false)
    {
      currentState = false;
    }
    else
    {
      Serial.println(ownersPhoneNumber);
      currentState = true;
    }
  }
}

bool WiFiConfig()
{
  WiFi.mode(WIFI_AP);
  if (WiFi.softAP(SSID, PASSWORD) == true)
    Serial.println(WiFi.localIP());
  // WiFi.mode(WIFI_STA);
  // WiFi.begin("S10+", "1223334444");
  // if (WiFi.waitForConnectResult(200000) != WL_CONNECTED)
  // {
  //   Serial.println("WiFi Failed!");
  //   return false;
  // }
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  return true;
}

void serverConfig()
{
  server.on("/", HTTP_GET, handleClient);
  server.on("/get", HTTP_GET, handleGet);
  server.on("/valid", HTTP_GET, handleValid);
  server.onNotFound(handleNotFound);
  server.begin();
}
void handleClient()
{
  server.send(200, "text/html", index_html);
}
String generateCode(String &_str, const byte &_codeSize = 4)
{
  _str = "";
  for (byte i = 0; i < _codeSize; i++)
    _str += random(9);
  ///
  Serial.print("code: ");
  Serial.println(_str);
  return _str;
}
void handleGet()
{
  String inputMessage, inputParam;
  if (server.hasArg(PARAM_INPUT1))
  {
    inputMessage = server.arg(PARAM_INPUT1);
    inputParam = PARAM_INPUT1;
    if (inputMessage != "")
    {
      ownersPhoneNumber = inputMessage;
      ///
      mySerial.begin(BAUD_RATE);
      mySerial.setTimeout(10000);
      mySerial.println("AT"); // Once the handshake test is successful, it will back to OK
      updateSerial();
      mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
      updateSerial();
      sendSMS(ownersPhoneNumber, generateCode(validationCode));
      ///
      server.send(200, "text/html", valid_html);
      return;
    }
  }
  server.send(200, "text/html", "The entered values are not correct!<br><a href=\"/\">Return to Home Page</a>");
  // server.send(200, "text/html", "HTTP GET request sent to your ESP on input field (" + inputParam + ") with value: " + inputMessage + "<br><a href=\"/\">Return to Home Page</a>");
}
void handleValid()
{
  String inputMessage, inputParam;
  if (server.hasArg(PARAM_INPUT2))
  {
    inputMessage = server.arg(PARAM_INPUT2);
    inputParam = PARAM_INPUT2;
    if (inputMessage != "" && inputMessage == validationCode)
    {
      Serial.println(ownersPhoneNumber);
      saveToEEPROM(ownersPhoneNumber, EEPROM_phoneNumberLengthIdx);
      server.send(200, "text/html", "Validation was successful");
      delay(1000);
      ESP.restart();
    }
  }
  server.send(200, "text/html", "Error in validation<br><a href=\"/\">Return to Home Page</a>");
}
void handleNotFound()
{
  server.send(404, "text/plain", "Error 404 - Not Found!");
}