#ifndef _MatrixMotorExtension_H_
#define _MatrixMotorExtension_H_

#include <Arduino.h>
#include <Wire.h>

#ifndef ADDR_PCA954X
#define ADDR_PCA954X 0x70
#endif

#define MatrixMotor_ADDR 0x24

typedef enum __MotorRegType
{
  Device_ID = 1,
  Device_Control_1,
  Device_Control_2, 
  Battery_Voltage,
  CH1_PWM,
  CH2_PWM,
  CH3_PWM,
  CH4_PWM
} MotorRegType;

class MatrixMotor{
private:
	uint8_t _ch=0, _ver=1;
  uint8_t _reverse1 = 0, _reverse2 = 0, _reverse3 = 0, _reverse4 = 0;
  uint8_t pwmChannel;
	uint8_t i2cReadData(MotorRegType reg);
	void i2cMUXSelect();
	void i2cWriteData(MotorRegType reg, uint8_t data);
  void channelReverse(uint8_t dir);
public:
	friend class MiniI2C;
	bool begin();
	float getVbat();
	void setPWM(int ch, int speed);
};

#endif
