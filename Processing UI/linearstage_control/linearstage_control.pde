import controlP5.*;
import processing.serial.*;

Serial port;


ControlP5 cp5;
PFont font;

void setup(){
  size(300, 400);
  printArray(Serial.list());
  port = new Serial(this,"COM5",9600);
  
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
}

void draw(){
  background(255,255,255);
  fill(0,0,0);
  textFont(font);
  text("LINEARSTAGE CONTROL", 40, 30);
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
