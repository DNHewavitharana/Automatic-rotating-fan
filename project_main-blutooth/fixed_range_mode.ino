void fixed_range_rotate(int fixed_angle_start, int fixed_angle_end){
<<<<<<< HEAD
  if (fixed_angle_start < fixed_angle_end){
     fan_rotator_backward(180 - fixed_angle_start, 180 - fixed_angle_end, speed_motor);
     fan_rotator_forward(180 - fixed_angle_end, 180 - fixed_angle_start,speed_motor);
  }else{
     fan_rotator_backward(180 - fixed_angle_end, 180 - fixed_angle_start,speed_motor);
     fan_rotator_forward(180 - fixed_angle_start, 180 - fixed_angle_end,speed_motor);
    }
}
=======
   fan_rotator_forward(fixed_angle_start, fixed_angle_end, speed_motor);
   //Serial.println("working");
   fan_rotator_backward(fixed_angle_end, fixed_angle_start,speed_motor);
   }
>>>>>>> refs/remotes/origin/master
