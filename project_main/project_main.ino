#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <Servo.h>
Servo motor_control;

#define firebaseUrl "smart-fan-remote.firebaseio.com"
#define authCode "Z6PssyyfAPtYzTFPY0795rnz50FU7oMCeA4AtZis"

                 
#define wifiName "DNH"
#define wifiPass "dnh123456"

bool speed_turn = true;


int motor_control_pin= D3;
int pir_left= D0;
int pir_middle= D1;
int pir_right= D2;

int fan_speed_control_pin= A0;

int pir_person_detector=D4;

int angle_keeper[2];

//mode activator
bool state1= true;
bool state2= true;
bool state3= true;
bool state4= true;
bool state5= true;

//person_detector_mode
int angle_start;
int angle_end;
int angle_mid;
int angle;

int speed_motor=250;

//fixed_range_mode angles
int fixed_angle_start= 30;  
int fixed_angle_end= 150;

//speed_changing_mode_speeds
int low_speed=150;
int medium_speed=200;
int high_speed=255;

int left_fan_speed;
int middle_fan_speed;
int right_fan_speed;


//angle_fixed_mode
int fixed_angle;
int fixed_speed_motor;


void setup() {
  Serial.begin(9600);
  setupWifi();
  setupFirebase();
  pinMode(fan_speed_control_pin, OUTPUT);
  pinMode(pir_left,INPUT);
  pinMode(pir_middle,INPUT);
  pinMode(pir_right,INPUT);
  pinMode(pir_person_detector,INPUT);
  motor_control.attach(motor_control_pin);
}

void setupFirebase(){
  Firebase.begin(firebaseUrl,authCode);
  }
  
void setupWifi(){
  WiFi.begin(wifiName,wifiPass);
  Serial.println("Hey I'm Connecting");
  
  while(WiFi.status()!=WL_CONNECTED){
    Serial.println("not connected");
    delay(500);
    }
  Serial.println();
  Serial.println("I'm connecting and IP address: ");
  Serial.println(WiFi.localIP());
}
bool getfanState(){
  String fan_state_path = "fanState";
  FirebaseObject fan_state_object = Firebase.get(fan_state_path);
  bool fan_state = fan_state_object.getBool();
  return fan_state;  
  }
 

void loop(){
  String path_automatic = "automatic";
  FirebaseObject automaticObject = Firebase.get(path_automatic);
  String path_manual = "manual";
  FirebaseObject manualObject = Firebase.get(path_manual);
  
  if (getfanState()){
    if (automaticObject.getBool("state")){
       speed_setter(automaticObject.getString("leftSide"),"left");
       speed_setter(automaticObject.getString("middle"),"middle");
       speed_setter(automaticObject.getString("rightSide"),"right");
       automatic_normal_mode(motor_control);
      }
      else{
        if (manualObject.getString("mode")=="fixedAngle"){
          fixed_angle=manualObject.getInt("angle");
          //Serial.println(fixed_angle);
          fixed_speed_motor=speed_decider(manualObject.getString("speed"));
          //Serial.println(fixed_speed_motor);
          angle_fixed_mode(fixed_angle);
        }else if(manualObject.getString("mode")=="fixedRange"){
           fixed_speed_motor=speed_decider(manualObject.getString("speed"));
           //Serial.println(fixed_speed_motor);
           fixed_range_rotate(fixed_angle_start, fixed_angle_end);
        }else if (manualObject.getString("mode")=="speedChanging"){
           speed_setter(manualObject.getString("leftSide"),"left");
           speed_setter(manualObject.getString("middle"),"middle");
           speed_setter(manualObject.getString("rightSide"),"right");
           //Serial.println("speedChanging mode working");
           speed_changing_mode();
        }
     }
  }
}
int speed_decider(String fan_speed){
    if(fan_speed=="low"){
      return low_speed;
      }else if(fan_speed=="medium"){
        return medium_speed;
      }else if(fan_speed=="high"){
          return high_speed;
      }else{
        return 0;
      }
  }
void speed_setter(String speed_state, String side){
  if ( side=="left"){
    if (speed_state=="low"){
        left_fan_speed=low_speed;
    }else if (speed_state=="medium"){
        left_fan_speed=medium_speed;
    }else if (speed_state=="high"){
        left_fan_speed=high_speed;
    }else{
        left_fan_speed=0;
    }
  }else if (side=="middle"){
    if (speed_state=="low"){
        middle_fan_speed=low_speed;
    }else if (speed_state=="medium"){
        middle_fan_speed=medium_speed;
    }else if (speed_state=="high"){
        middle_fan_speed=high_speed;
    }else{
        middle_fan_speed=0;
    }
  }else if ( side=="right"){
    if (speed_state=="low"){
        right_fan_speed=low_speed;
    }else if (speed_state=="medium"){
        right_fan_speed=medium_speed;
    }else if (speed_state=="high"){
        right_fan_speed=high_speed;
    }else{
        right_fan_speed=0;
     }
  }
  //Serial.println("left : ");
  //Serial.println(left_fan_speed);
  //Serial.println("middle : ");
  //Serial.println(middle_fan_speed);
  //Serial.println("right : ");
  //Serial.println(right_fan_speed);
}



