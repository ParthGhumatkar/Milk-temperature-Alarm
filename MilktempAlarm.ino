#include <OneWire.h>
#include <DallasTemperature.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define ONE_WIRE_BUS 8
#define Buzzer 3

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress MilkThermometer;

float Celsius = 0;

void setup() {
  sensors.begin();
  lcd.init();
  lcd.backlight();
  Serial.print(sensors.getDeviceCount(), DEC);
}

void loop() {
  sensors.requestTemperatures();
  Celsius = sensors.getTempCByIndex(0);

  lcd.setCursor(0, 1);
  lcd.print(Celsius);
  lcd.print(" Celsius: ");
  lcd.setCursor(0, 2);
   delay(100);
    sensors.setHighAlarmTemp(MilkThermometer, 94);
}
  

  void checkAlarm(DeviceAddress deviceAddress)
{
  if (sensors.hasAlarm(deviceAddress))
  {
    digitalWrite(Buzzer,HIGH);
    }
    else{
      digitalWrite(Buzzer,LOW);
    }
}
