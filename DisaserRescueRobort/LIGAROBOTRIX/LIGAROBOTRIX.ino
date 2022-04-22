
#define LechoPin 4 
#define LtrigPin 3
#define RechoPin 5 
#define RtrigPin 6
#define FechoPin 7 
#define FtrigPin 8

int Rdistance();
int Ldistance();
int Fdistance();
void setup() {
  pinMode(RtrigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(RechoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(FtrigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(FechoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(LtrigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(LechoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed

}
void loop() {
  
int a = Ldistance();
int b = Rdistance();
int c = Fdistance();

}

 int Ldistance()
 {
  long duration; 
  int distance;
  digitalWrite(LtrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(LtrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(LtrigPin, LOW);
  duration = pulseIn(LechoPin, HIGH);
  distance = duration * 0.034 / 2; 
  return distance;
  
 }

 int Rdistance()
 {
  long duration; 
  int distance;
  digitalWrite(RtrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(RtrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(RtrigPin, LOW);
  duration = pulseIn(FechoPin, HIGH);
  distance = duration * 0.034 / 2; 
  return distance;
  
 }

int Fdistance()
 {
  long duration; 
  int distance;
  digitalWrite(FtrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(FtrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(FtrigPin, LOW);
  duration = pulseIn(FechoPin, HIGH);
  distance = duration * 0.034 / 2; 
  return distance;
  
 }
