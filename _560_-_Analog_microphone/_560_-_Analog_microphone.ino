/*  Analog microphone demo sketch
 * 
 * This sketch detects loud noises using an analog electrelet microphone.
 * 
 * This sketch was adapted from the original that comes with the 
 * Adafruit library for Arduino Step by Step by Peter Dalmaris.
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - Analog electrelet microphone
 *  
 *  Libraries
 *  ---------
 *  - Nonw
 *
 * Connections
 * -----------
 *  Break out    |    Arduino Uno
 *  -----------------------------
 *      VCC      |      5V
 *      GND      |      GND
 *      AUD      |      A0
 
 * 
 * Other information
 * -----------------
 *  This code is useful if you want to do things like detect a knock on a door,
 *  hands clapping, etc.
 *  
 *  Created on October 14 2016 by Peter Dalmaris
 * 
 */

int currentValue;
int maxValue;
int minValue;
unsigned long timer;
int sampleSpan = 200; // Amount in milliseconds to sample data
int volume;           // this roughly goes from 0 to 700

void setup() 
{
    Serial.begin(9600); 
    resetValues();
}

void loop() 
{
    currentValue = analogRead(A0);

    if (currentValue < minValue) {
        minValue = currentValue;
    } 
    if (currentValue > maxValue) {
        maxValue = currentValue;
    }

    if (millis() - timer >= sampleSpan) {
        volume = maxValue - minValue;
//        Serial.println(volume);
        resetValues();
    }

    // I arbitrarily select 100 as the value above which the
    //microphone is picking a loud noise.
    if (volume > 100)
    {
      Serial.println("Loud");
    } else
    {
      Serial.println("Quiet");
    }
     
}

void resetValues()
{
    maxValue = 0;
    minValue = 1024;
    timer = millis(); 
}
