
#include <SoftwareSerial.h>
#define strlength 20
char numbers[] = {'0','1','2','3','4','5','6','7','8','9'};
String tostr[] = {"Zero","one","two","three","four","five","six","seven","eight","nine","0","1","2","3","4","5","6","7","8","9"};
// 'one','two','three','four','five','six','seven','eight','nine','ten',
SoftwareSerial mySerial(10, 11); // RX, TX
String m = "";
/*
int convstr(String a)
{
  
  for(int i = 0;i<strlength;i++){
  if (i<10 && tostr[i] == a)
        {
          return numbers[i];
        }
        
   else if (i>=10 && i<=20 && tostr[i] == a) 
        {
          return numbers[i-10];
        }
  }
  
}
 */ 

 int convertion(char a)
{
  
  for(int i = 0;i<strlength;i++){

        if (numbers[i] == a)
        {
          return i;
        }
    
  }
        
}

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(9,OUTPUT);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
 // mySerial.println("Hello, world?");
}

void loop() { 
  
  int a = 0;
  if(Serial.available()) {
      a = mySerial.read();
     // m = Serial.read();
     // Serial.print(m);
     // Serial.print(a);
      a = a-48;
      
      

  }
  
 
  if(a!=0)
  {
 // Serial.write(a); 
  //Serial.write(map(a,0,9,0,254));
  if(a == '<'){
    PORTB &= ~(1<<PB1);
  }
   if (a == '6')
  {
    PORTB |= (1<<PB1);
    DDRB &= ~(1<<PB1);
  }
  analogWrite(9,map(a,0,9,0,254));
  }
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  
  delay(100);
  
  
}
