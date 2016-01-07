int analogPin= 0;
int raw= 0;
int Vin= 5;
float T;
float Vout= 0;
float R1= 100;
float R2= 0;
float buffer= 0;
// codice da http://www.circuitbasics.com/arduino-ohm-meter/
//un grado centigrado ogni 0.384 ohm
//Rt = R0 * (1 + A* t + B*t2 + C*(t-100)* t3)     eq di linearizzazione
//A= 3.9083 E–3
//B = –5.775 E–7
//C = –4.183 E–12 (below 0 °C), or
//C = 0 (above 0 °C)
// il gruppo da 3 pt100 dà 87.20 ohm a zero gradi con ghiaccio fondente
void setup()
{
Serial.begin(9600);
}

void loop()
{
raw= analogRead(analogPin);
if(raw) 
{
buffer= raw * Vin;
Vout= (buffer)/1024.0;
buffer= (Vin/Vout) -1;
R2= R1 * buffer;
//Serial.println("Vout: ");
//Serial.println(Vout);
//Serial.print("R2: ");
//Serial.print(R2);
//Serial.println("T= ");
Serial.println((R2-87.20)/0.384+0.88);
T= (R2-87.20)/0.384+0.88;
//0.88 aggiunto a posteriori
//Serial.println(" °C");
delay(1500);
}
}
