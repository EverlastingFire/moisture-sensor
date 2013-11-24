/* moisture_sensor
 * 
 * This program checks the analog input (pin A0) coming from a moisture sensor
 * and switch on a LED placed on the digital pin 13 if the read data is below a
 * certain threshold. The default value of the threshold is 800, but it can be
 * changed in the source code if you really need to.
 */

/*Hello world*/

static int SENSOR_PIN = A0;      // sensor pin number
static int LED_PIN = 13;         // LED pin number
static int threshold = 800;      // threshold for activating the LED

int reading;                     // analog sensor reading
int led_state;                   // current led state

static char message[]="Feed me!";         //message to print on the monitor
static char message2[]="You can change the threshold. The current value is: ";

static long interval=300000; //interval of 5 minutes in milliseconds

void setup()
{
  // set the digital pin as output
    pinMode(LED_PIN, OUTPUT);
    
    Serial.begin(9600); //Start sending and receiving serial data
}

void loop()
{
  // get the sensor reading and the current LED state
  reading = analogRead(SENSOR_PIN);
  led_state = digitalRead(LED_PIN);
  while (reading<=threshold){ //until the recorder value is below 800
    digitalWrite(LED_PIN, HIGH); //Turn on the LED
    Serial.println(message); //Print the message to the monitor
    delay(interval); //Wait for 5 minutes
    digitalWrite(LED_PIN, LOW); //Turn off the LED
    reading = analogRead(SENSOR_PIN); //Get the sensor reading another time
  }
  
  /* TODO: allow the user changing the threshold value*/
}
