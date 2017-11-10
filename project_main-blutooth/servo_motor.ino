void motor_fixed_rotate(Servo motor_control,int angle, int speed_motor){
  motor_control.write(angle);
  }
void motor_rotation_two_areas(Servo motor_control,int angle_start,int angle_end,int speed_motor){
  motor_control.write(angle_start);
  delay_setter(speed_turn);
  fan_rotator_forward(angle_mid,angle_end,speed_motor);
  delay_setter(speed_turn);
  fan_rotator_backward(angle_end, angle_mid,speed_motor);
} 
 
void motor_rotation_three_areas(Servo motor_control,int angle_start,int angle_mid,int angle_end, int speed_motor){
  motor_control.write(angle_start);
  delay_setter(speed_turn);
  
  fan_rotator_forward(angle_start, angle_mid,speed_motor);
  delay_setter(speed_turn);
  
  fan_rotator_forward(angle_mid, angle_end,speed_motor);
  delay_setter(speed_turn);
  
  fan_rotator_backward(angle_end, angle_mid,speed_motor);
  delay_setter(speed_turn);
  
  fan_rotator_backward(angle_mid,angle_start,speed_motor);  
} 
 
void fan_rotator_forward(int angle_start, int angle_end, int speed_motor){
  int x = angle_start;
  while (x<=angle_end && input_availability){
    if (Serial.available()){
      read_input();
<<<<<<< HEAD
=======
      inputSetter();
>>>>>>> refs/remotes/origin/master
      constant_change_checker();
    }
    motor_speed_controller(speed_motor);
    motor_control.write(x);
    delay_setter(speed_turn); 
    x+=1;
  }  
 }

void fan_rotator_backward(int angle_end, int angle_start,int speed_motor){
    int x = angle_end;
    while (x>=angle_start && input_availability ){
      if (Serial.available()){
        read_input();
<<<<<<< HEAD
=======
        inputSetter();
>>>>>>> refs/remotes/origin/master
        constant_change_checker();
      }
      motor_speed_controller(speed_motor);
      motor_control.write(x);
      delay_setter(speed_turn); 
      x-=1;
     }
  }

void motor_drive_first_section_forward(Servo motor_control,bool speed_turn, int speed_motor){
  int a=0;
  while (a<=60 && input_availability){
    if (Serial.available()){
        read_input();
<<<<<<< HEAD
=======
        inputSetter();
>>>>>>> refs/remotes/origin/master
        constant_change_checker();
      }
      motor_speed_controller(speed_motor);
      motor_control.write(a);
      delay_setter(speed_turn);   
      a+=1;
   }
  }
  
void motor_drive_second_section_forward(Servo motor_control,bool speed_turn, int speed_motor){
    int b=60;
    while (b<=120 && input_availability){
       if (Serial.available()){
        read_input();
<<<<<<< HEAD
=======
        inputSetter();
>>>>>>> refs/remotes/origin/master
        constant_change_checker();
      }
       motor_speed_controller(speed_motor);
       motor_control.write(b);
       delay_setter(speed_turn);   
       b+=1;
      }
  }

void motor_drive_third_section_forward(Servo motor_control,bool speed_turn, int speed_motor){
    int c=120;
    while (c<=180 && input_availability){
       if (Serial.available()){
        read_input();
<<<<<<< HEAD
=======
        inputSetter();
>>>>>>> refs/remotes/origin/master
        constant_change_checker();
      }
      motor_speed_controller(speed_motor);
      motor_control.write(c);
      delay_setter(speed_turn);   
      c+=1;
      }
  }
void motor_drive_third_section_backward(Servo motor_control,bool speed_turn, int speed_motor){
    int j=180;
    while (j>=120 && input_availability){
      if (Serial.available()){
        read_input();
<<<<<<< HEAD
=======
        inputSetter();
>>>>>>> refs/remotes/origin/master
        constant_change_checker();
      }
      motor_speed_controller(speed_motor);
      motor_control.write(j);
      delay_setter(speed_turn);
      j-=1; 
    }
  }

void motor_drive_second_section_backward(Servo motor_control,bool speed_turn, int speed_motor){
    int j=120;
    while (j>=60 && input_availability){
      if (Serial.available()){
        read_input();
<<<<<<< HEAD
=======
        inputSetter();
>>>>>>> refs/remotes/origin/master
        constant_change_checker();
      }
      motor_speed_controller(speed_motor);
      motor_control.write(j);
      delay_setter(speed_turn);
      j-=1; 
    }
  }
  
void motor_drive_first_section_backward(Servo motor_control,bool speed_turn, int speed_motor){
    int j=60;
    while (j>0 && input_availability){
      if (Serial.available()){
        read_input();
<<<<<<< HEAD
=======
        inputSetter();
>>>>>>> refs/remotes/origin/master
        constant_change_checker();
      }
      motor_speed_controller(speed_motor);
      motor_control.write(j);
      delay_setter(speed_turn);
      j-=1; 
    } 
  }
   

<<<<<<< HEAD

=======

>>>>>>> refs/remotes/origin/master
