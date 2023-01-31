#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

#define TRIGGER_PIN1 4
#define ECHO_PIN1 5
#define TRIGGER_PIN2 6
#define ECHO_PIN2 7
#define TRIGGER_PIN3 8
#define ECHO_PIN3 9
#define TRIGGER_PIN4 10
#define ECHO_PIN4 11

#define BUTTON_PIN1 12
#define BUTTON_PIN2 13

#define MP3_RX 2
#define MP3_TX 3

SoftwareSerial mySerial(MP3_RX, MP3_TX);
DFRobotDFPlayerMini myMP3;       

long duration1, distance1, duration2, distance2, duration3, distance3, duration4, distance4;

int buttonState1 = 0;
int buttonState2 = 0;

void setup() {
  mySerial.begin(9600);
  myMP3.begin(mySerial);
  myMP3.volume(30);

  pinMode(TRIGGER_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIGGER_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
  pinMode(TRIGGER_PIN3, OUTPUT);
  pinMode(ECHO_PIN3, INPUT);
  pinMode(TRIGGER_PIN4, OUTPUT);
  pinMode(ECHO_PIN4, INPUT);
  
  pinMode(BUTTON_PIN1, INPUT);
  pinMode(BUTTON_PIN2, INPUT);
}

void loop() {
  digitalWrite(TRIGGER_PIN1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN1, LOW);
  duration1 = pulseIn(ECHO_PIN1, HIGH);
  distance1 = (duration1 / 2) / 29.1;

  digitalWrite(TRIGGER_PIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN2, LOW);
  duration2 = pulseIn(ECHO_PIN2, HIGH);
  distance2 = (duration2 / 2) / 29.1;

  digitalWrite(TRIGGER_PIN3, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN3, LOW);
  duration3 = pulseIn(ECHO_PIN3, HIGH);
  distance3 = (duration3 / 2) / 29.1;

  digitalWrite(TRIGGER_PIN4, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN4, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN4, LOW);
  duration4 = pulseIn(ECHO_PIN4, HIGH);
  distance4 = (duration4 / 2) / 29.1;
  
  buttonState1 = digitalRead(BUTTON_PIN1);
  buttonState2 = digitalRead(BUTTON_PIN2);

  if (distance1 < 20) {
        
    myMP3.play(1);
        
  } else if (distance2 < 20) {
        
    myMP3.play(2);
        
  } else if (distance3 < 20) {
        
    myMP3.play(3);
        
  } else if (distance4 < 20) {
        
    myMP3.play(4);
  }
  
  if (buttonState1 == HIGH) {
        
    myMP3.play(5);// choose
        
  }
  else if (buttonState2 == HIGH) {
        
    myMP3.play(6);//  choose
  }
  
  delay(100);
}
