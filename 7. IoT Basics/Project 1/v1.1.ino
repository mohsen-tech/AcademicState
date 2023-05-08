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

#define SenderNo "+989360668040"
String ReceiveFromSim()
{
  String temp = "";
  while (mySerial.available())
  {
    temp += mySerial.readString();
    // Forward what Software Serial received to Serial Port
  }
  if (temp != "")
  {
    if (temp.indexOf("+CMT") > 0)
    {
      mySerial.println("AT+CMGR=1\r\n");
      digitalWrite(LED_BUILTIN, LOW);
      delay(500);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN, LOW);
      delay(500);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN, LOW);
      delay(500);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(500);
    }
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
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

int Run(String command)
{
  if (command.indexOf("on") > 0)
  {
    digitalWrite(D7, LOW); // on
    Serial.println("\n*** LED is On ***\n");
    return 1;
  }
  else if (command.indexOf("off") > 0)
  {
    digitalWrite(D7, HIGH); // off
    Serial.println("\n*** LED is Off ***\n");
    return 2;
  }
  else
    Serial.println("Command Error");
  return -1;
}

bool CheckSenderValid(String command)
{
  if (command.indexOf(SenderNo) > 0)
    return true;
  return false;
}

void SendSMS(String number, String text)
{
  // Can take up to 60 seconds
  mySerial.print(F("AT+CMGF=1\r")); // set sms to text mode
  ReceiveFromSim();
  mySerial.println("AT+CSMP=17,167,0,0");
  ReceiveFromSim();

  mySerial.print(F("AT+CMGS=\"")); // command to send sms
  mySerial.print(number);
  mySerial.print(F("\"\r"));
  ReceiveFromSim();

  mySerial.print(text);
  mySerial.print("\r");
  ReceiveFromSim();

  mySerial.print((char)26);
  // try to read result from sim800 (max response 60s)
}

String mySMS = "";
void handleSms()
{
  if (mySMS != "")
  {
    server.send(200, "text/html", mySMS);
    mySMS = "";
  }
  else
    server.send(200, "text/html", "NULL");
}
void setup()
{
  pinMode(D7, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  delay(6000);
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.begin(BAUD_RATE);
  Serial.println("\nstart from here");

  // Begin serial communication with Arduino and SIM800L
  mySerial.begin(BAUD_RATE);
  mySerial.setTimeout(10000);

  mySerial.println("AT"); // Once the handshake test is successful, it will back to OK
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
  updateSerial();

  if (WiFiConfig() == true)
  {
    server.on("/sms", handleSms);
    server.begin();
  }

  // String command;

  // mySerial.println("AT+CNMI=2,1,0,0"); // new received sms stroe in memory
  // ReceiveFromSim();

  // mySerial.print("AT+CMGL=\"REC UNREAD\",1\r\n"); // read unrec (last newly received sms)
  // command = ReceiveFromSim();
  // Serial.println("\n*****\n");
  // Serial.println(command);
  // Serial.println("\n*****\n");

  // if (CheckSenderValid(command)) // check number and run
  // {
  //   int check = Run(command);

  //   mySerial.print("AT+CMGDA=\"DEL ALL\"\r\n"); // delete sms
  //   Serial.println(ReceiveFromSim());

  //   if (check > 0)
  //   {
  //     SendSMS(SenderNo, "Your Command is Run");
  //     Serial.println("\nSMS is sent");
  //   }
  //   else
  //   {
  //     SendSMS(SenderNo, "Your Command is Wrong");
  //     Serial.println("\nSMS is sent");
  //   }
  // }

  // delay(3000); // just for show
  // Serial.println("Wemos goes to sleep...");
  // ESP.deepSleep(0);

  // initProgram();
  // if (currentState == false)
  // {
  //   if (WiFiConfig() == true)
  //   {
  //     serverConfig();
  //   }
  // }
  // else
  // {
  //   Serial.println("ESP.deepSleep");
  //   delay(2000);
  //   ESP.deepSleep(0);
  // }
}
void loop()
{
  if (mySMS == "")
  {
    mySMS = ReceiveFromSim();
  }
  server.handleClient();
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
  EEPROM.begin(EEPROM_size);
  delay(1);
  // EEPROM.write(EEPROM_phoneNumberLengthIdx, 0);
  // delay(1);
  // EEPROM.commit();
  // delay(1);

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
  // WiFi.mode(WIFI_AP);
  // if (WiFi.softAP(SSID, PASSWORD) == true)
  //   Serial.println(WiFi.localIP());
  WiFi.mode(WIFI_STA);
  WiFi.begin("S10+", "1223334444");
  if (WiFi.waitForConnectResult(200000) != WL_CONNECTED)
  {
    Serial.println("WiFi Failed!");
    return false;
  }
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

      generateCode(validationCode);
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
      return;
    }
  }
  server.send(200, "text/html", "Error in validation<br><a href=\"/\">Return to Home Page</a>");
}
void handleNotFound()
{
  server.send(404, "text/plain", "Error 404 - Not Found!");
}