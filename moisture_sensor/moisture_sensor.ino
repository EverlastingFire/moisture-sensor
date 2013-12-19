/* moisture_sensor
 * 
 * This program checks the analog input (pin A0) coming from a moisture sensor
 * and switch on a LED placed on the digital pin 13 if the read data is below a
 * certain threshold.
 * 
 * Developed by EverlastingFire, Orphan27 and PKangu
 *
 */

static int SENSOR_PIN = A0;           // sensor pin number
static int LED_PIN = 13;              // LED pin number
static int THRESHOLD = 800;           // threshold for activating the LED

static long SPEED=9600;               // speed of serial data's transmission
static long INTERVAL=500;             // interval in milliseconds

static char MESSAGE[]="Feed me!";     // message to print on the monitor

int reading;                          // analog sensor reading
int led_state;                        // current led state

void setup()
{
    pinMode(LED_PIN, OUTPUT);         // set the digital pin as output
    Serial.begin(SPEED);              // start sending and receiving serial data
}

void loop()
{
  
  reading = analogRead(SENSOR_PIN);   // get the sensor reading 
  led_state = digitalRead(LED_PIN);   // get the current LED state
  
  if (reading<=THRESHOLD){            // check if the read value is below the threshold
    digitalWrite(LED_PIN, HIGH);      // turn on the LED
    Serial.println(MESSAGE);          // print the message to the monitor
    delay(INTERVAL);                  // wait for blink
    digitalWrite(LED_PIN, LOW);       // turn off the LED
    delay(INTERVAL);                  // wait for recheck
  }
  
}
