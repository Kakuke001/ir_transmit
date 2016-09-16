#define DELAY_TIME 208
#define ENTER_VALUE 0xA
int calc_func_time;
int delaytime;
#define pull_down 11
#define phototrans A0
#define LED 10
int brightvalue;
int darkvalue;
 static int max_val;
  static int min_val; 
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(4800);
  pinMode(LED,OUTPUT);
  pinMode(pull_down,OUTPUT);                   //tx
  pinMode(phototrans,INPUT);                  //rx
  digitalWrite(LED,LOW);
  
  max_val= brightvalue;
  min_val = darkvalue; 
}
void transmit_ir(uint8_t data)
  {
  digitalWrite(10,LOW);
    delayMicroseconds(DELAY_TIME);
    
    for(int i = 0; i<8;i++)
    {
      if(((data>>i)& 0x01)==0)
      {
        digitalWrite(10,LOW);
        
      }
      else
      {
        digitalWrite(10,HIGH);
        
      }
      delayMicroseconds(DELAY_TIME);
    }
    digitalWrite(10,HIGH);
     
  }

void loop()
{ 
 digitalWrite(10,HIGH);
    int value = Serial.read();
    
    if(value > 0 )
    {
    transmit_ir(value);
    }

  
}
