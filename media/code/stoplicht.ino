/*
HC-SR04 Ping ping stoplicht]
VCC naar arduino 5v; GND naar arduino GND
Echo naar Arduino pin 13; Trig naar Arduino pin 12
Rode led naar Arduino pin 11
Groene led naar Arduino pin 10
1k ohm weerstand tussen LED en de GND + rail
Meer info: http://fabschoolino.waag.org
*/
/*
Original code improvements to the Ping sketch sourced from Trollmaker.com
Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
Dutch translations for use with the fabschoolino by Henk <henk@waag.org>
http://fabschoolino.waag.org/
*/

/* geef aan welke pinnen we gebruiken op de fabschoolino */

#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10

/* geef aan in welke modus de pinnen staan: INPUT/OUTPUT. De eerste regel zorgt ervoor dat
 *  de seriele port inforrmatie kan ontvangen.
 */

void setup() { //
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

/*Hier begint het daadwerkelijke programma
 * De trigPin zend een ultrasone signaal
 * de echoPin ontvangt dit signaal als het weerkaatst wordt.
 * De afstand wordt bepaald aan de hand het tijdsverschil tussen
 * zenden en ontvangen. Gedeelt door 2 (de heen en terugweg van
 * het signaal) en het getal 29.1 (dat voor deze sensor geldt).
 */

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

/* Hier wordt bepaald welke led aan en uit moet staan */
  
  if (distance < 60) {  // Als de afstand is kleiner dan < 60cm
    digitalWrite(led,HIGH); // dan rode led AAN/HIGH
  digitalWrite(led2,LOW); // groene led UIT/LOW
}
  else {
    digitalWrite(led,LOW); // Anders (dus > 60cm, rode led UIT/LOW
    digitalWrite(led2,HIGH); // groene led UIT/LOW
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance); // kijk mee mbv de seriele monitor
    Serial.println(" cm"); // onder "Hulpmiddelen/Seriele monitor
  }
  delay(500);
} /* Begin hierna opnieuw */



