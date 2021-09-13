#include <Servo.h>
#include<SoftwareSerial.h>
#define TxD 3
#define RxD 2

Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
int trig = 9;
int echo = 10;
float duration, distance, i;

SoftwareSerial bluetoothSerial(TxD, RxD);
void setup() {
  myservo.attach(8);
  pinMode(trig, OUTPUT);
pinMode(echo, INPUT);    
 Serial.begin(9600);
bluetoothSerial.begin(9600);
}

void loop() {
  
    
    char c;  
     if (Serial.available())  
     {  
       c = Serial.read();  
        
       Serial.println(c);             // Write the character to the Serial Monitor  
        
       blueTooth.write (c);           // Write the character to Bluetooth  
     }  
 
  
  
  
  for (pos = 15; pos <= 165; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);
    i = calculateDistance();
    Serial.print(pos); 
  Serial.print(","); 
  Serial.print(i); 
  Serial.print("."); 
    
  }
  for (pos = 165; pos >= 15; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);     
    i = calculateDistance();
  Serial.print(pos);  
  Serial.print(","); 
  Serial.print(i); 
  Serial.print("."); 
  }

   
  }
  
  float calculateDistance(){
              // Clears the trigPin
digitalWrite(trig, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echo, HIGH);
// Calculating the distance
distance= duration*0.034/2;
return distance;
}
