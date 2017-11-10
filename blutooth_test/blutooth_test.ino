us
#include <Eventually.h>
EvtManager mgr;
void setup() {
  // put your setup code here, to run once:
  pinMode(4,OUTPUT);
  Serial.begin(9600);
  mgr.addListener(new EvtTimeListener(1000, true, (EvtAction)mainWork));
  //mgr.addListener(new EvtTimeListener(10000, true, (EvtAction)light));
}
USE_EVENTUALLY_LOOP(mgr)

char val;
void mainWork() { 
  // put your main code here, to run repeatedly:
  if (Serial.available()){
     val=Serial.read();
     Serial.println(val);
    }
    light();
}
void light(){
  if (val=='1'){
    digitalWrite(4,HIGH);
    delay(1000);
    }
    else{
      digitalWrite(4,LOW);
    delay(1000);
      }
  }


