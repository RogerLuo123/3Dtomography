// defines pins numbers
const int stepPin = 5;
const int dirPin = 2;
const int enPin = 8;
void setup() {

  // Sets the two pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);

  Serial.begin(9600);

}
void loop() {
  //if(Serial.available()){

     char val=Serial.read();
    if(val=='R'){
    //RIGHT RESET
    for(int i =0;i<1000000;i++){
      digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction
     // Makes 200 pulses for making one full cycle rotation
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
    if(val=='L'){
      //1mm per stop LEFT GO
      for(int i=0;i<1000000;i++){
      digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction
      // Makes 200 pulses for making one full cycle rotation
        for (int x = 0; x < 80; x++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(500);
        }
      delay(1000); // One second delay
      }
    }

    if(val=='S'){
      digitalWrite(dirPin,LOW);
      digitalWrite(enPin,LOW);
      digitalWrite(stepPin,LOW);
      delay(1000);
      }
  //}
}
