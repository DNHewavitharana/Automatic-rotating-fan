#include <Servo.h>
Servo motor_control;
bool speed_turn = true;


int motor_control_pin= 9;
int led= 4;
int pir_left= 7;
int pir_middle= 8;
int pir_right= 8;

int pir_person_detector=6;

int angle_keeper[2];

bool state1= true;
bool state2= true;
int angle_start;
int angle_end;
int angle_mid;
int angle;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(pir_left,INPUT);
  pinMode(pir_middle,INPUT);
  pinMode(pir_right,INPUT);
  pinMode(pir_person_detector,INPUT);
  motor_control.attach(motor_control_pin);
  Serial.begin(9600);
}
void loop() {
  automatic_normal_mode();
}


