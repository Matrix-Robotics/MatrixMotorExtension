#include <MatrixMotorExtension.h>

MatrixMotor Motor;

void setup()
{
    Serial.begin(115200);
    Serial.print("Starting...\n");
    if (Motor.begin()){
        Serial.print("Motor Extension Activated");
    };
}

void loop()
{
    Serial.println("===============================================================");
    
    Serial.print("Voltage=");
    Serial.println(Motor.getVbat());

    delay(250);
}