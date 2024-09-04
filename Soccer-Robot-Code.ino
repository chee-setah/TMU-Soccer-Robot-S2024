int leftMotor1=4;
int leftMotor2=5;
int rightMotor1=6;
int rightMotor2=7;
char t;
 
void setup() {
pinMode(leftMotor1,OUTPUT);   //left motors  forward
pinMode(leftMotor2,OUTPUT);   //left motors reverse
pinMode(rightMotor1,OUTPUT);   //right  motors forward
pinMode(rightMotor2,OUTPUT);   //right motors reverse

Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move  forward(all motors rotate in forward direction)
  digitalWrite(leftMotor1,HIGH);
  digitalWrite(leftMotor2,LOW);
  
  digitalWrite(rightMotor1,HIGH);
  digitalWrite(rightMotor2,LOW);
}
else if(t == 'B'){      //move reverse (all  motors rotate in reverse direction)
  digitalWrite(leftMotor1,LOW);
  digitalWrite(leftMotor2,HIGH);
  
  digitalWrite(rightMotor1,LOW);
  digitalWrite(rightMotor2,HIGH);
}
  
else if(t == 'L'){      //turn right (left side motors rotate in forward direction,  right side motors doesn't rotate)
  digitalWrite(leftMotor1,HIGH);
  digitalWrite(leftMotor2,LOW);
  
  digitalWrite(rightMotor1,LOW);
  digitalWrite(rightMotor2,LOW);
}
 
else  if(t == 'R'){      //turn left (right side motors rotate in forward direction, left  side motors doesn't rotate)
  digitalWrite(leftMotor1,LOW);
  digitalWrite(leftMotor2,LOW);
  
  digitalWrite(rightMotor1,HIGH);
  digitalWrite(rightMotor2,LOW);
}

 
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(leftMotor1,LOW);
  digitalWrite(leftMotor2,LOW);
  digitalWrite(rightMotor1,LOW);
  digitalWrite(rightMotor2,LOW);
}
}
