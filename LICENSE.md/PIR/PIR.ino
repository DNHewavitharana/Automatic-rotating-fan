int led= 4;
int pir_left= 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(pir_left,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x =digitalRead(pir_left);
  Serial.println(x);
  if (x==1){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
    }
}
