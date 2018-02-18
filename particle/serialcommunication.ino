#include "cellular_hal.h"

STARTUP(cellular_credentials_set("isp.telus.com", "", "", NULL));
// SYSTEM_MODE(SEMI_AUTOMATIC);

// Variables
int counter = 0;

// Functions
int receiveMessage(String message) {
    Serial.printlnf("%s", message.c_str());
    flashLED();
}

void flashLED() {
    RGB.control(true);
    RGB.color(255,0,0);
    delay(500);
    RGB.color(0,0,255);
    delay(500);
    RGB.control(false);
}

void setup() {
    Particle.keepAlive(30);
    
    Serial.begin(9600);
    
    Particle.function("sendmessage", receiveMessage);
    Particle.variable("counter", counter);
    
    flashLED();
}

void loop() {
    // Serial.printlnf("testing %d", counter);
    counter++;
    delay(1000);
}