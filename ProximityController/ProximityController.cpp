#include "ProximityController.h"

int sensorValue;
int threshold;
int sensorPins [] = {
  A1,
  A2,
  //A3,
  //A4
};

void startSensors(){
  pinMode(sensorPins[0], INPUT);
  pinMode(sensorPins[1], INPUT);
  //pinMode(sensorPins[2], INPUT);
  //pinMode(sensorPins[3], INPUT);
  
  Serial.begin(9600);
}

void run_Sensor_Loop(){
  threshold = 100;
  for(int i = 0; i < 2; i++){
    sensorValue = analogRead(sensorPins[i]);
    if(sensorValue < threshold){
      String text = "Sensor: ";
      text += String(i);
      text += ", Raw Reading: ";
      text += String(sensorValue);
      Serial.println(text);
      delay(50);
    }  
  }
  delay(1000);
}
