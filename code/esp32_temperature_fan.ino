#define BLYNK_TEMPLATE_ID   "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "IoT Temperature Controlled Fan"
#define BLYNK_AUTH_TOKEN    "YOUR_DEVICE_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// Replace these with your Wi-Fi credentials
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// DHT11 sensor
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

// L298N motor driver pins
const int ENA = 25;  // PWM speed control
const int IN1 = 26;  // Motor direction
const int IN2 = 27;  // Motor direction

// Temperature thresholds
const float MIN_TEMP = 25.0;
const float MAX_TEMP = 40.0;

// Fan speed limits
const int MIN_PWM = 90;
const int MAX_PWM = 255;

// Control variables
bool manualMode = false;
int manualSpeed = 0;
int currentPWM = 0;

float temperature = NAN;
float humidity = NAN;

bool sensorValid = false;

// Stop the fan
void stopFan() {
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  currentPWM = 0;
}

// Set fan speed and direction
void setFanSpeed(int pwm) {
  pwm = constrain(pwm, 0, MAX_PWM);

  if (pwm == 0) {
    stopFan();
    return;
  }

  // Fixed forward direction
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENA, pwm);

  currentPWM = pwm;
}

// Read temperature and control the fan
void updateFan() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  // Stop the fan if the sensor reading is invalid
  if (isnan(t) || isnan(h)) {
    sensorValid = false;
    stopFan();

    Serial.println("DHT11 reading failed. Fan stopped.");

    if (Blynk.connected()) {
      Blynk.virtualWrite(V3, 0);
    }

    return;
  }

  sensorValid = true;
  temperature = t;
  humidity = h;

  // Automatic or manual control
  if (manualMode) {
    int pwm = map(manualSpeed, 0, 100, 0, 255);
    setFanSpeed(pwm);
  } else {
    if (temperature < MIN_TEMP) {
      stopFan();
    }
    else if (temperature >= MAX_TEMP) {
      setFanSpeed(MAX_PWM);
    }
    else {
      int pwm = MIN_PWM +
        (int)((temperature - MIN_TEMP) *
        (MAX_PWM - MIN_PWM) /
        (MAX_TEMP - MIN_TEMP));

      setFanSpeed(pwm);
    }
  }

  // Serial Monitor output
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Mode: ");
  Serial.println(manualMode ? "Manual" : "Automatic");

  Serial.print("PWM: ");
  Serial.println(currentPWM);

  Serial.println("----------------------");

  // Send readings to the Blynk dashboard
  if (Blynk.connected()) {
    Blynk.virtualWrite(V0, temperature);
    Blynk.virtualWrite(V3,
      (currentPWM * 100L) / 255);
  }
}

// Automatic/manual mode switch
BLYNK_WRITE(V1) {
  manualMode = (param.asInt() == 1);
}

// Manual fan speed slider
BLYNK_WRITE(V2) {
  manualSpeed = constrain(param.asInt(), 0, 100);
}

void setup() {
  Serial.begin(115200);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  stopFan();

  dht.begin();

  // Connect to Wi-Fi and Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Read sensor and update fan every 2 seconds
  timer.setInterval(2000L, updateFan);

  Serial.println("ESP32 Temperature-Controlled Fan Started");
}

void loop() {
  Blynk.run();
  timer.run();
}