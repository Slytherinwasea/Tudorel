#include "DHT.h"
int DHTPIN =  8 ;    // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);

int STATE_HUMIDITY_TEMP = 1;
int STATE_TEMP = 1;
int sv = A0;
float v = 0;
float Temp = 0;

int STATE_FLAME = 1;
int flamepin = 8;
int k ;

void getTemperature1(float sv) {
  if (STATE_TEMP == 1) {
    v = analogRead(sv);
    Temp = log(10000.0 / (1024.0 / v - 1));

    Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);

    Temp = Temp - 273.15; // Convert Kelvin to Celcius
    Serial.println(Temp);
    delay(1000);
  }
  else {
    Serial.println("None");
  }
}

void getTempHumidity2(int DHTPIN) {
  if (STATE_HUMIDITY_TEMP == 1) {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
  }
  else {
    Serial.println("No data");
  }
}

void getFlame(int flamepin) {
  if (STATE_FLAME == 1) {
    k = digitalRead(flamepin);
    if (k == HIGH) {
      Serial.println("Fire");
    }
    else {
      Serial.println("No fire");
    }
  }
  else {
    Serial.println("No data");
  }
}


void setup()
{
  Serial.begin(9600);
  pinMode(v, INPUT);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  pinMode(flamepin,INPUT);
}

void loop() {
  getTemperature1(sv);
  getTempHumidity2(DHTPIN);
  getFlame(flamepin);
  delay(500);

}
