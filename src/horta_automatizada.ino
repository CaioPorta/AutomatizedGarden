#define motor 8 //pino do motor
#define led 9 //pino do led
#define SH 5 //pino do sensor de umidade
unsigned long hr12 = 43200000; //tempo de 12horas 
unsigned long hr3 = 10800000; //3 horas
unsigned long antes=0; //grava o tempo anterior
unsigned long agora; //grava o tempo atual
unsigned long Y; //variavel auxiliar
unsigned long regou=0; //grava ultima regada
bool seco(); //função pra medir a umidade
int nivel();
int N;
bool x;

void setup() 
{
  pinMode(motor, OUTPUT);
  digitalWrite(motor, LOW);
  pinMode(led, OUTPUT);
  pinMode(SH, INPUT);
  //Serial.begin(9600);
  //Serial.println("Inicio");
  for(int i=0; i<3; i++){digitalWrite(led, HIGH);delay(300);digitalWrite(led, LOW);delay(100);}  
  //if(nivel()<80)
   // { 
      //do
      //{
        //Serial.println("Seco?");
        digitalWrite(motor, HIGH); //mantém ligado até o solo ficar umido
        digitalWrite(led, HIGH); //aqui também
        regou = millis(); 
        delay(10000);
    //  }while(seco());
   // }         
  digitalWrite(motor, LOW); //desliga motor
  digitalWrite(led, LOW); //desliga led
    x=true;
} 

void loop() 
{
  agora = millis();
  /*Serial.print("Tempo desde a ultima regada: ");
  Serial.println(agora-regou);
  Serial.print("agora - antes = ");
  Serial.println(agora-antes);*/
  if(agora - antes >= hr12) 
  {
    /*do
    {
      //Serial.println("StandBy");
      Y = millis();
      digitalWrite(led, HIGH);delay(100);digitalWrite(led, LOW);delay(100);
    }while(nivel() >= 80 && Y - agora <= hr3);*/
   // if(nivel()<80)
   // { 
    //  do
    //  {
        //Serial.println("Seco?");
        digitalWrite(motor, HIGH); //mantém ligado até o solo ficar umido
        digitalWrite(led, HIGH); //aqui também
        regou = millis(); 
        delay(10000);
   //   }while(seco());
  //  }    
    x=true;
  }  
  digitalWrite(motor, LOW); //desliga motor
  digitalWrite(led, LOW); //desliga led
  /*int aux=nivel();
  if(aux>90){digitalWrite(led, HIGH); delay(100); digitalWrite(led, LOW); delay(10000);}
  else if(aux>80){digitalWrite(led, HIGH); delay(100); digitalWrite(led, LOW); delay(7000);}
  else if(aux>70){digitalWrite(led, HIGH); delay(200); digitalWrite(led, LOW); delay(4000);}
  else if(aux>50){digitalWrite(led, HIGH); delay(200); digitalWrite(led, LOW); delay(1000);}
  else {digitalWrite(led, HIGH); delay(1500); digitalWrite(led, LOW); delay(1000);}*/
  if(x){x=false; /*Serial.println("Zerou o relogio");*/ antes=agora; /*Serial.println(agora-antes);*/}
  /*/Serial.println("Fim do loop");
  //Serial.print("Tempo total: ");
  //Serial.println(millis());
  */
  digitalWrite(led, HIGH); delay(150); digitalWrite(led, LOW); delay(10000);
}

bool seco() //faz leitura da umidade
{
  //if(nivel() > 90)return false; //se ja está umido, desligar
  //else return true; //senão manter ligado
  return false;
}

int nivel() //mede o nivel de umidade do solo
{
  //int X;
 // X = analogRead(SH);
//  X = map(X, 1023, 0, 0, 200);
  //Serial.print("Umidade atual = ");
  //Serial.println(X);
  return 0;
}
