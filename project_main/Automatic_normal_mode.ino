void automatic_normal_mode(){
  while(state1){
   if (pir_L()== HIGH && pir_M()== LOW && pir_R()== LOW ){
    digitalWrite(led,HIGH);
      motor_drive_first_section_forward(motor_control,speed_turn);
      motor_drive_first_section_backward(motor_control,speed_turn);
      Serial.println("Left sensor");
    }
    else if(pir_L()== LOW && pir_M()== HIGH && pir_R()== LOW){
      led_blink();
        motor_drive_second_section_forward(motor_control,speed_turn);
        motor_drive_second_section_backward(motor_control,speed_turn);
        Serial.println("middle sensor");    
    }
    else if(pir_L()== LOW && pir_M()== LOW && pir_R()== HIGH){
      led_blink();
        motor_drive_third_section_forward(motor_control,speed_turn);
        motor_drive_third_section_backward(motor_control,speed_turn);
        Serial.println("right sensor");    
    }
    else if(pir_L()== HIGH && pir_M()== HIGH && pir_R()== LOW){
      led_blink();
        motor_drive_first_section_forward(motor_control,speed_turn);
        motor_drive_second_section_forward(motor_control,speed_turn);
        motor_drive_second_section_backward(motor_control,speed_turn);
        motor_drive_first_section_backward(motor_control,speed_turn); 
        Serial.println("Left two sensor");      
    }
      else if(pir_L()== LOW && pir_M()== HIGH && pir_R()== HIGH){
        led_blink();
        motor_drive_second_section_forward(motor_control,speed_turn);
        motor_drive_third_section_forward(motor_control,speed_turn);
        motor_drive_third_section_backward(motor_control,speed_turn);
        motor_drive_second_section_backward(motor_control,speed_turn); 
        Serial.println("right two sensor");      
    }
   else if(pir_L()== HIGH && pir_M()== LOW && pir_R()== HIGH){
        led_blink();
        motor_drive_first_section_forward(motor_control,speed_turn);
        motor_drive_second_section_forward(motor_control,false);
        motor_drive_third_section_forward(motor_control,speed_turn);
        motor_drive_third_section_backward(motor_control,speed_turn);
        motor_drive_second_section_backward(motor_control,false);
        motor_drive_first_section_backward(motor_control,speed_turn); 
        Serial.println("between sensor");      
    }
    else if(pir_L()== HIGH && pir_M()== HIGH && pir_R()== HIGH){
      led_blink();
        motor_drive_first_section_forward(motor_control,speed_turn);
        motor_drive_second_section_forward(motor_control,speed_turn);
        motor_drive_third_section_forward(motor_control,speed_turn);
        motor_drive_third_section_backward(motor_control,speed_turn);
        motor_drive_second_section_backward(motor_control,speed_turn);
        motor_drive_first_section_backward(motor_control,speed_turn);
        Serial.println("All sensor");       
    }else{
      digitalWrite(led,LOW);
      }
  }
}
