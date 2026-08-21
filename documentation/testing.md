# Testing

## Overview

The prototype was tested on a breadboard to verify that the sensors, LCD, and programmed threshold logic worked together correctly.

Testing focused on:

- Light sensor response
- Temperature and humidity readings
- LCD output
- Threshold-based responses
- Full system cohesiveness 

## Light Sensor Testing

The photocell was tested under different lighting conditions to observe changes in its sensor readings.

Example readings recorded during testing included:

- 188
- 186
- 168
- 45–48

The readings changed when I places my finger over it or when I directly shined a flashlight, confirming that the photocell responded to changes in light.

## Temperature and Humidity Testing

The DHT11 sensor was tested to verify that temperature and humidity readings were being received correctly by being compared to a thermostat at my house. 

Example reading:

- Temperature: 29.0°C
- Humidity: 65.0%
(These mostly matched the thermostat, however slight impressions were present due to Celsius and Fahrenheit variability.)  
The sensor did successfully provided temperature and humidity readings to the Arduino.

## LCD Testing

The LCD1602 was tested to verify that the device could display sensor information and system status.

Multiple LCD states were photographed during testing and are included in the `photos` folder.

## Threshold Testing

The programmed thresholds were tested by changing the environmental conditions around the sensors.

When a reading crossed a programmed threshold, the system responded according to the programmed logic.

These thresholds are predefined test values and are not based on real data collected from an individual.

## Full System Testing

The complete prototype was tested with the Arduino, photocell, DHT11, LCD1602, and other components connected on the breadboard.

The system successfully:

- Read environmental sensor values
- Displayed information on the LCD
- Compared readings against predefined thresholds
- Produced the programmed response when thresholds were reached

## Documentation

Photos and videos were taken during development and testing to document the prototype.

The `photos` folder contains:

- Different LCD display states
- A photo of the complete breadboard prototype

A demonstration video is included in the main README.
