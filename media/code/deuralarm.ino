/*
HC-SR04 Deur alarm op een breadboard]

Allereerst koppel je de VCC en GND van de fabschoolino aan de + en - op het breadboardje
VCC arduino naar breadboard + baan; GND fabschoolino naar breadboard - baan

Prik de Ultrasone sensor (de HC-SR04) in het breadboardje en zorg dat de VCC en GnD 
verbonden zijn met de + en - baantjes.

Verbind de volgende componenten aan de fabschoolino:
- Speaker/Boxje: rode draadje aan pin 8, de ander aan het - baantje 
- led: lange poot aan pin 11 (vergeet niet er een weertand tussen te plaatsen 
    korte poot aan de -
- HC-SR04: De volgende pinnen van de sensor koppel je aan de fabschoolino:
    Trigger pin 12 
    Echo  pin 13 

Meer info: http://fabschoolino.waag.org
Code and dutch comments for use with the fabschoolino by Henk http://fabschoolino.waag.org
*/

#include <NewTone.h> //extra bibliotheek met meer geluiden

/* geef aan welke pinnen waarvoor gebruikt worden */
#define trigPin 13
#define echoPin 12
#define ledPin  11
#define ALARM 8
    float sinVal;
    int toneVal;

/* geef aan welke pinnen in- danwel output pinnen zijn*/
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ALARM, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

/* hier begint het programma */
void loop() {

/* bereken de afstand tot een object voor de ultrasone sensor */  
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); /* als de ping ontvangen wordt, */
  distance = (duration/2) / 29.1; /* wordt hier de afstand bepaald */

/* als de afstand groter is dan 40cm doe dan niets */
  if (distance >= 40 || distance <= 0){
    Serial.println("no object detected");
    noNewTone();
    digitalWrite(ledPin,LOW);
  }

/* in andere gevallen laat hier weten dat er een object gezien is */  
  else {
    Serial.println("object detected");
  alarm();
  }
  delay(300);
}

/* en hier zet je het alarm aan: dus je laat de led knipperen en stuurt een NewTone naar de speakers */
    void alarm(){   
    digitalWrite(ledPin,HIGH);
    delay(100);    
    digitalWrite(ledPin,LOW);
       for (int x=0; x<180; x++) {
        // convert degrees to radians then obtain sin value
        sinVal = (sin(x*(3.1412/180)));
        // generate a frequency from the sin value
        toneVal = 2000+(int(sinVal*1000));
        NewTone(ALARM, toneVal);

      }
    }
 
