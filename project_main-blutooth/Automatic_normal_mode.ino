void automatic_normal_mode(Servo motor_control) {
   if (pir_L()== HIGH && pir_M()== LOW && pir_R()== LOW ){
      motor_drive_first_section_forward(motor_control,speed_turn,speed_motor);
      motor_drive_first_section_backward(motor_control,speed_turn,speed_motor);
      Serial.println("Left sensor");
    }
    else if(pir_L()== LOW && pir_M()== HIGH && pir_R()== LOW){
        motor_drive_second_section_forward(motor_control,speed_turn,speed_motor);
        motor_drive_second_section_backward(motor_control,speed_turn, speed_motor);
        Serial.println("middle sensor");    
    }
    else if(pir_L()== LOW && pir_M()== LOW && pir_R()== HIGH){
        motor_drive_third_section_forward(motor_control,speed_turn, speed_motor);
        motor_drive_third_section_backward(motor_control,speed_turn, speed_motor);
        Serial.println("right sensor");    
    }
    else if(pir_L()== HIGH && pir_M()== HIGH && pir_R()== LOW){
      
        motor_drive_first_section_forward(motor_control,speed_turn,speed_motor);
        motor_drive_second_section_forward(motor_control,speed_turn,speed_motor);
        motor_drive_second_section_backward(motor_control,speed_turn,speed_motor);
        motor_drive_first_section_backward(motor_control,speed_turn,speed_motor); 
        Serial.println("Left two sensor");      
    }
      else if(pir_L()== LOW && pir_M()== HIGH && pir_R()== HIGH){
       
        motor_drive_second_section_forward(motor_control,speed_turn, speed_motor);
        motor_drive_third_section_forward(motor_control,speed_turn,speed_motor);
        motor_drive_third_section_backward(motor_control,speed_turn,speed_motor);
        motor_drive_second_section_backward(motor_control,speed_turn,speed_motor); 
        Serial.println("right two sensor");      
    }
   else if(pir_L()== HIGH && pir_M()== LOW && pir_R()== HIGH){
        motor_drive_first_section_forward(motor_control,speed_turn,speed_motor);
        motor_drive_second_section_forward(motor_control,false,speed_motor);
        motor_drive_third_section_forward(motor_control,speed_turn,speed_motor);
        motor_drive_third_section_backward(motor_control,speed_turn,speed_motor);
        motor_drive_second_section_backward(motor_control,false,speed_motor);
        motor_drive_first_section_backward(motor_control,speed_turn,speed_motor); 
        Serial.println("middle sensor low");      
    }
    else if(pir_L()== HIGH && pir_M()== HIGH && pir_R()== HIGH){     
        motor_drive_first_section_forward(motor_control,speed_turn,speed_motor);
        motor_drive_second_section_forward(motor_control,speed_turn,speed_motor);
        motor_drive_third_section_forward(motor_control,speed_turn,speed_motor);
        motor_drive_third_section_backward(motor_control,speed_turn,speed_motor);
       motor_drive_second_section_backward(motor_control,speed_turn,speed_motor);
        motor_drive_first_section_backward(motor_control,speed_turn,speed_motor);
        Serial.println("All sensor high");       
    }else{
      motor_control.write(90);
      motor_speed_controller(0);
      Serial.println("All sensor low"); 
      }
  }
