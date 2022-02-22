#define strlength 20
// char numbers[] = {'one','two','three','four','five','six','seven','eight','nine','ten'};
String tostr[] = {"Zero","one","two","three","four","five","six","seven","eight","nine","0","1","2","3","4","5","6","7","8","9"};
char number[] = {'1','2','3','4','5','6','7','8','9'};
String val;
String message = "";
 int g = 0;
static inline char xyz;

int convertion(char a)
{
  for(int i = 0;i<strlength;i++){
    if (i<=9 && number[i] == a)
    {
      return i;
    }
    
  }
}

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  Serial.println("Goodnight moon!");
  digitalWrite(13,LOW);

  
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
    int testval = z;
     testval = map(testval-48,0,9,0,240);
    
    
    Serial.print("test val = ");
    Serial.println(testval);
    analogWrite(9,testval);
    Serial.println(message);
    
  }
    
    if(message == "turn on")
    {
      digitalWrite(13,HIGH);
      delay(100);
}
if(message == "turn off")
  {
    digitalWrite(13,LOW);
      delay(100);
  }
   
  
  delay(500);

}
