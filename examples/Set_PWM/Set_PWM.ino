#include <MatrixMotorExtension.h>

MatrixMotor Motor;
int channel, pwm;
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
    
    channel = 1;
    pwm = 255;
    Motor.setPWM(channel, pwm);
    Serial.println("set channel " + (String)channel + " to " + (String)pwm);
    delay(500);

    channel = 2;
    pwm = -255;
    Motor.setPWM(channel, pwm);
    Serial.println("set channel " + (String)channel + " to " + (String)pwm);
    delay(500);

    channel = 1;
    pwm = -255;
    Motor.setPWM(channel, pwm);
    Serial.println("set channel " + (String)channel + " to " + (String)pwm);
    delay(500);

    channel = 2;
    pwm = 255;
    Motor.setPWM(channel, pwm);
    Serial.println("set channel " + (String)channel + " to " + (String)pwm);
    delay(500);
}