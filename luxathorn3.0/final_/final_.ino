
#define strlength 20
#define personoutTime 10000

const int buttonPin1 = 2;
const int buttonPin2 = 3;
static inline int lightintensity = 0;
// char numbers[] = {'one','two','three','four','five','six','seven','eight','nine','ten'};
String tostr[] = {"Zero","one","two","three","four","five","six","seven","eight","nine","0","1","2","3","4","5","6","7","8","9"};
char number[] = {'1','2','3','4','5','6','7','8','9'};
String val;
String message = "";
 int g = 0;
 
static inline char xyz;
int buttonState1 = 0;
int buttonState2 = 0;

 static inline int testval = 0;

int convertion(char a)
{
  for(int i = 0;i<strlength;i++){
    if (i<=9 && number[i] == a)
    {
      return i;
    }
    
  }
}

void personout()
{
  lightintensity = testval;
  testval = 12;
  int currenttime = millis();
  if(currenttime>personoutTime)testval=0;
  Serial.println("person out");
  
}
 void personin()
 {
  testval = lightintensity;
  Serial.println("person in");
 }
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  
  Serial.println("Welcome to Home");
  digitalWrite(13,LOW);
  pinMode(buttonPin1, INPUT);

  
}

void loop() {
  message = ""; 
  while (Serial.available()) {
    xyz = char(Serial.read());
    message += xyz;
  }
  
  if(xyz >= 1)
  {
    char z = xyz;
    testval = z;
     testval = map(testval-48,0,9,0,240);
    
    
    
    Serial.println(message);
    
  }
    
    if(message == "turn on")
    {
      digitalWrite(13,HIGH);
     // delay(100);
}
else if(message == "turn off")
  {
    testval = 0;
    digitalWrite(13,LOW);
     // delay(100);
  }
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  // person out test
  if (buttonState1 == HIGH) {
    if(buttonState2 == HIGH){

   
   personout();
  } 
  }
  if (buttonState2 == HIGH) {
    if(buttonState1 == HIGH){

   
   personin();
  } 
  }

   Serial.print("test val = ");
    Serial.println(testval);
    analogWrite(9,testval);
  
 // delay(500);

}
