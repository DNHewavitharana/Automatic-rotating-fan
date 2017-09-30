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
  if (digitalRead(pir_left)==HIGH){
    Serial.println(digitalRead(pir_left));
    digitalWrite(led,HIGH);

  }else{
    Serial.println(digitalRead(pir_left));
    digitalWrite(led,LOW);
    }
}

