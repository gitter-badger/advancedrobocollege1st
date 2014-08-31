int led=9;
int brightness=0;
int fadeamount=10;

void setup(){
  
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  
}

void loop(){
  
  analogWrite(led,brightness);
  
  brightness=brightness+fadeamount;
  
  if(brightness==0|brightness==200){
    fadeamount=-fadeamount;
  }
  
  Serial.println(brightness);
  
  delay(30);
  
}
