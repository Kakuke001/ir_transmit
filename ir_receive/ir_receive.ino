#define DELAY_TIME 208
#define HALFTIME DELAY_TIME*1.5
#define ENTER_VALUE 0xA
#define test_pin 8
int calc_func_time;
int delaytime;
#define pull_down 11
#define phototrans A0
#define LED 10
int brightvalue;
int darkvalue;
int8_t rec_byte[8];
 static int max_val;
  static int min_val; 
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(4800);
  pinMode(LED,OUTPUT);
  pinMode(test_pin,OUTPUT);
  pinMode(pull_down,OUTPUT);                   //tx
  pinMode(phototrans,INPUT);                  //rx
  digitalWrite(LED,HIGH);
  read_ptrans();
  digitalWrite(pull_down, LOW);
  max_val= brightvalue;
  min_val = darkvalue; 
}
void analog_data(int data)
{
  static int x=0;
  int data_buffer[8];
  data_buffer[x]=data;
  //Serial.print("x value");
  //Serial.println(x);
  x++;
  if(x==8)
  {
    for(int z = 0; z<8;z++)
    {
    if(data_buffer[z]>1)
    {
      Serial.print("0");
    }
    else
    {
      Serial.print("1");
    }
    //Serial.println(data_buffer[z]);
    }
    x=0;
    Serial.println("");
  }
}

void read_ptrans()
{
  int analogvalue =digitalRead(phototrans);
  //Serial.println(analogvalue);
  analog_data(analogvalue);
}
void get_time(int timelast)
{
  int timenow=micros();
  if (timenow-timelast>=DELAY_TIME)
  {
  read_ptrans();
  }
  else
  {
    get_time(timelast);
  }
}

void loop()
{ 
 
 int analogval = digitalRead(phototrans);
 
 //Serial.println(analogval);

if ( analogval == 1)
{
  delayMicroseconds(HALFTIME);
  for(int x = 0; x<8;x++)
  {
  int timenow=micros();
  digitalWrite(test_pin,HIGH);
  digitalWrite(test_pin,LOW);
  get_time(timenow);
  }
}
}
