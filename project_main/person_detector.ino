void person_detect_mode(){
  while(state2){
    if (pir_L()== HIGH && pir_M()== LOW && pir_R()== LOW ){
      led_blink();
      motor_fixed_rotate(motor_control, angle);
    }
    else if(pir_L()== LOW && pir_M()== HIGH && pir_R()== LOW){
        led_blink();
        motor_fixed_rotate(motor_control,angle);    
    }
    else if(pir_L()== LOW && pir_M()== LOW && pir_R()== HIGH){
        led_blink();
        motor_fixed_rotate(motor_control,angle);  
    }
    else if(pir_L()== HIGH && pir_M()== HIGH && pir_R()== LOW){
        led_blink();
        motor_rotation_two_areas(motor_control, angle_start, angle_end);  
    }
    else if(pir_L()== LOW && pir_M()== HIGH && pir_R()== HIGH){
        led_blink();
        motor_rotation_two_areas(motor_control, angle_start, angle_end);  
    }
   else if(pir_L()== HIGH && pir_M()== LOW && pir_R()== HIGH){
        led_blink();
        motor_rotation_two_areas(motor_control, angle_start,angle_end);     
    }
    else if(pir_L()== HIGH && pir_M()== HIGH && pir_R()== HIGH){
        led_blink();
        motor_rotation_three_areas(motor_control, angle_start, angle_mid, angle_end);       
    }else{
        digitalWrite(led,LOW);
    }
  }
}

void angle_calculator(){
  angle_start=30;
  angle_end=60;
  angle_mid=45;
  angle= 90;
  

  
  }



