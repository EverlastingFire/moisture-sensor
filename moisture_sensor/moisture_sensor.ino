/* moisture_sensor
 * 
 * This program checks the analog input (pin A0) coming from a moisture sensor
 * and switch on a LED placed on the digital pin 13 if the read data is below a
 * certain threshold. The default value of the threshold is 800, but it can be
 * changed in the source code if you really need to.
 *
 */

static int SENSOR_PIN = A0;           // sensor pin number
static int LED_PIN = 13;              // LED pin number
static int threshold = 800;           // threshold for activating the LED

static long SPEED=9600;               // speed of serial data's transmission
static long interval=300000;          // interval of 5 minutes in milliseconds

static char message[]="Feed me!";     // message to print on the monitor
/*static char message2[]="You can change the threshold. The current value is: ";*/

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
  
  while (reading<=threshold){         // until the recorded value is below 800
    digitalWrite(LED_PIN, HIGH);      // turn on the LED
    Serial.println(message);          // print the message to the monitor
    delay(interval);                  // wait for 5 minutes
    digitalWrite(LED_PIN, LOW);       // turn off the LED
    reading = analogRead(SENSOR_PIN); // get the sensor reading another time
  }
  
  /* TODO: allow the user changing the threshold value*/
  
}
