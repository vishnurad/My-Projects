/* Project to measure flicker fusion threshold using
 teensy 3.2 microcontroller.
The requirements of the project are:
 A flashing LED should serve as the visual stimulus.
 A potentiometer should be used to adjust the LED blink
 frequency.
 A button should be connected which when pressed a hardware
 interrupt is to be triggered and the currently set blink
 frequency should be displayed.
 No delay() function to be used and
 Debouncing of the button to be done*/
#include <Arduino.h>
#define PotPin  A8 // input pin for the potentiometer is A8
#define ledPin  8 //  green LED is pin 8 on teensy
#define buttonPin 12 // the push button is on pin 12 on teensy
float Timeperiod = 0; // Timeperiod is read as input from the potentiometer.

volatile float frequency; //Blink frequency of green LED
bool ledState = LOW; // ledState used to set the LED
unsigned long previousMillis = 0; // will store last time LED was updated
unsigned long lastDebounceTime = 0; // output pin previous toggle recorded
unsigned long debounceDelay = 50; // debounce delay time
//Its given to filter out unwanted switch bounces.
float xtime; // to store the value of 'Timeperiod' 
//which is mapped to a lower range

/* Main Setup Code*/
void ISR();
void setup() 
{
  pinMode(ledPin, OUTPUT); // this is set as the output pin(8)
  pinMode( buttonPin, INPUT); // this is set as the input pin(12)
  attachInterrupt(digitalPinToInterrupt(12), ISR , FALLING);
  //an interrupt ISR is created
}

/*Loop code*/

void loop()
{
 Timeperiod = analogRead(PotPin); // read the value from the
 // potentiometer
 unsigned long currentMillis = millis(); // current value stored
 // to currentmillis
 xtime = map(Timeperiod,0,1023,0,200); // value mapped
 // to a lower range
if (currentMillis - previousMillis >xtime)
{
 previousMillis = currentMillis; //previous blink state is recorded.
 if (ledState == LOW)
 ledState = HIGH;
 else
 ledState = LOW;
 digitalWrite(ledPin, ledState); // set the LED with the ledState
 frequency = (500/xtime); // store the value of led blink freqency
 //frequency mutiplied to 500 times
}
}


/* Created Interrupt Service Routine (ISR) */

void ISR()
{
 bool flag;
 lastDebounceTime = micros();
 if ((micros() - lastDebounceTime) > debounceDelay) //debounce
{
 flag = 1; //to start debounce check
}
if (flag ==1 ) // debounce checking
{
 Serial.print("Current Flicker Freqency in Hz = ");
 Serial.println(frequency); // print current frequency of green LED
}
}
