void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(10,255);
  delay(2000);
  analogWrite(10,0);
  delay(2000);
}
