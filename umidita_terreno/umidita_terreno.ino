int soil=0;
//String soill="";

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  sensorValue = constrain(sensorValue, 485, 1023);
  // print out the value you read:
  //Serial.println(sensorValue);

  //map the value to a percentage
  soil = map(sensorValue, 485, 1023, 100, 0);
  
  // print out the soil water percentage you calculated:
  Serial.print(soil);
  Serial.println("%");
  //soill = atoi(soil);
  //Spark.variable("umid", &soil, INT);
  //Spark.publish("Umidita %",soill,60,PRIVATE);


  delay(3000);        // delay in between reads for stability
}
