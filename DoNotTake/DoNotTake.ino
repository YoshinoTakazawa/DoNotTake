#include <Servo.h>
#include<stdio.h>
#define SERVO_PWM_PIN10 10
#define SERVO_PWM_PIN13 13
const int DISTANCE_SENSOR = A0;
const int LIGHT_SENSOR = A5;

Servo myservo0;
Servo myservo1;
int pos = 0;
int val = 0;
int Width_Min = 700;    //最小パルス幅（μs）
int Width_Max = 2300;   //最大パルス幅（μs）

void setup() {
  Serial.begin(9600);
  myservo0.attach(SERVO_PWM_PIN10, Width_Min, Width_Max);
  myservo1.attach(SERVO_PWM_PIN13, Width_Min, Width_Max);
}

void loop() {
  int distance_value = analogRead( DISTANCE_SENSOR );
  int light_value = analogRead( LIGHT_SENSOR );


  distance_value = map(distance_value, 0, 1023, 0, 180);

  
  if (light_value <= 700) { //チョコある状態

    if (distance_value > 100) {
      distance_value = 30;
      myservo0.write(distance_value);
      myservo1.write(180 - distance_value);
    } else {
      distance_value = 0;
      myservo0.write(distance_value);
      myservo1.write(180 - distance_value);
    }

   }else{ //チョコ取られた！！
    
    for(int i=0; i<=30; i++){
    val = i;
    myservo0.write(val);
    myservo1.write(180 - val);
    delay(10);
    }
    for(int i=30; i>=0; i--){
    val = i;
    myservo0.write(val);
    myservo1.write(180 - val);
    delay(10);
    }
    
 }

    Serial.print("after=");
    Serial.println(distance_value);
    Serial.print("light=");
    Serial.println(light_value);
    //myservo0.write(distance_value);
    //myservo1.write(180 - distance_value);
    delay(10);

  }
