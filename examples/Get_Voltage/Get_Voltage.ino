#include <MatrixMotorExtension.h>

MatrixMotor Motor;

void setup()
{
    Serial.begin(115200);
    Serial.print("Starting...\n");
    if (Motor.begin()){
        Serial.println("Motor Extension Activated");
    }
    else{
        Serial.println("Motor Extension activation failed");
    }
}

void loop()
{
    Serial.println("===============================================================");
    
    Serial.print("Voltage=");
    Serial.println(Motor.getVbat());

    delay(250);
}