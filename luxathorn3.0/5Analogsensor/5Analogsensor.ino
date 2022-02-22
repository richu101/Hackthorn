
#include<Arduino.h>
#define SensorPin0 A0            //LUX meter Analog output to Arduino Analog Input 0
#define SensorPin1 A1
#define SensorPin2 A2
#define SensorPin3 A3
#define SensorPin4 A4
     
#define LED 13
#define samplingInterval 10 
#define printInterval 400
#define ArrayLenth  40    //times of collection
int LUXArray[ArrayLenth];   //Store the average value of the sensor feedback
int LUXArrayIndex = 0;

int y=0;
void setup(void)
{
  
  Serial.begin(9600);
  
}
void loop(void)
{
  static unsigned long samplingTime = millis();
  static unsigned long printTime = millis();
  static float LUXvalue, voltage;
  if (millis() - samplingTime > samplingInterval)
  {
    LUXArray[LUXArrayIndex++] = analogRead(SensorPin);
    if (LUXArrayIndex == ArrayLenth)LUXArrayIndex = 0;
    voltage = avergearray(LUXArray, ArrayLenth);
   
    samplingTime = millis();
  }
  if (millis() - printTime > printInterval)  //Every 800 milliseconds, print a numerical, convert the state of the LED indicator
  {

    Serial.println(analogRead(SensorPin));
    // equation to convert analog read values to lux
    y = voltage*voltage*voltage*(1.09182162799e-6)+voltage*voltage*(-8.0086930755e-4)+voltage*(2.2492992246159e-1)+(-1.3179239997436e+1);
   // Serial.print("    LUX value: ");
   // Serial.println(LUXvalue, 2);
   Serial.print("lux : ");
   Serial.println(y);
   // digitalWrite(LED, digitalRead(LED) ^ 1);
    printTime = millis();
  }
}
double avergearray(int* arr, int number) {
  int i;
  int max, min;
  double avg;
  long amount = 0;
  if (number <= 0) {
    Serial.println("Error number for the array to avraging!/n");
    return 0;
  }
  if (number < 5) { //less than 5, calculated directly statistics
    for (i = 0; i < number; i++) {
      amount += arr[i];
    }
    avg = amount / number;
    return avg;
  } else {
    if (arr[0] < arr[1]) {
      min = arr[0]; max = arr[1];
    }
    else {
      min = arr[1]; max = arr[0];
    }
    for (i = 2; i < number; i++) {
      if (arr[i] < min) {
        amount += min;      //arr<min
        min = arr[i];
      } else {
        if (arr[i] > max) {
          amount += max;  //arr>max
          max = arr[i];
        } else {
          amount += arr[i]; //min<=arr<=max
        }
      }//if
    }//for
    avg = (double)amount / (number - 2);
  }//if
  return avg;
}
