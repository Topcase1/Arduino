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
delayMicroseconds (10);
digitalWrite( triggerPort, HIGH );
delayMicroseconds( 10 );
digitalWrite( triggerPort, LOW );
 
long duration = pulseIn( echoPort, HIGH );

long t = 22; //t in centigradi
Serial.print( t );Serial.println( " Centigradi " );

double vcm = (331.4 + 0.62 * t) / 10000; //velocità già in cm/ms per dopo
Serial.print( vcm );Serial.println( " cm/ms " );
 
double r = vcm * duration / 2; //velocità per spazio
 
Serial.print( "durata dell'impulso: " );
Serial.print( duration );
Serial.print( " , " );
Serial.print( "distanza: " );
 
//dopo 38ms è fuori dalla portata del sensore
if( duration > 400000 ) Serial.println( "fuori portata");
else { Serial.print( r ); Serial.println( "cm" );}
 
//aspetta 1.5 secondi
delay( 1500 );
}
