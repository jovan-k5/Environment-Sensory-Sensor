# Sensory Environment Monitor

## Overview 

The Sensory Environment Monitor is an Arduino-based prototype that monitors light, temperature, and humidity and provides real-time environmental feedback through a 16x2 LCD and RGB LED.

The project explores how embedded systems could be used to make environments more sensory-aware.

> **Note:** This prototype does not detect or predict sensory overload. Sensory thresholds vary between individuals. The thresholds used in this project are prototype values for demonstration.

## How It Works

The device uses a photocell to measure light and a DHT11 sensor to measure temperature and humidity. The photocell produces an analog reading rather than a measurement in lux. The Arduino compares each reading against a prototype threshold and counts how many environmental conditions are above their thresholds.

The current prototype thresholds are:

- **Light:** Above 300 analog units
- **Temperature:** Above 28 Degrees Celsius
- **Humidity:** Above 70% relative humidity

The number of elevated conditions determines the system status:

| Conditions Above Threshold | Status | LED |
|---|---|---|
| 0 | Normal | 🟢 Green |
| 1 | Elevated | 🟡 Yellow |
| 2–3 | High | 🔴 Red |

A push button allows the user to cycle through three LCD screens showing the system status and sensor readings.

## Hardware

- Arduino Uno R3
- DHT11 temperature/humidity sensor
- Photocell
- RGB LED
- 16x2 LCD
- Push button
- Resistors
- Breadboard and jumper wires
- Potentiometer 
- USB cable

## Process

I developed the project incrementally rather than building the entire system at once.

1. Tested individual sensors and components.
2. Measured the photocell's response to different lighting conditions.
3. Tested temperature and humidity readings from the DHT11.
4. Built the LCD interface and button navigation.
5. Added RGB status feedback.
6. Integrated the sensors and programmed the status logic.
7. Tested the complete system together.

## Demo

https://github.com/user-attachments/assets/f7767861-1e39-41e8-bc69-80e421489710

The demo shows the sensor readings, LCD screen navigation, and RGB status indicator responding to environmental conditions.

## What I Learned

- How to integrate multiple sensors into one system.
- How to control multiple stages of a LED and LCD.
- How conditional logic can turn raw sensor data into meaningful system states.
- How testing individual components makes debugging a system easier.

## How It Can Be Improved

- Calibrate the LDR to provide measurements in lux.
- Transitioning the prototype from a breadboard to a custom PCB.
- Add adjustable or personalized thresholds.
- Design and 3D-print a physical enclosure.
- Add additional environmental measurements.

## Limitations

The current prototype uses inexpensive sensors and fixed prototype thresholds rather than specific ones for the user. It measures environmental conditions, not an individual's sensory response, and has not been clinically validated.

## Overall Growth

This project took me from testing individual Arduino components to building an integrated system. It strengthened my understanding of sensors, circuits, programming, debugging, and hardware-software connections, while giving me a foundation for exploring assistive technology.
