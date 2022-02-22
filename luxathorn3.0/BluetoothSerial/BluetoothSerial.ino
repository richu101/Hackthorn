#define strlength 20
// char numbers[] = {'one','two','three','four','five','six','seven','eight','nine','ten'};
String tostr[] = {"Zero","one","two","three","four","five","six","seven","eight","nine","0","1","2","3","4","5","6","7","8","9"};
char f = ['1','2','3','4','5','6','7','8','9'];
String val;
String message = "";
 int g = 0;

int convertion(String a)
{
  for(int i = 0;i<strlength;i++){
    if (i<=9 && tostr[i] == a)
    {
      return i;
    }
    else if(i>=10 && tostr[i] == a)
    {
      return i-9;
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
    message += char(Serial.read());
  }
  if(sizeof(message))
  {
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
