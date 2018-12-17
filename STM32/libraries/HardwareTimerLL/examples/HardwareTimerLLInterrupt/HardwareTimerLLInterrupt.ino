
#include "hardwareTimerLL.h"

#define Timerx TimerLL2

void interrupt() {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
//    Timerx.setCount(250);
}

void setup() {
    Serial.begin(115200);
    Serial.println("Application start...");
    pinMode(LED_BUILTIN, OUTPUT);

    Timerx.attachInterrupt(interrupt);
    Timerx.resume();

    Timerx.setPeriod(100000); // in microseconds = 1 second
//    Timerx.setTimerFrequency(65514);
//    Timerx.setPeriodFrequency(1);
}

void loop() {
    delay(5000);
    Serial.println("----");
    
    Serial.print("Timer base frequency:");
    Serial.println(Timerx.getBaseFrequency());

    Serial.print("Timer prescaler:");
    Serial.println(Timerx.getPrescaleFactor());

    Serial.print("Timer period:");
    Serial.println(Timerx.getOverflow());

//    Serial.print("Timer count:");
//    Serial.println(Timerx.getCount());
}
