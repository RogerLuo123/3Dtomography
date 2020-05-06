// defines pins numbers
const int stepPin = 5;
const int dirPin = 2;
const int enPin = 8;
int flag = 0;
int leng;
void setup() {

  // Sets the two pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);

  Serial.begin(9600);

}

void loop() {

    if(flag==0){
      if(Serial.read() == 'a')
      {digitalWrite(1,HIGH);}
      if(Serial.read() == 'b')
      {digitalWrite(2,HIGH);
       char a = Serial.read();
       Serial.println(a);}
      //flag = 1;
      }

//    if(flag==1){
//        
//        char val=Serial.read();
//        
//        //RIGHT RESET
//        if(val=='R'){
//          for(int i =0;i<1000000;i++){
//          digitalWrite(dirPin,LOW);  
//            if(Serial.read()=='S'){
//              val='S';
//              break;}//jump out if receive STOP command
//              for(int x = 0; x < 800; x++) {
//                digitalWrite(stepPin,HIGH);
//                delayMicroseconds(500);
//                digitalWrite(stepPin,LOW);
//                delayMicroseconds(500);
//                }
//              flag = 1;
//              delay(0); //0 sec delay
//          }
//        }
//    
//        //1mm per stop LEFT GO
//        if(val=='L'){
//          for(int i=0;i<1000000;i++){
//          digitalWrite(dirPin, HIGH); 
//            if(Serial.read()=='S'){
//              val='S';
//              break;}
//              for (int x = 0; x < 80; x++) {
//                digitalWrite(stepPin, HIGH);
//                delayMicroseconds(500);
//                digitalWrite(stepPin, LOW);
//                delayMicroseconds(500);
//              }
//            flag = 1;
//            delay(1000); // One second delay
//          }
//        }
//    
//        //STOP
//        if(val=='S'){
//          digitalWrite(dirPin,LOW);
//          digitalWrite(enPin,LOW);
//          digitalWrite(stepPin,LOW);
//          flag=0;
//          delay(1000);
//          }
//      }
}
