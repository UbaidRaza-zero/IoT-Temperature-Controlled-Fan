IoT-BASED TEMPERATURE-CONTROLLED FAN

PROJECT OVERVIEW

The IoT-Based Temperature-Controlled Fan is designed to automatically control the speed of a DC fan according to the surrounding temperature.

The system uses an ESP32 microcontroller and a DHT11 temperature sensor to monitor environmental conditions. Based on the temperature readings, the ESP32 controls the fan speed through an L298N motor driver using PWM (Pulse Width Modulation).

The project also integrates the Blynk IoT platform, enabling users to monitor temperature and control the fan remotely through a mobile dashboard.


FEATURES

- Automatic fan-speed control based on temperature.
- Temperature and humidity monitoring.
- PWM-based fan-speed regulation.
- Wi-Fi connectivity using ESP32.
- Remote monitoring through Blynk IoT.
- Automatic and manual fan-control modes.


COMPONENTS USED

- ESP32 Development Board
- DHT11 Temperature and Humidity Sensor
- L298N Motor Driver
- DC Motor / DC Fan
- External DC Power Supply
- Breadboard and Jumper Wires


WORKING PRINCIPLE

1. The DHT11 sensor measures the surrounding temperature and humidity.
2. The sensor sends the readings to the ESP32.
3. The ESP32 processes the temperature data.
4. Based on the temperature, the ESP32 generates PWM signals to control the fan speed.
5. The L298N motor driver drives the DC fan according to the control signals.
6. The ESP32 communicates with the Blynk IoT platform through Wi-Fi for remote monitoring and control.


TEMPERATURE-BASED FAN CONTROL

The fan operates according to the following temperature conditions:

- Below 25°C – Fan OFF.
- At 25°C – Low Speed.
- At 30°C – Medium Speed.
- At 35°C – High Speed.
- At 40°C and above – Maximum Speed.


REPOSITORY STRUCTURE

```text
IoT-Temperature-Controlled-Fan/
│
├── README.md
│
├── circuit/
│   └── esp32_fan_circuit.png
│
├── code/
│   └── esp32_temperature_fan.ino
│
├── documentation/
│   └── component_connections.md
│
└── results/
    └── test_results.md
```


HARDWARE CONNECTIONS

The ESP32 is interfaced with the DHT11 temperature sensor and L298N motor driver.

For detailed pin configurations, wiring instructions and power supply connections, refer to the component_connections.md file in the documentation folder.


CIRCUIT DIAGRAM

The circuit diagram illustrates the connections between the ESP32, DHT11 sensor, L298N motor driver and DC fan.


SOFTWARE REQUIREMENTS

- Arduino IDE
- ESP32 Board Package
- DHT Sensor Library
- Blynk IoT Library
- Wi-Fi Network


HOW TO RUN

1. Clone or download this repository.
2. Open the esp32_temperature_fan.ino file in Arduino IDE.
3. Install the required libraries.
4. Configure your Wi-Fi credentials and Blynk authentication details.
5. Select the appropriate ESP32 board and COM port.
6. Upload the program to the ESP32.
7. Open the Blynk mobile dashboard to monitor and control the fan.


RESULTS AND TESTING

The system is designed to regulate fan speed according to temperature and provide remote monitoring through Blynk IoT.

For detailed expected outputs, hardware testing procedures, observations and performance evaluation, refer to the test_results.md file in the results folder.


FUTURE IMPROVEMENTS

- Real-time fan RPM monitoring.
- Energy consumption measurement.
- Temperature data logging.
- High-temperature mobile notifications.
- Smart-home automation integration.


PROJECT INFORMATION

- Project: IoT-Based Temperature-Controlled Fan
- Controller: ESP32
- Sensor: DHT11
- Motor Driver: L298N
- IoT Platform: Blynk
- Programming Language: C/C++ (Arduino Framework)


LICENSE

This project is developed for educational and learning purposes.