// -------------------- Pin Definitions --------------------
#define RAIN_SENSOR A0     // Analog pin connected to potentiometer (rain sensor simulation)
#define GREEN_LED 12       // Green LED pin (indicates rain)
#define RED_LED 8          // Red LED pin (indicates heavy rain)
#define BUZZER 4           // Buzzer pin (alert for heavy rain)

// -------------------- Threshold Values --------------------
#define NO_RAIN 300        // Value below this means no rain
#define RAIN 600           // Value above this means heavy rain

void setup() {
  // Set LED and buzzer pins as OUTPUT
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Start Serial Monitor to view sensor values
  Serial.begin(9600);
}

void loop() {
  // Read analog value from potentiometer
  int rainValue = analogRead(RAIN_SENSOR);

  // Print sensor value on Serial Monitor
  Serial.println(rainValue);

  // -------------------- No Rain Condition --------------------
  // If sensor value is less than 300
  if (rainValue < NO_RAIN) {
    digitalWrite(GREEN_LED, LOW);   // Turn OFF green LED
    digitalWrite(RED_LED, LOW);     // Turn OFF red LED
    noTone(BUZZER);                 // Turn OFF buzzer
  }

  // -------------------- Rain Detected --------------------
  // If sensor value is between 300 and 600
  else if (rainValue >= NO_RAIN && rainValue <= RAIN) {
    digitalWrite(GREEN_LED, HIGH);  // Turn ON green LED
    digitalWrite(RED_LED, LOW);     // Turn OFF red LED
    noTone(BUZZER);                 // Buzzer remains OFF
  }

  // -------------------- Heavy Rain Alert --------------------
  // If sensor value is greater than 600
  else {
    digitalWrite(GREEN_LED, LOW);   // Turn OFF green LED
    digitalWrite(RED_LED, HIGH);    // Turn ON red LED
    tone(BUZZER, 2000);             // Turn ON buzzer with alert sound
  }

  // Small delay for stable reading
  delay(200);
}
