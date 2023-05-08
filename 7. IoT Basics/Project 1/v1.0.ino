#include <Arduino.h>
#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define BAUD_RATE 9600
#define SSID "Smart Door"
#define PASSWORD "a1b2c3d4"

#define EEPROM_size 30
#define EEPROM_magicNumber 13
#define EEPROM_magicIdx 0
#define EEPROM_phoneNumberLengthIdx 1

ESP8266WebServer server(80);

// false == No phoneNumber | true == With phoneNumber
bool currentState;
String ownersPhoneNumber = "";

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
void handleClient()
{
  server.send(200, "text/html", index_html);
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
void setup()
{
  Serial.begin(BAUD_RATE);
  Serial.println();
  EEPROM.begin(EEPROM_size);

  // EEPROM.write(EEPROM_phoneNumberLengthIdx, 0);
  // delay(1);
  // EEPROM.commit();
  // delay(1);

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

  if (currentState == false)
  {
    // WiFi.mode(WIFI_AP);
    // if (WiFi.softAP(SSID, PASSWORD) == true)
    //   Serial.println(WiFi.localIP());
    WiFi.mode(WIFI_STA);
    WiFi.begin("S10+", "1223334444");
    if (WiFi.waitForConnectResult(200000) != WL_CONNECTED)
    {
      Serial.println("WiFi Failed!");
      return;
    }
    Serial.println();
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    server.on("/", HTTP_GET, handleClient);
    server.on("/get", HTTP_GET, handleGet);
    server.on("/valid", HTTP_GET, handleValid);
    server.onNotFound(handleNotFound);
    server.begin();
  }
  else
  {
    Serial.println("ESP.deepSleep");
    delay(2000);
    ESP.deepSleep(0);
  }
}
void loop()
{
  server.handleClient();
}