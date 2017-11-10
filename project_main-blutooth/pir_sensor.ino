
int pir_L(){
  //return HIGH;
 // Serial.println(digitalRead(pir_left));
  return digitalRead(pir_left);
}
int pir_R(){
 // return HIGH;
  return digitalRead(pir_right);
}
int pir_M(){
  //return LOW;
  return digitalRead(pir_middle);
}

int pir_person_detec(){
  return digitalRead(pir_person_detector);
}
<<<<<<< HEAD

=======

>>>>>>> refs/remotes/origin/master
