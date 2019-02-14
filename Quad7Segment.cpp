#include "Quad7Segment.h"
#include "HC595.h"
//int buffer[4];

// 0 means on 1 means off
//http://www.nutsvolts.com/magazine/article/using-seven-segment-displays-part-1
const int Quad7Segment::pattern[10] = { 
  //abcdefg
  0b100000010000, //0
  0b110011110000, //1
  0b100100100000, //2
  0b100001100000, //3
  0b110011000000, //4
  0b101001000000, //5
  0b101000000000, //6
  0b100011110000, //7
  0b100000000000, //8
  0b100011000000 //9
};

Quad7Segment::Quad7Segment(int ser, int srClk, int rClk, int srClr):
  shreg(ser,srClk,rClk,srClr){
}

void Quad7Segment::setup(){
  //implement this
  
}

void Quad7Segment::update(){
  for (int i = 0; i < 4; i++){
    shreg.pushn(buffer[i], 12);
    shreg.latch();
  }
}

void Quad7Segment::setNumber(int n){
  //implement this
  buffer[0] = pattern[(n/1000)] | 8;
  buffer[1] = pattern[((n/100) % 10)] | 4;
  buffer[2] = pattern[((n/10) % 10)]  | 2;
  buffer[3] = pattern[(n % 10)] | 1;
}
