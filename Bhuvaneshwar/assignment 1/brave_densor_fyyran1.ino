// C++ code
//
void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(5, OUTPUT);
  
}

void loop()
{
  int motion=digitalRead(2);//pir sensor is to measure the motion
  Serial.print("position is:");
  Serial.println(motion);
if (motion==1)
{tone(5,200);}
else
{noTone(5);}
 
  double data = analogRead(A2);
  double n=data/1024;//since ADC 
  //Serial.print("converted analog data :");
  //Serial.println(n);
  double volt=n*5;//because its connected to 5v
  //Serial.print("voltage data :");
  //Serial.println(volt);
  double off=volt-0.5;//the constsnt off set value of tmp sensor is 0.5,hence we use this to show the negative values too.
  //Serial.print("offset value :");
  //Serial.println(off);
  double temp=off*100;//to get a perfect temp value.
  Serial.print("temp value :");
  Serial.println(temp);
if(temp>60)
{tone(5,600);}
else
{noTone(5);}
}