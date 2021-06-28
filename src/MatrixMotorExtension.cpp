#include "MatrixMotorExtension.h"

bool MatrixMotor::begin(){
	Wire.begin();
	i2cMUXSelect();
	delay(50);
	if(i2cReadData(Device_ID) == 0x45){
		i2cWriteData(Device_Control_1, 0x08); // reset
		delay(500);
		i2cWriteData(Device_Control_1, 0x00); // module enable
		i2cWriteData(Device_Control_2, 0xF0); // channel enable
		delay(500);
		return true;
	}
	else{
		return false;
	}
}

float MatrixMotor::getVbat(){
	i2cMUXSelect();
	return i2cReadData(Battery_Voltage)*0.033;
}

void MatrixMotor::setPWM(int ch, int speed){
	i2cMUXSelect();
	if(ch > 0 && ch < 5){
		pwmChannel = ch;
		if(speed < 0){
			speed *= -1;
			channelReverse(1);
		}
		else{
			channelReverse(0);
		}
		i2cWriteData(MotorRegType(ch+4), speed);
	}

}

void MatrixMotor::channelReverse(uint8_t dir){

	switch (pwmChannel){
		case CH1_PWM:
			_reverse1 = dir; 
			break;
		case CH2_PWM:
			_reverse2 = dir; 
			break;
		case CH3_PWM:
			_reverse3 = dir; 
			break;
		case CH4_PWM:
			_reverse4 = dir; 
			break;
	}
	i2cWriteData(Device_Control_2,  0xF0 + (_reverse1 << 3) + (_reverse2 << 2) + (_reverse3 << 1) + _reverse4);
}

uint8_t MatrixMotor::i2cReadData(MotorRegType reg){
	
	Wire.beginTransmission(MatrixMotor_ADDR);
	Wire.write(reg);
	Wire.endTransmission(1);

	delay(1);

	Wire.requestFrom(MatrixMotor_ADDR, 1);

	delay(1);

	return Wire.read();
}

void MatrixMotor::i2cMUXSelect(){
	switch (_ver)
	{
	case 2:
		Wire.beginTransmission(ADDR_PCA954X);
		Wire.write(_ch + 4);
		Wire.endTransmission(1);

		delay(10);
		break;
	case 3:
		Wire.beginTransmission(ADDR_PCA954X);
		Wire.write((1 << _ch));
		Wire.endTransmission(1);
		
		delay(10);
		break;
	default:
		break;
	}
}

void MatrixMotor::i2cWriteData(MotorRegType reg, uint8_t data){

	Wire.beginTransmission(MatrixMotor_ADDR);

	Wire.write(reg);
	Wire.write(data);

	Wire.endTransmission(1);
}
