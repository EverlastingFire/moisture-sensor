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


static long SPEED=9600;               // speed of serial data's transmission
static long interval_1m=60000;        // interval of 1 minute in milliseconds
static long interval_30m=1800000;     // interval of 30 minutes in milliseconds

static char message[]="Feed me!";     // messages to print on the monitor
static char message2[]="Do you want to change the threshold value? 1=Yes, 0=No";
static char message3[]="Enter the new threshold value: ";

int reading;                          // analog sensor reading
int led_state;                        // current led state
int threshold = 800;                  // threshold for activating the LED
int answer=0;

void setup()
{
    pinMode(LED_PIN, OUTPUT);         // set the digital pin as output
    Serial.begin(SPEED);              // start sending and receiving serial data
}

void ledSOS(){
  int i = 0;
  for (i=0; i<3; i++){                // letter S, made by 3 dots
    digitalWrite(LED_PIN, HIGH);      // turns on the LED
    delay(250);                       // wait
    digitalWrite(LED_PIN, LOW);       // turns off the LED
    delay(250);
  }
  delay(1500);
  i = 0;
  for (i=0; i<3; i++){                // letter O, made by 3 dashes
    digitalWrite(LED_PIN, HIGH); 
    delay(900); 
    digitalWrite(LED_PIN, LOW); 
    delay(250);
  }
  delay(1500);
  i = 0;
  for (i=0; i<3; i++){                // letter S, made by 3 dots
    digitalWrite(LED_PIN, HIGH); 
    delay(250); 
    digitalWrite(LED_PIN, LOW); 
    delay(250);
  }
}

void loop()
{
  reading = analogRead(SENSOR_PIN);   // get the sensor reading 
  led_state = digitalRead(LED_PIN);   // get the current LED state
  
  if (reading<=threshold){            // if the recorded value is below 800
    void ledSos();                    // launch the SOS light message
    Serial.println(message);          // print the message to the monitor
    void ledSos();                    // re-launch the SOS light message
    delay(interval_1m);               // wait 1 minute
  }
  else{                               // if the plant soil is moist wait a bit
    digitalWrite(LED_PIN, LOW);       // turn off the LED
    delay(interval_30m);              // wait 30 minutes
    Serial.println(message2);         // ask if user wants another threshold
    scanf("%i", &answer);             // enter the answer
    if (answer==1){                   // if yes
      Serial.println(message3);       // ask the new value
      scanf("%i", &threshold);        // enter new value
    }
  }  
}
