String val;
int pin = A1;
int led = D7;

void setup() {
    pinMode(pin, INPUT);
    pinMode(led, OUTPUT);
}

void loop() {
    
    digitalWrite(led, HIGH);
    val = String(analogRead(pin));
    
    Particle.publish("Distance", val, PRIVATE);
    
    delay(1000);
    
    digitalWrite(led, LOW);
    
    delay(29000);
}