#include <analogWrite.h>


int channel1 = 14;
int channel2 = 27;
int channel3 = 26;
int channel4 = 25;
int channel5 = 33;
int channel6 = 32;

int frontLeftE = 23;
int frontLeft1 = 22;
int frontLeft2 = 18;

int backLeftE = 19;
int backLeft1 = 21;
int backLeft2 = 3;

int backRightE = 5;
int backRight1 = 17;
int backRight2 = 16;

int frontRightE = 2;
int frontRight1 = 0;
int frontRight2 = 4;


void setup() 
{
    Serial.begin(115200);

  // put your setup code here, to run once:
  pinMode(channel1, INPUT);
  pinMode(channel2, INPUT);
  pinMode(channel3, INPUT);
  pinMode(channel4, INPUT);
  pinMode(channel5, INPUT);
  pinMode(channel6, INPUT);

  pinMode( frontRightE, OUTPUT);
  pinMode( frontRight1, OUTPUT);
  pinMode( frontRight2, OUTPUT);
  
  pinMode( backRightE, OUTPUT);
  pinMode( backRight1, OUTPUT);
  pinMode( backRight2, OUTPUT);
  
  pinMode( frontLeftE, OUTPUT);
  pinMode( frontLeft1, OUTPUT);
  pinMode( frontLeft2, OUTPUT);
  
  pinMode( backLeftE, OUTPUT);
  pinMode( backLeft1, OUTPUT);
  pinMode( backLeft2, OUTPUT);
}

void loop() 
{

  int c1 = pulseIn(channel1, HIGH); //Right console. left-right 1000-2000
  int c2 = pulseIn(channel2, HIGH); //Right console. up-down 1000-2000
  int c3 = pulseIn(channel3, HIGH); //Left console. up-down 1000-2000
  int c4 = pulseIn(channel4, HIGH); //Left console. left-rught 1000-2000
  int c5 = pulseIn(channel5, HIGH); //Left dial button. 1000-2000
  int c6 = pulseIn(channel6, HIGH); //Right dial button. 1000-2000

  Serial.print("a: ");

  Serial.print(c1);
  Serial.print(" ");
  Serial.print(c2);
  Serial.print(" ");
  Serial.print(c3);
  Serial.print(" ");
  Serial.print(c4);
  Serial.print(" ");
  Serial.print(c5);
  Serial.print(" ");
  Serial.print(c6);
  Serial.println(" ");

  float v = fabs((c3 - 1500) / 500.0 * 255);

  Serial.print(" v:");
  Serial.print(v);


  //moving forward
  if (c3 > 1600)
  {
    digitalWrite(frontLeft1, HIGH);
    digitalWrite(frontLeft1, HIGH);
    digitalWrite(frontRight1, HIGH);
    digitalWrite(backLeft1, HIGH);
    digitalWrite(backRight1, HIGH);

    digitalWrite(frontLeft2, LOW);
    digitalWrite(frontLeft2, LOW);
    digitalWrite(frontRight2, LOW);
    digitalWrite(backLeft2, LOW);
    digitalWrite(backRight2, LOW);
  }
  else
  if (c3 < 1400)
  {
    digitalWrite(frontLeft1, LOW);
    digitalWrite(frontRight1, LOW);
    digitalWrite(backLeft1, LOW);
    digitalWrite(backRight1, LOW);
  
    digitalWrite(frontLeft2, HIGH);
    digitalWrite(frontRight2, HIGH);
    digitalWrite(backLeft2, HIGH);
    digitalWrite(backRight2, HIGH);
  }
  else
  {
    digitalWrite(frontLeft1, LOW);
    digitalWrite(frontRight1, LOW);
    digitalWrite(backLeft1, LOW);
    digitalWrite(backRight1, LOW);
  
    digitalWrite(frontLeft2, LOW);
    digitalWrite(frontRight2, LOW);
    digitalWrite(backLeft2, LOW);
    digitalWrite(backRight2, LOW);
  }   

  if (c4 < 1300)
  {    
    analogWrite(frontLeftE, v);
    analogWrite(backLeftE, v); 
    analogWrite(frontRightE, 0);
    analogWrite(backRightE, 0);   
  }
  else
  if (c4 > 1700)
  {
    analogWrite(frontLeftE, 0);
    analogWrite(backLeftE, 0); 
    analogWrite(frontRightE, v);
    analogWrite(backRightE, v);
  }
  else
  {
    analogWrite(frontLeftE,  v);
    analogWrite(backLeftE,   v);  
    analogWrite(frontRightE, v);
    analogWrite(backRightE,  v);    
  }
  
  
  Serial.println(" ");
}
