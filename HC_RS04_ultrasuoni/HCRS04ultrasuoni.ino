//HC RS04 Sensore ultrasuoni
int triggerPort = 7;
int echoPort = 8;
 
void setup() {
 
pinMode( triggerPort, OUTPUT );
pinMode( echoPort, INPUT );
Serial.begin( 9600 );
Serial.println( "Sensore ultrasuoni: ");
 
}
 
void loop() {
//porta bassa l'uscita del trigger
digitalWrite( triggerPort, LOW );
 
//invia un impulso di 10microsec su trigger
delayMicroseconds (10)
digitalWrite( triggerPort, HIGH );
delayMicroseconds( 10 );
digitalWrite( triggerPort, LOW );
 
long duration = pulseIn( echoPort, HIGH );
 
long r = 0.034 * duration / 2;
 
Serial.print( "durata: " );
Serial.print( duration );
Serial.print( " , " );
Serial.print( "distanza: " );
 
//dopo 38ms è fuori dalla portata del sensore
if( duration > 38000 ) Serial.println( "fuori portata");
else { Serial.print( r ); Serial.println( "cm" );}
 
//aspetta 1.5 secondi
delay( 1500 );
}
