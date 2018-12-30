int load = 9; // choose the pin for load coil
int generator = 12; // choose the pin for generator coil
int transValve = 11; // choose the pin for transfer valve
int starter = 10; // choose the pin for starter coil

int cityPower = 7;   // choose the input pin (for a pushbutton)
int val = 0;     // variable for reading the pin status

void setup() {
  pinMode(load, OUTPUT);  
  pinMode(generator, OUTPUT);  
  pinMode(transValve, OUTPUT);  
  pinMode(starter, OUTPUT);
  pinMode(cityPower, INPUT);

   val = digitalRead(cityPower);
  if (val == HIGH) {         //If the city power is there
    delay(2000);
    digitalWrite(generator,HIGH);
    delay(2000);
    digitalWrite(load,HIGH);
  } 
  while (digitalRead(cityPower) == HIGH) {
  }
  
}

void loop(){
  val = digitalRead(cityPower);  // read input value
  if (val == LOW) {         //If the city power is not there
    digitalWrite(generator,LOW);
    delay(2000);
    digitalWrite(load,LOW);
    delay(2000);            //wait 2 seconds
    digitalWrite(starter,HIGH);
    digitalWrite(transValve,HIGH);
    delay(3000);
    digitalWrite(starter,LOW);
    delay(5000);
    digitalWrite(load,HIGH);
  } 
  while (digitalRead(cityPower) == LOW) {
  }
  
  val = digitalRead(cityPower);
  if (val == HIGH) {         //If the city power is not there
    delay(2000);            //wait 2 seconds
    digitalWrite(load,LOW);
    delay(2000);
    digitalWrite(transValve,LOW);
    delay(5000);
    digitalWrite(generator,HIGH);
    delay(2000);
    digitalWrite(load,HIGH);
  } 
  while (digitalRead(cityPower) == HIGH) {
  }
}
