
Fedi, date d’envoi : Aujourd’hui, à 19:41
int buzzer = 7;
int redpin = 11; //select the pin for the red LED
int bluepin =10; // select the pin for the  blue LED
int greenpin =9;// select the pin for the green LED
 

const int mqxPin = A0;  // La sortie analogique du détecteur MQx est reliée au Pin analogique A0 de l'Arduino

void setup()
{
      pinMode(buzzer, OUTPUT);
    pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);

    Serial.begin(9600); // Initialise le port série à 9600 bps // 
}

void loop()
{


    //Serial.println(analogRead(mqxPin));
          // Imprime une mesure chaque seconde
    if((analogRead(mqxPin)) > 650 )
  {
    digitalWrite(buzzer, HIGH);
   Serial.println("1");
   analogWrite(11, 0);
   analogWrite(10, 255);
   analogWrite(9, 0);
   delay(1000); 
  }
  else if(((analogRead(mqxPin)) < 650) && ((analogRead(mqxPin)) > 550) )
  {
   digitalWrite(buzzer, HIGH);
   Serial.println("2");
   analogWrite(11, 0);
   analogWrite(10, 255);
   analogWrite(9, 255);
   delay(1000); 
  }
else if((analogRead(mqxPin)) < 550 )
  {
   digitalWrite(buzzer, LOW);
   Serial.println("3");
   analogWrite(11, 0);
   analogWrite(10, 0);
   analogWrite(9, 255);
   delay(1000); 
  }
    if(Serial.available())
{
  int a = Serial.read();
if(a == '4' )
{
   digitalWrite(buzzer, LOW);
   delay(500);
  
}
}
}
