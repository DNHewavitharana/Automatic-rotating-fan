void speed_changing_mode(){
      motor_drive_first_section_forward(motor_control,speed_turn,left_fan_speed);
      delay(200);
      motor_drive_second_section_forward(motor_control,speed_turn,middle_fan_speed);
      delay(200);
      motor_drive_third_section_forward(motor_control,speed_turn,right_fan_speed);
      delay(200);
      motor_drive_third_section_backward(motor_control,speed_turn,right_fan_speed);
      delay(200);
      motor_drive_second_section_backward(motor_control,speed_turn,middle_fan_speed);
      delay(200);
      motor_drive_first_section_backward(motor_control,speed_turn,left_fan_speed); 
      delay(200);
    
  }
