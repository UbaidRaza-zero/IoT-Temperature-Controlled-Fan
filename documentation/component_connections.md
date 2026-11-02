COMPONENT CONNECTIONS – IoT-BASED TEMPERATURE-CONTROLLED FAN

1. PROJECT OVERVIEW

This project uses an ESP32 microcontroller to develop an IoT-based temperature-controlled fan system.

The DHT11 temperature sensor measures the surrounding temperature and sends the readings to the ESP32. Based on the measured temperature, the ESP32 controls the speed of a DC fan through the L298N motor driver.

The ESP32 also connects to a Wi-Fi network to enable remote monitoring and fan control through the Blynk IoT platform.


2. COMPONENTS REQUIRED

1. ESP32 Development Board (Quantity: 1)
   Purpose: Main controller with Wi-Fi.

2. DHT11 Temperature Sensor (Quantity: 1)
   Purpose: Measures temperature and humidity.

3. L298N Motor Driver (Quantity: 1)
   Purpose: Controls DC fan speed and direction.

4. DC Motor / DC Fan (Quantity: 1)
   Purpose: Provides airflow.

5. External DC Power Supply (Quantity: 1)
   Purpose: Supplies power to the motor.

6. Breadboard (Quantity: 1)
   Purpose: Circuit prototyping.

7. Jumper Wires (As required)
   Purpose: Electrical connections.


3. ESP32 PIN CONFIGURATION

The following GPIO pins are used for interfacing the sensor and motor driver.

- GPIO 4:
  Connected to DHT11 DATA.
  Function: Temperature and humidity data.

- GPIO 25:
  Connected to L298N ENA.
  Function: PWM fan speed control.

- GPIO 26:
  Connected to L298N IN1.
  Function: Motor direction control.

- GPIO 27:
  Connected to L298N IN2.
  Function: Motor direction control.

- 3V3:
  Connected to DHT11 VCC.
  Function: Sensor power supply.

- GND:
  Connected to DHT11 GND.
  Function: Ground connection.

- GND:
  Connected to L298N GND.
  Function: Common ground.


4. DHT11 TEMPERATURE SENSOR CONNECTIONS

The DHT11 sensor measures the surrounding temperature and humidity.

Pin Connections:

- VCC: Connected to ESP32 3V3.
- DATA: Connected to ESP32 GPIO 4.
- GND: Connected to ESP32 GND.

Working:

1. The DHT11 measures the surrounding temperature.
2. It sends digital data to ESP32 through GPIO 4.
3. The ESP32 processes the temperature reading.
4. The processed temperature is used to determine the required fan speed.

Note: If using a bare DHT11 sensor instead of a sensor module, an external pull-up resistor may be required on the DATA line.


5. L298N MOTOR DRIVER CONNECTIONS

The L298N motor driver acts as an interface between the ESP32 and the DC fan.

Pin Connections:

- ENA:
  Connected to ESP32 GPIO 25.
  Function: PWM speed control.

- IN1:
  Connected to ESP32 GPIO 26.
  Function: Motor direction control.

- IN2:
  Connected to ESP32 GPIO 27.
  Function: Motor direction control.

- OUT1:
  Connected to DC Fan Terminal 1.
  Function: Motor output.

- OUT2:
  Connected to DC Fan Terminal 2.
  Function: Motor output.

- GND:
  Connected to Common GND.
  Function: Ground connection.

- Motor Supply (+):
  Connected to External DC Supply (+).
  Function: Motor power.

- 5V Logic:
  Connected as required by module configuration.
  Function: Logic power.

Important Motor Driver Connections:

1. Remove the ENA jumper to enable PWM speed control through ESP32 GPIO 25.

2. Connect both DC fan terminals to OUT1 and OUT2.

3. Connect the negative terminal of the motor power supply to L298N GND.

4. Connect ESP32 GND to L298N GND.

5. Supply the motor with the voltage required by its specifications.

Logic Power Configuration:

L298N modules may have different onboard regulator arrangements.

- If the module's 5V-enable jumper is installed, its onboard regulator may provide the logic supply. Follow the module's documentation.

- If the jumper is removed, provide a suitable regulated 5V logic supply to the 5V terminal, as specified by the module manufacturer.

- Do not connect an external 5V supply to a regulator output.


6. DC FAN CONNECTIONS

The DC fan is connected to the output terminals of the L298N motor driver.

Pin Connections:

- DC Fan Terminal 1: Connected to L298N OUT1.
- DC Fan Terminal 2: Connected to L298N OUT2.

The L298N receives control signals from the ESP32 and regulates the motor's average voltage using PWM.


7. POWER SUPPLY CONNECTIONS

The project uses separate power arrangements for the ESP32 and DC motor.

Power Connections:

- ESP32: USB or suitable regulated power supply.
- DHT11: ESP32 3.3V.
- L298N Logic: According to module configuration.
- DC Fan: External motor power supply.

Common Ground Connection:

The following grounds must be connected together:

- ESP32 GND.
- L298N GND.
- External motor power supply negative terminal.
- DHT11 GND.

A common ground provides a shared voltage reference for the control signals.


8. TEMPERATURE-BASED FAN CONTROL

The system operates according to the following temperature conditions.

- Below 25°C: Fan OFF.
- At 25°C: Fan starts at low speed.
- 25°C – 40°C: Fan speed gradually increases.
- 40°C and above: Fan operates at maximum commanded speed.

The ESP32 uses PWM (Pulse Width Modulation) to regulate the fan speed.


9. IoT CONNECTIVITY

The ESP32 connects to a Wi-Fi network and communicates with the Blynk IoT platform.

The mobile dashboard provides:

- Live temperature monitoring.
- Humidity monitoring.
- Automatic and manual fan control.
- Remote fan speed adjustment.
- Current commanded fan speed display.


10. SAFETY AND DESIGN CONSIDERATIONS

- Verify all component connections before applying power.
- Never connect 5V directly to an ESP32 GPIO pin.
- Use an appropriate motor power supply.
- Ensure common ground between the ESP32 and motor driver.
- Check the motor driver's current and voltage ratings.
- Do not connect a DC motor directly to ESP32 GPIO pins.
- Protect the circuit against accidental short circuits.
- This design is intended for a low-voltage DC fan, not a 230V AC ceiling fan.


11. CONCLUSION

The ESP32 acts as the main controller of the IoT-based temperature-controlled fan system. The DHT11 sensor provides temperature readings, while the L298N motor driver controls the DC fan speed.

By integrating Wi-Fi and the Blynk IoT platform, the system supports remote monitoring and manual fan control in addition to automatic temperature-based operation.