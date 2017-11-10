void angle_fixed_mode(int fixed_angle){
  int angle=180- fixed_angle;
  fan_rotator_forward(angle, angle+1, speed_motor);
}
