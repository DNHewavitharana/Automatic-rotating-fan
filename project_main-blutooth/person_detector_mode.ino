void person_detect_mode(){
    if (pir_L()== HIGH && pir_M()== LOW && pir_R()== LOW ){
      
      motor_fixed_rotate(motor_control, angle,speed_motor);
    }
    else if(pir_L()== LOW && pir_M()== HIGH && pir_R()== LOW){
        
        motor_fixed_rotate(motor_control,angle,speed_motor);    
    }
    else if(pir_L()== LOW && pir_M()== LOW && pir_R()== HIGH){
        
        motor_fixed_rotate(motor_control,angle,speed_motor);  
    }
    else if(pir_L()== HIGH && pir_M()== HIGH && pir_R()== LOW){
        
        motor_rotation_two_areas(motor_control, angle_start, angle_end, speed_motor);  
    }
    else if(pir_L()== LOW && pir_M()== HIGH && pir_R()== HIGH){
        
        motor_rotation_two_areas(motor_control, angle_start, angle_end, speed_motor);  
    }
   else if(pir_L()== HIGH && pir_M()== LOW && pir_R()== HIGH){
       
        motor_rotation_two_areas(motor_control, angle_start,angle_end, speed_motor);     
    }
    else if(pir_L()== HIGH && pir_M()== HIGH && pir_R()== HIGH){
        
        motor_rotation_three_areas(motor_control, angle_start, angle_mid, angle_end, speed_motor);       
    }
  
}

void angle_calculator(){
  angle_start=30;
  angle_end=60;
  angle_mid=45;
  angle= 90;
  

  
  }




