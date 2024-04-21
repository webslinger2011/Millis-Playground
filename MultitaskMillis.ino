/* Blink, Button and Servo Control by Webslinger2011
 *  This code features making use of millis to blink an led while controlling a servo 
 *  thru a potentiometer, switching leds using a for loop 
 *  and triggering a button press
 */
 
//Create an array for blinking multiple led's (Note: we can leave LEDpins[ ] empty)
byte LEDpins[6] = {7,8,9,10,11,12};

//Declare Input and Ouput pins for triggering a button
#define button 4
#define redLed 2

//Controlling a servo
#include <Servo.h>
Servo myservo;
int potpin = 0; //Analog pin on arduino
int val;  

//Bingo!!!
const unsigned long eventInterval = 1000;
unsigned long previousTime = 0;

//Blinky!
const unsigned long eventInterval2 = 3000; //executes blinking for 3 secs
unsigned long previousTime2 =0;
int LED13 = 13;
int ledState = HIGH;

//For loop!
const unsigned long eventInterval3 = 500; //executes a for loop after 0.5 secs 
unsigned long previousTime3 =0;

void setup() {
  myservo.attach(3);
  Serial.begin(9600);
  pinMode(LED13,OUTPUT);

  //Declare array pins in a for loop
  for (byte i = 0; i < 6; i++){
    pinMode(LEDpins[i],OUTPUT);
    }
  //Declare button and red led  
  pinMode(button, INPUT_PULLUP);
  pinMode(redLed, OUTPUT);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= eventInterval) {
    Serial.println("  Bingo!!! ");
    previousTime = currentTime;
    }
  if (currentTime - previousTime2 >= eventInterval2){
    if (ledState == LOW) {
      ledState = HIGH;
      Serial.println("  LED ON"); }
    else {ledState = HIGH;
      Serial.println("  LED OFF");
      ledState = LOW;}
    digitalWrite(LED13,ledState);
    previousTime2 = currentTime;
    }
  if (currentTime - previousTime3 >= eventInterval3){
    //Detect a button press every 0.5 second
    byte buttonState = digitalRead(button);
    Serial.print("  Button = ");
    Serial.println(buttonState);
    if (buttonState == LOW){
      digitalWrite(redLed, HIGH);
      }
    else {
      digitalWrite(redLed, LOW);
      }
     previousTime3 = currentTime;
    }
    //Increment LEDpins array
    for (byte j = 0; j<6; j++){
      digitalWrite(LEDpins[j], HIGH);
      delay(100);
      }
    //Declare k as int instead of using bytes since we'll be getting a negative value  
    for (int k = 6; k>=0; k--){
      digitalWrite(LEDpins[k], LOW);
      delay(50);
      }
    //Control the servo
    val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
    val = map(val, 0, 1023, 0, 180);      // scale it to use it with the servo (value between 0 and 180)
    myservo.write(val);                   // sets the servo position according to the scaled value
    Serial.print("  Degrees =  ");
    Serial.println(val);
    delay(15); 
    Serial.println("   ");  
    Serial.println("   ");     
}
