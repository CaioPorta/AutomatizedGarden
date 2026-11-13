#define motor 8 //motor pin
#define led 9 //LED pin
#define SH 5 //humidity sensor pin
unsigned long hr12 = 43200000; //12 hours in ms
unsigned long hr3 = 10800000; //3 hours in ms
unsigned long lastCheck = 0; //stores previous check time
unsigned long now; //stores current time
unsigned long elapsed; //auxiliary variable
unsigned long lastWatered = 0; //stores last watering time
bool isDry(); //function to check if soil is dry
int moistureLevel();
int N;
bool timerReset;

void setup() 
{
  pinMode(motor, OUTPUT);
  digitalWrite(motor, LOW);
  pinMode(led, OUTPUT);
  pinMode(SH, INPUT);
  //Serial.begin(9600);
  //Serial.println("Start");
  for(int i=0; i<3; i++){digitalWrite(led, HIGH);delay(300);digitalWrite(led, LOW);delay(100);}  
  //if(moistureLevel()<80)
   // { 
      //do
      //{
        //Serial.println("Dry?");
        digitalWrite(motor, HIGH); //keeps motor on until soil is moist
        digitalWrite(led, HIGH); //same here
        lastWatered = millis(); 
        delay(10000);
    //  }while(isDry());
   // }         
  digitalWrite(motor, LOW); //turns off motor
  digitalWrite(led, LOW); //turns off LED
    timerReset=true;
} 

void loop() 
{
  now = millis();
  /*Serial.print("Time since last watering: ");
  Serial.println(now-lastWatered);
  Serial.print("now - lastCheck = ");
  Serial.println(now-lastCheck);*/
  if(now - lastCheck >= hr12) 
  {
    /*do
    {
      //Serial.println("StandBy");
      elapsed = millis();
      digitalWrite(led, HIGH);delay(100);digitalWrite(led, LOW);delay(100);
    }while(moistureLevel() >= 80 && elapsed - now <= hr3);*/
   // if(moistureLevel()<80)
   // { 
    //  do
    //  {
        //Serial.println("Dry?");
        digitalWrite(motor, HIGH); //keeps motor on until soil is moist
        digitalWrite(led, HIGH); //same here
        lastWatered = millis(); 
        delay(10000);
   //   }while(isDry());
   //  }    
    timerReset=true;
  }  
  digitalWrite(motor, LOW); //turns off motor
  digitalWrite(led, LOW); //turns off LED
  /*int aux=moistureLevel();
  if(aux>90){digitalWrite(led, HIGH); delay(100); digitalWrite(led, LOW); delay(10000);}
  else if(aux>80){digitalWrite(led, HIGH); delay(100); digitalWrite(led, LOW); delay(7000);}
  else if(aux>70){digitalWrite(led, HIGH); delay(200); digitalWrite(led, LOW); delay(4000);}
  else if(aux>50){digitalWrite(led, HIGH); delay(200); digitalWrite(led, LOW); delay(1000);}
  else {digitalWrite(led, HIGH); delay(1500); digitalWrite(led, LOW); delay(1000);}*/
  if(timerReset){timerReset=false; /*Serial.println("Clock reset");*/ lastCheck=now; /*Serial.println(now-lastCheck);*/}
  /*/Serial.println("End of loop");
  //Serial.print("Total time: ");
  //Serial.println(millis());
  */
  digitalWrite(led, HIGH); delay(150); digitalWrite(led, LOW); delay(10000);
}

bool isDry() //reads humidity level
{
  //if(moistureLevel() > 90)return false; //if already moist, turn off
  //else return true; //otherwise keep on
  return false;
}

int moistureLevel() //measures soil moisture level
{
  //int X;
 // X = analogRead(SH);
//  X = map(X, 1023, 0, 0, 200);
  //Serial.print("Current moisture = ");
  //Serial.println(X);
  return 0;
}
