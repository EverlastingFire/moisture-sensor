/* moisture_sensor
 * 
 * This program checks the analog input (pin A0) coming from a moisture sensor
 * and switch on a LED placed on the digital pin 13 if the read data is below a
 * certain threshold. The default value of the threshold is 800, but it can be
 * changed in the source code if you really need to.
 */

static int SENSOR_PIN = A0;      // sensor pin number
static int LED_PIN = 13;         // LED pin number
static int threshold = 800;      // threshold for activating the LED

int reading;                     // analog sensor reading
int led_state;                   // current led state

void setup()
{
  // set the digital pin as output
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // get the sensor reading and the current LED state
  reading = analogRead(SENSOR_PIN);
  led_state = digitalRead(LED_PIN);
  
  /* TODO */
}
