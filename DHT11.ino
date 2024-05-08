#include <DHT.h>

#define BLYNK_TEMPLATE_ID "TMPL6_qNu-toC" // (Optional: For Blynk integration)
#define BLYNK_TEMPLATE_NAME "SENSOR SUHU DAN KELEMBABAN" // (Optional: For Blynk integration)
#define BLYNK_AUTH_TOKEN "aI_P4rXedduktBin2fgMn93hPNxFN1p3" // (Optional: For Blynk integration)

#define DHTPIN 18
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

int lampu = 12; // Pin terhubung ke lampu
float kelembaban; // Menggunakan nama yang lebih deskriptif
float suhu;     // Menggunakan nama yang lebih deskriptif

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(lampu, OUTPUT); // Setel pin lampu sebagai output
}

void loop() {
  kelembaban = dht.readHumidity();
  suhu = dht.readTemperature();

  Serial.print("Kelembaban: ");
  Serial.print(kelembaban);
  Serial.print("%  ");
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.print("°C\n");

  if (suhu > 30) {
    digitalWrite(lampu, HIGH); // Nyalakan lampu
  } else {
    digitalWrite(lampu, LOW); // Matikan lampu
  }

  delay(2000);
}
