#include "Quad7Segment.h"
#include "HC595.h"
//HC595 shreg(2,3,4,5);
Quad7Segment seg(2,3,4,5);

//this means
//2 -> ser
//3 -> srClk
//4 -> rClk
//5 -> clear
void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A5);
  int voltage = sensorValue;
//  Serial.println(n_voltage);
  seg.setNumber(voltage);
  seg.update();
//  i++;
//  shreg.pushn(0b110011111000, 12);
//  shreg.latch();
//  shreg.pushn(0b100100100100, 12);
//  shreg.latch();
  
//  delay(100);
}
