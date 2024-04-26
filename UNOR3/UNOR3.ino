#include "DHT.h"
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include "DFRobot_RGBLCD1602.h"
#include <iarduino_OLED.h> 

#define DHTPIN A0
#define DHTTYPE DHT11

iarduino_OLED myOLED(0x3C); 
DFRobot_RGBLCD1602 lcd(16,2); 
Adafruit_BMP085 bmp180;
DHT dht(DHTPIN, DHTTYPE);

extern uint8_t MediumFontRus[];
extern uint8_t SmallFontRus[];

void setup() {
  Serial.begin(57600);
  lcd.init();
  bmp180.begin();
  dht.begin();
  myOLED.begin();
  myOLED.setFont(SmallFontRus);
  lcd.clear();
  lcd.setCursor(0,0);
}

void loop() {
  delay(2000);
  lcd.clear();
  myOLED.clrScr();
  lcd.setCursor(0,0);
  int humidity = dht.readHumidity();
  int temperature = dht.readTemperature();
  uint32_t pres = bmp180.readPressure();
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" Hum: ");
  lcd.print(humidity);
  lcd.setCursor(0,1);
  lcd.print("Pa ");
  lcd.print(pres);
  myOLED.print(F("Temp:"),      0,      15);
  myOLED.print(temperature,      60,      15);
  myOLED.print(F("Hum:"),      0,      30);
  myOLED.print(humidity,      60,      30);
  myOLED.print(F("Pa:"),      0,      45);
  myOLED.print(pres,      60,      45);
}
