// defines pins numbers
const int stepPin = 5;
const int dirPin = 2;
const int enPin = 8;
int Flag1=0;
int Flag2=0;
int timedelay;
char val;
void setup() {

  // Sets the two pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);

  Serial.begin(9600);

}
void loop() {
    if(Flag1==0)
      {char mode=Serial.read();
       if(mode=='U')
       {timedelay=1000;}
       if(mode=='I')
       {timedelay=2000;}
       if(mode=='O')
       {timedelay=3000;}
       Flag1=1;
      }
    if(Flag2==0)
      {val=Serial.read();
      Flag2=1;
      }
    if(val=='R'){
    //RIGHT RESET
    for(int i =0;i<1000000;i++){
      digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction
      if(Serial.read()=='S'){
        val='S';
        break;}
        for(int x = 0; x < 800; x++) {
          digitalWrite(stepPin,HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin,LOW);
          delayMicroseconds(500);
        }
        delay(0);
        }
       // One second delay
      }
    if(val=='A'){
      //1mm per stop LEFT GO
      for(int i=0;i<1000000;i++){
      digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction
      // Makes 200 pulses for making one full cycle rotation
      if(Serial.read()=='S'){
        val='S';
        break;}
        for (int x = 0; x < 80; x++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(500);
        }
      delay(timedelay); // One second delay
      }
    }

    if(val=='B'){
      //2mm per stop LEFT GO
      for(int i=0;i<1000000;i++){
      digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction
      // Makes 200 pulses for making one full cycle rotation
      if(Serial.read()=='S'){
        val='S';
        break;}
        for (int x = 0; x < 160; x++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(500);
        }
      delay(timedelay); // One second delay
      }
    }

    if(val=='C'){
      //3mm per stop LEFT GO
      for(int i=0;i<1000000;i++){
      digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction
      // Makes 200 pulses for making one full cycle rotation
      if(Serial.read()=='S'){
        val='S';
        break;}
        for (int x = 0; x < 240; x++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(500);
        }
      delay(timedelay); // One second delay
      }
    }

    if(val=='S'){
      digitalWrite(dirPin,LOW);
      digitalWrite(enPin,LOW);
      digitalWrite(stepPin,LOW);
      delay(1000);
      }
}
