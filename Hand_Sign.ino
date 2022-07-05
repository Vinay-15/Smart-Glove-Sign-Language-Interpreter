const int flexPin1 = A0; 
const int flexPin2 = A1;
const int flexPin3 = A2; 
const int flexPin4 = A5; 

int value, i;
int initialSum1=0, sum1;
int initialSum2=0, sum2;
int initialSum3=0, sum3;
int initialSum4=0, sum4;
String a,b,c,d;

void setup()
{
  pinMode(flexPin1, INPUT);
  pinMode(flexPin2, INPUT);
  pinMode(flexPin3, INPUT);
  pinMode(flexPin4, INPUT);
  Serial.begin(9600);   
  for(i=0; i<10; ++i)
  {
    value=analogRead(flexPin1);
    initialSum1 += value;
    Serial.println(initialSum1);
    value=analogRead(flexPin2);
    initialSum2 += value;
        Serial.println(initialSum2);
    value=analogRead(flexPin3);
    initialSum3 += value;
        Serial.println(initialSum3);
    value=analogRead(flexPin4);
    initialSum4 += value;
        Serial.println(initialSum4);
  }
  Serial.println("Done");
}

void loop()
{
  sum1=sum2=sum3=sum4=0;
  a=b=c=d="1";
  for(i=0; i<10; ++i) 
  {
    value = analogRead(flexPin1);
    sum1 += value;
    Serial.println(sum1);
    value = analogRead(flexPin2);
    sum2 += value;
        Serial.println(sum2);
    value = analogRead(flexPin3);
    sum3 += value;
        Serial.println(sum3);
    value = analogRead(flexPin4);
    sum4 += value;
        Serial.println(sum4);
  }
  delay(125);
  if ( (sum1-initialSum1)>150 )
    a="0";
  if ( (sum2-initialSum2)>30 )
    b="0";
  if ( (sum3-initialSum3)>30 )
    c="0";
  if ( (sum4-initialSum4)>30 )
    d="0";

  String s=a+b+c+d;
  Serial.println(s);
  if(s=="1111")
    Serial.write("HELLO\n");
  else if(s=="0001")
    Serial.write("NO\n");
  else if(s=="0010")
    Serial.write("GLAD\n"); 
  else if(s=="0011")
    Serial.write("NAME\n");
  else if(s=="0100")
    Serial.write("IS\n");
  else if(s=="0101")
    Serial.write("WHY\n");
  else if(s=="0110")
    Serial.write("WHERE\n");
  else if(s=="0111")
    Serial.write("OK\n");
  else if(s=="1000")
    Serial.write("YES\n");
  else if(s=="1001")
    Serial.write("COOL\n");
  else if(s=="1010")
    Serial.write("WHO\n");
  else if(s=="1011")
    Serial.write("NICE\n");
  else if(s=="1100")
    Serial.write("THANK YOU\n");
  else if(s=="1101")
    Serial.write("YOU\n");
  else if(s=="1110")
    Serial.write("WHAT\n");
  else if(s=="0000")
    Serial.write("HOW\n");
    delay(5000);
}
