void fixed_range_rotate(int fixed_angle_start, int fixed_angle_end){
  if (fixed_angle_start < fixed_angle_end){
     fan_rotator_backward(180 - fixed_angle_start, 180 - fixed_angle_end, speed_motor);
     fan_rotator_forward(180 - fixed_angle_end, 180 - fixed_angle_start,speed_motor);
  }else{
     fan_rotator_backward(180 - fixed_angle_end, 180 - fixed_angle_start,speed_motor);
     fan_rotator_forward(180 - fixed_angle_start, 180 - fixed_angle_end,speed_motor);
    }
}
