#include <SPI.h>



const int slaveSelectPin = 10;                                               // set pin 10 as the slave select for the digital pot:
const int analoginput=A2;
const int value;
  int x;


byte command_byte[1]= {1};


void setup() 
{
  // set the slaveSelectPin as an output:
  pinMode(slaveSelectPin, OUTPUT);
  pinMode(A2, INPUT);
  //pinMode(9,OUTPUT);
  Serial.begin(9600);
  // initialize SPI:
  SPI.begin();
}

void loop() 
{

   
    int binval= analogRead(A2);
   // analogWrite(9,binval);
    //Serial.println(binval);
   
  

   
    // Serial.print("BINARY VALUE IS \n");
    // Serial.println(binval,BIN);
     
    delay(1);

    digitalWrite(slaveSelectPin, LOW);
    SPI.transfer(command_byte[0]); 
     //Serial.print(command_byte[0]);
     
      
      
  displaybinary(binval);
 
  digitalWrite(slaveSelectPin,HIGH); 
   

 }
  

void displaybinary(int current)
{
      
  double voltage = 5 * current / 255.0;
 
    double temp;
    temp = (double)current / 1023.0;
    current = temp * 255;
  //  int test_digital = (int) current;
   // unsigned short finalval= ((unsigned short)current) | (0x1<<8);
    SPI.transfer(current);
    Serial.println (current);
      
}


