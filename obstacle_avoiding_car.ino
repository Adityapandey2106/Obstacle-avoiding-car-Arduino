int mr1=3;
int mr2=5;
int ml1=6;
int ml2=11;
int trig=9;
int echo=10;
long d , cm ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(mr1,OUTPUT);
  pinMode(mr2,OUTPUT);
  pinMode(ml1,OUTPUT);
  pinMode(ml2,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,LOW);
  d=pulseIn(echo,HIGH);
  cm=(d/2)/29.1;
  Serial.println(cm);
  if (cm<50 && cm!=0){
    stopr();
    delay(800);
    moveB();
    turnR();
    delay(1000);
  }
  else{
    moveF();
  }
}
void moveF(){
  analogWrite(mr1,0);
  analogWrite(mr2,255);
  analogWrite(ml1,0);
  analogWrite(ml2,255);
}
void moveB(){
  analogWrite(mr1,255);
  analogWrite(mr2,0);
  analogWrite(ml1,255);
  analogWrite(ml2,0);
}
void turnL(){
  analogWrite(mr1,0);
  analogWrite(mr2,255);
  analogWrite(ml1,255);
  analogWrite(ml2,0);
}
void turnR(){
  analogWrite(mr1,255);
  analogWrite(mr2,0);
  analogWrite(ml1,0);
  analogWrite(ml2,255);
}
void stopr(){
  analogWrite(mr1,0);
  analogWrite(mr2,0);
  analogWrite(ml1,0);
  analogWrite(ml2,0);
}
