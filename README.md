# Modular Automated Firefighting Robot

## Overview

This is a **DEMO** for our term project in our electronics lab course 2nd Year 2nd Semester of BUP. It is an autonomous robot designed to detect and extinguish fires in hazardous environments. Equipped with sensors for fire and gas detection, a servo-controlled water pump, and a mobile chassis, the robot can navigate to a fire source, extinguish it, and alert users via SMS upon detecting harmful gases. This project aims to provide a scalable and adaptable solution for automated fire suppression in industrial or domestic settings.

## Features

- **Fire Detection and Extinguishing**: Utilizes a flame sensor to detect fire and a servo-controlled pump to extinguish it with precision.
- **Gas Detection and Alerts**: Monitors gas levels using a sensor and sends SMS alerts via a SIM800L module when dangerous levels are detected.
- **Autonomous Movement**: Employs a four-motor chassis for reliable navigation towards a detected fire.
- **Modular Design**: Allows for easy upgrades and modifications to sensors, actuators, and communication modules.
- **Remote Communication**: Integrates with a SIM800L module for SMS notifications and potential call alerts.

## Hardware Requirements

- **Microcontroller**: Arduino-compatible board (e.g., Arduino Uno).
- **Motor Shield**: Adafruit Motor Shield (AFMotor library compatible).
- **Motors**: 4 DC motors for the chassis (controlled via the motor shield).
- **Sensors**:
  - Flame sensor (connected to digital pin 6).
  - Gas sensor (connected to analog pin A0).
- **Servo Motor**: For controlling the water pump nozzle (connected to pin 10).
- **Water Pump**: Controlled via a relay or transistor (connected to pin 7).
- **SIM800L Module**: For SMS and call functionality (connected to pins 2 and 3 for RX/TX).
- **Power Supply**: Battery pack to power the motors and microcontroller.
- **Chassis**: A four-wheeled robot chassis with mounting points for components.

## Setup Instructions

1. **Assemble the Hardware**:
   - Mount the DC motors to the chassis and connect them to the Adafruit Motor Shield.
   - Attach the flame sensor, gas sensor, servo motor, and water pump to the respective pins on the Arduino as defined in the code.
   - Connect the SIM800L module to the Arduino using the specified RX/TX pins.
   - Secure the battery pack and ensure proper power distribution to the Arduino and motor shield.

2. **Install Required Libraries**:
   - Download and install the following Arduino libraries via the Arduino IDE:
     - `Servo.h` (included with Arduino IDE).
     - `SoftwareSerial.h` (included with Arduino IDE).
     - `AFMotor.h` (Adafruit Motor Shield library, available via the Arduino Library Manager).

3. **Upload the Code**:
   - Open the `firefightingRobot.ino` file in the Arduino IDE.
   - Update the `PHONE` constant in the code with the recipient's phone number for SMS alerts. For example:
     ```cpp
     const String PHONE = "+XXXXXXXXXXXXXX";
     ```
   - Upload the code to the Arduino board.

4. **Test the System**:
   - Power on the robot and ensure the SIM800L module is connected to a network.
   - Test the flame sensor by introducing a small flame (safely) to verify movement and pump activation.
   - Test the gas sensor by exposing it to a safe gas source to confirm SMS alerts.

## Usage

1. **Power On**: Connect the battery pack to power the robot.
2. **Operation**:
   - The robot continuously monitors for fire using the flame sensor.
   - Upon detecting a fire, it moves forward, activates the water pump, and sweeps the servo to extinguish the fire.
   - If the gas sensor detects levels above the threshold (70), it sends an SMS alert to the specified phone number.
3. **Monitoring**: Check the Serial Monitor in the Arduino IDE (at 9600 baud) for debugging messages, such as gas detection or SMS sending status. Example output:
     ```
     Gas is Detected.
     sending sms....
     ```
