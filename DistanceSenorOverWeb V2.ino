String val;
int pin = A1;
int led = D7;

void setup() {
    pinMode(pin, INPUT);
    pinMode(led, OUTPUT);
}

void loop() {
    
    digitalWrite(led, HIGH);
    val = String( get_gp2d12( analogRead(pin) ) );
    
    Particle.publish("Distance", val, PRIVATE);
    
    delay(1000);
    
    digitalWrite(led, LOW);
    
    delay(29000);
}

uint16_t get_gp2d12 (uint16_t value) {
    if (value < 10) value = 10;
    return ((67870.0 / (value - 3.0)) - 40.0);
}