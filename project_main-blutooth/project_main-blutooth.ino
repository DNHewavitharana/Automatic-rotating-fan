<<<<<<< HEAD
 #include <Servo.h>
=======
#include <Servo.h>
>>>>>>> refs/remotes/origin/master
Servo motor_control;
                 
bool speed_turn = true;

int motor_control_pin= 9;
int pir_left= 10;
int pir_middle= 11;
int pir_right= 12;
<<<<<<< HEAD
 
=======

>>>>>>> refs/remotes/origin/master
int fan_speed_control_pin= 6;

int pir_person_detector=7;

//person_detector_mode
int angle_start;
int angle_end;
int angle_mid;
int angle;

//fixed_range_mode angles
int fixed_angle_start;  
int fixed_angle_end;

//speed_changing_mode_speeds
int low_speed=150;
int medium_speed=200;
int high_speed=255;

int left_fan_speed;
int middle_fan_speed;
int right_fan_speed;
int speed_motor;

//angle_fixed_mode
int fixed_speed_motor;

bool input_availability=true;

<<<<<<< HEAD

=======
String val="0000000000000";
>>>>>>> refs/remotes/origin/master
boolean fan_state;
String fan_mode;
String mode_state;

boolean current_fan_state;
String current_fan_mode;
String current_mode_state;
<<<<<<< HEAD
String val;
int input_collector[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
=======
>>>>>>> refs/remotes/origin/master

void setup() {
  Serial.begin(9600);
  pinMode(fan_speed_control_pin, OUTPUT);
  pinMode(pir_left,INPUT);
  pinMode(pir_middle,INPUT);
  pinMode(pir_right,INPUT);
  pinMode(pir_person_detector,INPUT);
  motor_control.attach(motor_control_pin);
}

<<<<<<< HEAD

int begin_loop=0;
void loop(){
  if (begin_loop==0){
    begin_loop+=1;
    inputSetter();
    Serial.println(fan_state);
    Serial.println(fan_mode);
    Serial.println(mode_state);
    Serial.println(fixed_angle_start);
    Serial.println(fixed_angle_end);
    Serial.println(speed_motor);
    Serial.println(left_fan_speed);
    Serial.println(middle_fan_speed);
    Serial.println(right_fan_speed);
    
    }
    
  if (Serial.available()){
    read_input();
=======
void inputSetter(){
  if (val[0]== 0){
    fan_state=false;
    }else{
      fan_state=true;
    }
  if (val[1]== 1){
    fan_mode="Manual";
    }else if (val[1]== 2){
      fan_mode="Auto";
    }
  if (val[1]== 1 && val[2]== 0){
     mode_state="fixed_angle";
    }
  else if (val[1]== 1 && val[2]== 1){
      mode_state="fixed_range";
      }
  else if (val[1]== 1 && val[2]== 2){
      mode_state="speed_changing";
      }
  else if (val[1]== 2 && val[2]== 0){
      mode_state="Automatic_normal";
      }
  fixed_angle_start = val[3] + val[4] + val[5];
  fixed_angle_end = val[6] + val[7] + val[8];
  if (val[9]==0){
    speed_motor= 0;
  }else if (val[9]==1){
    speed_motor= low_speed;
  }else if (val[9]==2){
    speed_motor= medium_speed;
  }else if (val[9]==3){
    speed_motor= high_speed;
  }
  left_fan_speed = val[10];
  middle_fan_speed = val[11];
  right_fan_speed = val[12];
}

void loop(){
  inputSetter();
  if (Serial.available()){
      read_input();
      inputSetter();
>>>>>>> refs/remotes/origin/master
    }
  current_fan_state=fan_state;
  current_fan_mode=fan_mode;
  current_mode_state= mode_state;
<<<<<<< HEAD

  
  if (fan_state== 1){
=======
  if (fan_state= true){
>>>>>>> refs/remotes/origin/master
    if (fan_mode=="Manual" && mode_state=="fixed_angle"){
      angle_fixed_mode(fixed_angle_start);
      }
     else if (fan_mode=="Manual" && mode_state=="fixed_range"){
      fixed_range_rotate(fixed_angle_start, fixed_angle_end);
      }
     else if (fan_mode=="Manual" && mode_state=="speed_changing"){
      speed_changing_mode();
      }
     else if (fan_mode=="Auto" && mode_state=="Automatic_normal"){
      automatic_normal_mode(motor_control);
      }
<<<<<<< HEAD
    }else{
      motor_speed_controller(0);
      motor_control.write(90);
      fan_mode="0";
      }
=======
    }
>>>>>>> refs/remotes/origin/master
    input_availability=true;
  }

void read_input(){
<<<<<<< HEAD
  int count=0;
  while (count<13){
    val = ((byte)Serial.read());
    if ((val.toInt()-48)<10){
      input_collector[count]=val.toInt()-48;
      Serial.println(input_collector[count]);
      count+=1;
    }
  }
  inputSetter();
  Serial.println("After change");
  Serial.println(fan_state);
  Serial.println(fan_mode);
  Serial.println(mode_state);
  Serial.println(fixed_angle_start);
  Serial.println(fixed_angle_end);
  Serial.println(speed_motor);
  Serial.println(left_fan_speed);
  Serial.println(middle_fan_speed);
  Serial.println(right_fan_speed);
  
=======
  val=Serial.read();
  Serial.println(val);
>>>>>>> refs/remotes/origin/master
  }

void constant_change_checker(){
  if ((fan_state == false) && (current_fan_state != fan_state) && (current_fan_mode != fan_mode) && (current_mode_state != mode_state)){
     input_availability=false;
    }
  }
<<<<<<< HEAD
  

void inputSetter(){
  if (input_collector[0]== 0){
    fan_state=false;
    }else{
      fan_state=true;
    }
  if (input_collector[1]== 1){
    fan_mode="Manual";
    }else if (input_collector[1]== 2){
      fan_mode="Auto";
    }
  if (input_collector[1]== 1 && input_collector[2]== 0){
     mode_state="fixed_angle";
    }
  else if (input_collector[1]== 1 && input_collector[2]== 1){
      mode_state="fixed_range";
      }
  else if (input_collector[1]== 1 && input_collector[2]== 2){
      mode_state="speed_changing";
      }
  else if (input_collector[1]== 2 ){
      mode_state="Automatic_normal";
      }
  fixed_angle_start = (String(input_collector[3]) + String(input_collector[4]) + String(input_collector[5])).toInt();
  fixed_angle_end = (String(input_collector[6]) + String(input_collector[7]) + String(input_collector[8])).toInt();
  if (input_collector[9]==0){
    speed_motor= 0;
  }else if (input_collector[9]==1){
    speed_motor= low_speed;
  }else if (input_collector[9]==2){
    speed_motor= medium_speed;
  }else if (input_collector[9]==3){
    speed_motor= high_speed;
  }
    if (input_collector[10]==0){
    left_fan_speed= 0;
  }else if (input_collector[10]==1){
    left_fan_speed= low_speed;
  }else if (input_collector[10]==2){
    left_fan_speed= medium_speed;
  }else if (input_collector[10]==3){
    left_fan_speed= high_speed;
  }
    if (input_collector[11]==0){
    middle_fan_speed= 0;
  }else if (input_collector[11]==1){
    middle_fan_speed= low_speed;
  }else if (input_collector[11]==2){
    middle_fan_speed= medium_speed;
  }else if (input_collector[11]==3){
    middle_fan_speed= high_speed;
  }
  if (input_collector[12]==0){
    right_fan_speed= 0;
  }else if (input_collector[12]==1){
    right_fan_speed= low_speed;
  }else if (input_collector[12]==2){
    right_fan_speed= medium_speed;
  }else if (input_collector[12]==3){
    right_fan_speed= high_speed;
  }
}




=======


>>>>>>> refs/remotes/origin/master
