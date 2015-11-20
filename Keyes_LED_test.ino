/* This sketch is an example of using
 *  simple LED RGB Module Keyes K845041 with eight RGB 5050 LEDS
 *  Module is connected to Arduino UNO
 *  
 *  Working video is at https://youtu.be/8OYcpKoXm4c
 *  
 *  It has 8 RGB Leds and three pins to set
 *  color of all of the Leds
 *  
 *  Setting color and Led turn on is inverted.
 *  It means that to turn the Led on you must set LOW level on it.
 *  Setting colors is also inverted. Highest brightness is 0, darknest is 255
 * 
 *  RGB pins are connected to PWM pins, for UNO that are 3, 5 and 6
 *  
 *  Leds are connected to digital pins 
 * 
 */

#define redPin  6
#define bluePin 5
#define grnPin  3

int const leds[8]={4,7,8,9,10,11,12,13}; // Pins, Leds are connected to

void setup() {
  // Setup color pins
  pinMode(redPin, OUTPUT);  
  pinMode(bluePin, OUTPUT);
  pinMode(grnPin, OUTPUT);

  // Setup green color yet for testing
  analogWrite(redPin, 255);
  analogWrite(bluePin, 255);
  analogWrite(grnPin, 0);

  // Setup led pins
  for(int i=0; i<8; i++){
     pinMode(leds[i],OUTPUT); // Init and light up
     delay(100);
  }

  delay (250);

  // Test Blue
  analogWrite(grnPin, 255);
  analogWrite(bluePin, 0);
  delay(750);

  // Test Red
  analogWrite(bluePin, 255);
  analogWrite(redPin, 0);
  delay(750);

  resetSlow();
  
}

void loop() {
  //Red
  analogWrite(redPin, 0);
  analogWrite(bluePin, 255);
  analogWrite(grnPin, 255);
  simpleMove();
  missFill();
  simpleFill();
  
  //Blue
  analogWrite(redPin, 255);
  analogWrite(bluePin, 0);
  analogWrite(grnPin, 255);
  simpleMove();
  missFill();
  simpleFill();

  //Green
  analogWrite(redPin, 255);
  analogWrite(bluePin, 255);
  analogWrite(grnPin, 0);
  simpleMove();
  missFill();
  simpleFill();

  //Yellow
  analogWrite(redPin, 0);
  analogWrite(bluePin, 255);
  analogWrite(grnPin, 0);
  simpleMove();
  missFill();
  simpleFill();

}

// One by one turn off
void resetSlow(){
  for(int i=0; i<8; i++){       
     digitalWrite(leds[i], HIGH); // Turn off
     delay(100);
  }
}

// Moving led
void simpleMove(){
  for(int i=0; i<8; i++){   
     digitalWrite(leds[i], LOW); // Turn on
     delay(100);
     digitalWrite(leds[i], HIGH); // Turn off
  }
}

// Turn all leds one by one
void simpleFill(){
  for(int i=0; i<8; i++){   
     digitalWrite(leds[i], LOW); // Turn on
     delay(100);
  }

  resetSlow();
}

// Turn on every second led
void missFill(){
  for(int i=0; i<8; i++){
    if (i % 2 == 0){ 
     digitalWrite(leds[i], LOW); // Turn on
     delay(100);
    }
  }

  resetSlow();
}
