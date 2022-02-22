
#include <SoftwareSerial.h>
#define strlength 20
int numbers[] = {0,1,2,3,4,5,6,7,8,9};
String tostr[] = {"Zero","one","tu","three","four","five","six","seven","eight","nine","0","1","2","3","4","5","6","7","8","9"};
// 'one','two','three','four','five','six','seven','eight','nine','ten',
SoftwareSerial mySerial(10, 11); // RX, TX
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
/*
int convertion(char a)
{
  
  for(int i = 0;i<strlength;i++){

        if (numbers[i] == a)
        {
          return i;
        }
    
  }
        
   */     
    
   /* 
    *  
    *  if(i>10){
      return 10-i;
        }
    */
   


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(38400);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
 // mySerial.println("Hello, world?");
}

void loop() { // run over and over
  if (mySerial.available()) {
     a = mySerial.read();
    String b = String(mySerial.read());
    Serial.println(convstr(b));
    // Serial.println(strlen(a));
  }
  
  
}
