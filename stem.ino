int ena =6; // pin that l298n connected to (can be change depened on pin connected)
int enb = 7;
int in1 =2;
int in2 = 3;
int lightsensor,rainsensor,check0,check1;
int check[] = {check0,check1};
void motorstop()// motor function
{
  digitalWrite(in1,LOW);// change from 0 volt to 5 volt
  digitalWrite(in2,LOW);
}
void motorrundown()
{
   digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(ena,255);//motor speed that connect in enable a pin
  delay(10000);// run time in millisecond
}
void motorrunup()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ena,255);// motor speed
  delay(10000);
}
void setup() {
 Serial.begin(9600);
 rainsensor= analogRead(A0);
lightsensor =analogRead(A1);
if(rainsensor <=470 && lightsensor >= 870)
{check0=1; motorrundown(); }
else if (rainsensor <= 470 && lightsensor <500 )
{check0=1; motorrundown(); }
else if (rainsensor >=470 && lightsensor >=870)
{check0=1; motorrundown();}
else 
{check0=0;}   
 pinMode(in1,OUTPUT);// it return to be output
 pinMode(in2,OUTPUT);
 pinMode(ena,OUTPUT);
}
void loop() {
 rainsensor= analogRead(A0);
lightsensor =analogRead(A1);
if(rainsensor <=470 && lightsensor >= 870)
{ check1 = 1;// rain and dark
}else if (rainsensor <= 470 && lightsensor <500 )
{
  check1 = 1;
  }else if (rainsensor >=470 && lightsensor >=870)
  {
    check1 = 1; // not rain dark
  }
else 
{
 check1 = 0; // not rain and sun
}  
  if(check0==check1)
  {
  motorstop();
  }else
  {
    if(check1==1)
    {
      motorrundown();
    }if(check1==0)
    {
      motorrunup();
    }
  }
  check0 = check1;
  delay(1000);
  }
