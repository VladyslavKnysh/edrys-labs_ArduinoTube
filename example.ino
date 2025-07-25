#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

double kp = 0.002;
double ki = 0.001;
double kd = 0.0003;
int dir   = 166; 

double KP,KI,KD;

int motorCMD, errorValue, prevErrorValue;

double sum, prevSum;

int motorPin = 3;

unsigned long tic, tic2, tic3;
int pause = 100;
int steadiness = 5000/pause;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(motorPin, OUTPUT);

  Wire.begin();

  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }

  sensor.startContinuous();
  Serial.println("Write your task:");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    int pos, i,j;
    int task = Serial.parseInt();
    if(task>0){
      tic = millis();
      while(millis()<tic+30000){
        tic2 = millis();
        pos = 970 - sensor.readRangeContinuousMillimeters();
        errorValue = task - pos;
        sum = prevSum+pause*ki*errorValue/1000;
        
        KP = kp*errorValue*255;
        KI = sum*255;
        KD = ((errorValue-prevErrorValue)/(i*1000/pause))*kd*255;

         motorCMD = dir+KP+KI+KD;

         if(motorCMD>255){
           motorCMD = 255;
         }else if(motorCMD<0){
           motorCMD = 0;
         }
         analogWrite(motorPin,motorCMD);
        
        if(abs(errorValue)<20){
          j++;
        }else{
          j=0;
        }
        if(j>=steadiness){
          break;
        }
        
        Serial.print("Position:");
        Serial.println(pos);

        prevErrorValue = errorValue;
        prevSum = sum;
        i++;
        delay(tic2+pause-millis());
      }
        double grad = motorCMD/5;
        tic3 = millis();
        while(tic3+5000>millis()){
             analogWrite(motorPin,motorCMD - grad*millis()/1000);
        }
         analogWrite(motorPin,0);
    }
    Serial.println("Write your task:");
  }
  
}
