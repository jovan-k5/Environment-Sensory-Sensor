#include <LiquidCrystal.h>
#include <dht_nonblocking.h>

//Pins
const int lightSensorPin = A0;
const int buttonPin = 4;

const int redPin = 6;
const int greenPin = 5;
const int bluePin = 3;

#define DHT_SENSOR_TYPE DHT_TYPE_11
const int DHT_SENSOR_PIN = 2;

DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//Screen
int screen = 0;

//Sensor values
float temperature = 0;
float humidity = 0;
int lightValue = 0;

//Thresholds
//These are prototype thresholds
//Not always correct due to individual preferences

const float TEMP_HIGH = 25.6;      
const float HUMIDITY_HIGH = 70.0;  
const int LIGHT_HIGH = 300;        

//status
// 0 = NORMAL
// 1 = ELEVATED
// 2 = HIGH

int status = 0;


void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  lcd.begin(16, 2);

  Serial.begin(9600);

  setStatusColor(0);

  lcd.print("Starting...");
  delay(1000);

  lcd.clear();
}


void loop() {
  lightValue = analogRead(lightSensorPin);

  if (dht_sensor.measure(&temperature, &humidity)) {
    // Print sensor values
    Serial.print("Light: ");
    Serial.print(lightValue);

    Serial.print(" | Temperature: ");
    Serial.print(temperature);

    Serial.print(" C | Humidity: ");
    Serial.print(humidity);

    Serial.println(" %");


  //Determine status
    int concerningConditions = 0;

    // Temperature condition
    if (temperature > TEMP_HIGH) {
      concerningConditions++;
    }

    // Humidity condition
    if (humidity > HUMIDITY_HIGH) {
      concerningConditions++;
    }

    // Light condition
    if (lightValue > LIGHT_HIGH) {
      concerningConditions++;
    }


    //Convert conditions to states
    if (concerningConditions == 0) {
      status = 0;
    }
     else if (concerningConditions == 1) {
      status = 1;
    }
    else {
      status = 2;
    }

    // Change RGB LED
    setStatusColor(status);
  }


  //Button
  if (digitalRead(buttonPin) == LOW) {

    screen++;

    if (screen > 2) {
      screen = 0;
    }

    delay(300);
  }


  //LCD Output
  showScreen();

  delay(100);
}


// LCD screen function

void showScreen() {

  lcd.clear();
  // Screen 0 — status

  if (screen == 0) {

    lcd.setCursor(0, 0);
    lcd.print("STATUS:");

    if (status == 0) {
      lcd.print(" NORMAL");
    }

    else if (status == 1) {
      lcd.print(" ELEVATED");
    }

    else {
      lcd.print(" HIGH");
    }


    lcd.setCursor(0, 1);

    if (status == 0) {
      lcd.print("Conditions OK");
    }

    else if (status == 1) {
      lcd.print("Check environment");
    }

    else {
      lcd.print("High conditions");
    }
  }

  // Screen 1 = Light + Temperature
  else if (screen == 1) {

    lcd.setCursor(0, 0);
    lcd.print("Light: ");
    lcd.print(lightValue);

    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperature, 1);
    lcd.print("C");
  }

  // Screen 2 = Humidity
  else if (screen == 2) {

    lcd.setCursor(0, 0);
    lcd.print("Humidity: ");
    lcd.print(humidity, 1);
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("Press Button");
  }
}

// RGB Led function

void setStatusColor(int status) {
  // Green — normal
  if (status == 0) {

    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
  }

  // Yellow — elevated
  else if (status == 1) {

    analogWrite(redPin, 255);
    analogWrite(greenPin, 220);
    analogWrite(bluePin, 0);
  }

  // Red — high
  else {

    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }
}
