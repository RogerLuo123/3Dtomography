import controlP5.*;
import processing.serial.*;

Serial port;


ControlP5 cp5;
String url1;
PFont font;
String value;
int PP;

void setup(){
  size(300, 600);
  printArray(Serial.list());
  port = new Serial(this,"/dev/cu.usbmodem14201",9600);
  
  cp5 = new ControlP5(this);
  font = createFont("abc",20);
  cp5.addButton("LEFT")
    .setPosition(30,100)
    .setSize(100,80)
    .setFont(font);
  ;
  
    cp5.addButton("RIGHT")
    .setPosition(170,100)
    .setSize(100,80)
    .setFont(font);
  ;
  
    cp5.addButton("STOP")
    .setPosition(100,220)
    .setSize(100,80)
    .setFont(font);
  ;
  
    cp5.addTextfield("step length (mm)")
    .setPosition(100,340)
    .setSize(100,40)
    .setFont(font)
    .setAutoClear(false);
  ;
    
    cp5.addBang("submit")
    .setPosition(110,420)
    .setSize(80,35)
    .setFont(font)
  ;
}

void draw(){
  background(0,0,0);
  fill(0,0,0);
  textFont(font);
  text("LINEARSTAGE CONTROL", 40, 30);
//  if ( port.available() > 0) 
//  {  // If data is available,
//  value = port.readStringUntil('\n');         // read it and store it in val
//  } 
//println(value); //print it out in the console
}

void submit(){
  url1 = cp5.get(Textfield.class,"step length (mm)").getText();
  PP = int(url1);
  port.write(PP);
}

void LEFT(){
  port.write('L');
}

void RIGHT(){
  port.write('R');
}

void STOP(){
  port.write('S');
}
