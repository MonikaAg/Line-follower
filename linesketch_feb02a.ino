`int sen_min=1023;
int sen_max=0;
int sensorPin1=A0;
int sensorPin2=A1;
int sensorPin3=A2;
int sen_avg1,sen_avg2,sen_avg3;
int i;
int reading1,reading2,reading3;
void calib() 
{
  for(i=0;i<1000;i++)
  {
    reading1=analogRead(sensorPin1);
    reading2=analogRead(sensorPin2);
    reading3=analogRead(sensorPin3);
    if(reading1<sen_min1&&reading2<sen_min2&&reading3<sen_min3)
    {
      sen_min1=reading1;
      sen_min2=reading2;
      sen_min3=reading3;
      
    }
    else if(reading1>sen_max1&&reading2>sen_max2&&reading3>sen_max3)
    {
      sen_max1=reading1;
      sen_max2=reading2;
      sen_max3=reading3;
    }
    delay(5);
  }
    sen_avg1=(sen_min1+sen_max1)/2;
    sen_avg2=(sen_min2+sen_max2)/2;
    sen_avg3=(sen_min3+sen_max3)/2;
    
void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin,INPUT);
  calib();
  Serial.print(sen_min);
  Serial.print(" ");
  Serial.print(sen_max);
  Serial.print(" ");
  Serial.print(sen_avg);
  Serial.print(" ");
  Serial.println();
}
int a;
void loop()
{
  a=analogRead(sensorPin1);
  if(a>sen_avg1)
  {
    Serial.println("Black");
    x=0;
  }
    else
    {
    Serial.println("White");
    x=1;
    }
  b=analogRead(sensorPin2);
  if(a>sen_avg2)
  {
    Serial.println("Black");
    y=0;
  }
    else
    {
    Serial.println("White");
    y=1;
    }
  c=analogRead(sensorPin3);
  if(c>sen_avg3)
  {
    Serial.println("Black");
    z=0;
  }
    else
    {
    Serial.println("White");
    z=1;
    }
if(x==0&&y==1&&z==0)
{                            /// go straight
  digitalWrite(2,LOW);
analogWrite(3,255);
  digitalWrite(4,HIGH);
  analogWrite(5,0);
    
}

if(x==1&&y==0&&z==0)
{                            /// go left
  digitalWrite(2,LOW);
analogWrite(3,100);
  digitalWrite(4,HIGH);
  analogWrite(5,0);
    
}



}



