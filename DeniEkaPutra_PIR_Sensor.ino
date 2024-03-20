#include <LiquidCrystal_I2C.h>

const int pirSensor = 7;
const int buzz = 8;

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address, LCD width, height

void setup() {
  Serial.begin(9600);  // Initialize serial communication for debugging (optional)
  pinMode(pirSensor, INPUT);
  pinMode(buzz, OUTPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {
  int sensorValue = digitalRead(pirSensor);

  Serial.println(sensorValue);  // Optional for debugging

  lcd.setCursor(8, 0);  // Set cursor position
  lcd.print("Deteksi:");

  if (sensorValue == HIGH) {
    digitalWrite(buzz, HIGH);
    lcd.setCursor(4, 1);
    lcd.print("ADA GERAKAN");
  } else {
    digitalWrite(buzz, LOW);
    lcd.setCursor(5, 1);
    lcd.print("TIDAK ADA");
    lcd.setCursor(4, 2);
    lcd.print("GERAKAN");
  }

  delay(500);
  lcd.clear();
}
