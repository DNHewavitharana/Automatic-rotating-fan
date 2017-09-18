void motor_fixed_rotate(Servo motor_control,int angle){
  motor_control.write(angle);
  }
void motor_rotation_two_areas(Servo motor_control,int angle_start,int angle_end){
  motor_control.write(angle_start);
  delay_setter(speed_turn);
  fan_rotator_forward(angle_mid,angle_end);
  delay_setter(speed_turn);
  fan_rotator_backward(angle_end, angle_mid);
} 
 
void motor_rotation_three_areas(Servo motor_control,int angle_start,int angle_mid,int angle_end){
  motor_control.write(angle_start);
  delay_setter(speed_turn);
  
  fan_rotator_forward(angle_start, angle_mid);
  delay_setter(speed_turn);
  
  fan_rotator_forward(angle_mid, angle_end);
  delay_setter(speed_turn);
  
  fan_rotator_backward(angle_end, angle_mid);
  delay_setter(speed_turn);
  
  fan_rotator_backward(angle_mid,angle_start);  
} 
 
void fan_rotator_forward(int angle_start, int angle_end){
  for (int x=angle_start; x<=angle_end ; x++){
      motor_control.write(x);
      delay_setter(speed_turn); 
    }
  }
void fan_rotator_backward(int angle_end, int angle_start){
  for (int x=angle_end; x<=angle_start ; x--){
      motor_control.write(x);
      delay_setter(speed_turn); 
    }
  }

void motor_drive_first_section_forward(Servo motor_control,bool speed_turn){
  for (int a=0; a<=60; a++){
      motor_control.write(a);
      delay_setter(speed_turn);   
  }
}
void motor_drive_second_section_forward(Servo motor_control,bool speed_turn){
  for (int b=60; b<=120; b++){
      motor_control.write(b);
      delay_setter(speed_turn);   
  }
}
void motor_drive_third_section_forward(Servo motor_control,bool speed_turn){
  for (int c=120; c<=180; c++){
      motor_control.write(c);
      delay_setter(speed_turn);   
  }
}
void motor_drive_third_section_backward(Servo motor_control,bool speed_turn){
  for (int j=180; j>=120; j--){
     motor_control.write(j);
     delay_setter(speed_turn);  
   }
}
void motor_drive_second_section_backward(Servo motor_control,bool speed_turn){
  for (int j=120; j>=60; j--){
     motor_control.write(j);
     delay_setter(speed_turn);  
   }
}
void motor_drive_first_section_backward(Servo motor_control,bool speed_turn){
  for (int j=60; j>0; j--){
     motor_control.write(j);
     delay_setter(speed_turn);  
   }
}

/*void motor_drive_right(Servo motor_control){
  for (int i=0; i<=90; i++){
      motor_control.write(i);
      delay(20);   
      int angle_right=motor_control.read();
      Serial.println(angle_right); 
  }
}
void motor_drive_left(Servo motor_control){
  for (int j=90; j>=0; j--){
     motor_control.write(j);
     delay(20);
     int angle_left=motor_control.read();
     Serial.println(angle_left);
   }
}*/
