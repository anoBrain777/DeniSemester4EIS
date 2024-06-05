#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD dengan alamat I2C 0x27 (bisa berbeda, cek modul I2C Anda)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int sensorGasPin = A0; // Pin analog untuk sensor gas
const int buzzerPin = 8; // Pin digital untuk buzzer
const int gasThreshold = 300; // Ambang batas nilai sensor gas

void setup() {
  // Inisialisasi pin
    pinMode(sensorGasPin, INPUT);
      pinMode(buzzerPin, OUTPUT);
        
          // Inisialisasi LCD
            lcd.begin();
              lcd.backlight();
                
                  // Pesan awal
                    lcd.setCursor(0, 0);
                      lcd.print("Sensor Gas MQ");
                        delay(2000);
                          lcd.clear();
                          }

                          void loop() {
                            // Membaca nilai sensor gas
                              int sensorValue = analogRead(sensorGasPin);
                                
                                  // Menampilkan nilai sensor gas di LCD
                                    lcd.setCursor(0, 0);
                                      lcd.print("sensor_gas:");
                                        lcd.setCursor(0, 1);
                                          lcd.print(sensorValue);
                                            
                                              // Mengaktifkan buzzer jika nilai sensor melebihi ambang batas
                                                if (sensorValue > gasThreshold) {
                                                    digitalWrite(buzzerPin, HIGH);
                                                      } else {
                                                          digitalWrite(buzzerPin, LOW);
                                                            }
                                                              
                                                                delay(1000); // Delay 1 detik sebelum pembacaan berikutnya
                                                                }
                                                                