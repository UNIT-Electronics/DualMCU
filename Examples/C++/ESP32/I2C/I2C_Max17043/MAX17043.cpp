#include "MAX17043.h"

MAX17043::MAX17043(uint8_t alertThreshold, uint8_t alertPin) :
	_alertThreshold(alertThreshold),
    _alertPin(alertPin),
    _sleeping(true)
{
}

MAX17043::MAX17043(uint8_t alertThreshold) :
	_alertThreshold(alertThreshold),
    _alertPin(MAX17043_NOT_USING_ALERT_PIN),
    _sleeping(true)
{
}

MAX17043::MAX17043() :
	_alertThreshold(MAX17043_MAX_ALERT_PERCENTAGE),
    _alertPin(MAX17043_NOT_USING_ALERT_PIN),
    _sleeping(true)
{
}

void MAX17043::begin() {
	//if using the alert pin
	if(_alertPin != MAX17043_NOT_USING_ALERT_PIN) {
		pinMode(_alertPin, INPUT);
  		digitalWrite(_alertPin, HIGH);
  	}
  	
  	Wire.begin(); // Start I2C
  	setAlertThreshold(_alertThreshold); //sets threshold, resets alert bit, and wakes as well
  	quickStart(); // restart fuel-gauge calculations in case of noisy startup
}

void MAX17043::reset(){
  i2cWrite16(MAX17043_POWER_ON_RESET, MAX17043_MODE);
  wake(); //sets threshold and resets alert bit as well
}

void MAX17043::quickStart()
{
  i2cWrite16(MAX17043_QUICK_START, MAX17043_MODE);
}

uint16_t MAX17043::getVersion(){
  uint16_t value = 0;
  uint8_t msb = 0;
  uint8_t lsb = 0;
  i2cRead16(MAX17043_VERSION, msb, lsb);
  
    value  = 0xFF00 & (msb<<8);
    value |=   0xFF & lsb;

  return value;
}

float MAX17043::getBatteryVoltage()
{
  uint16_t vcell;
  
  vcell = i2cRead16(0x02);
  vcell = vcell >> 4;  // last 4 bits of vcell are nothing
  
  return (float) vcell * MAX17043_VCELL_VOLTAGE_FACTOR;
}

float MAX17043::getBatteryPercentage()
{
  uint16_t soc;
  float percent;
  
  soc = i2cRead16(MAX17043_SOC);  // Read SOC register of MAX170433
  percent = (uint8_t) (soc >> 8);  // High byte of SOC is percentage
  percent += ((float)((uint8_t)soc))/256;  // Low byte is 1/256%
  
  return percent;
}

void MAX17043::setAlertThreshold(uint8_t percent)
{
  uint8_t percentBits = percent;
  
  if ( percent > (uint8_t) MAX17043_MAX_ALERT_PERCENTAGE )
    percentBits = (uint8_t) MAX17043_MAX_ALERT_PERCENTAGE;
  else if( percent < (uint8_t) MAX17043_MIN_ALERT_PERCENTAGE )
  	percentBits = (uint8_t) MAX17043_MIN_ALERT_PERCENTAGE;
  
  _alertThreshold = (uint8_t) (MAX17043_MAX_ALERT_PERCENTAGE - percentBits);
  
  wake();
}

uint8_t MAX17043::getAlertThreshold(){
  return (uint8_t) (MAX17043_MAX_ALERT_PERCENTAGE - _alertThreshold);
}

uint8_t MAX17043::getAlertThresholdRegister(){
  uint8_t msb = 0;
  uint8_t lsb = 0;

  i2cRead16(MAX17043_CONFIG,msb,lsb);
  uint8_t percent = lsb & 0x1f;

  return (uint8_t) (MAX17043_MAX_ALERT_PERCENTAGE - percent);
}

boolean MAX17043::isAlerting(){
  boolean result = false;
  if(_alertPin == MAX17043_NOT_USING_ALERT_PIN) {
	  uint8_t msb = 0;
	  uint8_t lsb = 0;
	
	  i2cRead16(MAX17043_CONFIG,msb,lsb);
	  uint8_t alerting = (lsb >>5) & 0x01;
	
	  result = (alerting == MAX17043_IS_TRUE);
  }
  else //active low
  	result = (digitalRead(_alertPin) == LOW);
  	
  return result;
}

void MAX17043::clearAlert() {
	if(isAlerting())
		wake();
}

void MAX17043::sleep(){
  i2cWrite16((MAX17043_SLEEP_DEFAULT | _alertThreshold), MAX17043_CONFIG);
  _sleeping = true;
}

void MAX17043::wake(){
  i2cWrite16((MAX17043_AWAKE_DEFAULT | _alertThreshold), MAX17043_CONFIG);
  _sleeping = false;
}

boolean MAX17043::isSleeping(){
  return _sleeping;
}

boolean MAX17043::isSleepingRegister(){
  uint8_t msb = 0;
  uint8_t lsb = 0;

  i2cRead16(MAX17043_CONFIG,msb,lsb);
  uint8_t sleeping = (lsb >>7) & 0x01; 

  return (sleeping == MAX17043_IS_TRUE);
}

uint16_t MAX17043::i2cRead16(uint8_t address)
{
  uint16_t data = 0;
  
  Wire.beginTransmission(MAX17043_ADDRESS);
  Wire.write(address);
  Wire.endTransmission();
  
  Wire.requestFrom(MAX17043_ADDRESS, 2);
  
  //TODO:  return false if don't have enough to read, so we don't block
  while (Wire.available() < 2)
    ;
  data = ((uint16_t) Wire.read()) << 8;
  data |= Wire.read();
  
  return data;
}

void MAX17043::i2cRead16(uint8_t address, uint8_t &msb, uint8_t &lsb){

  Wire.beginTransmission(MAX17043_ADDRESS);
  Wire.write(address);
  Wire.endTransmission();

  Wire.requestFrom(MAX17043_ADDRESS, 2);

  //TODO:  return false if don't have enough to read, so we don't block
  while (Wire.available() < 2)
    ;
  msb = Wire.read();
  lsb = Wire.read();
  Wire.endTransmission();
}

void MAX17043::i2cWrite16(uint16_t data, uint8_t address)
{
  Wire.beginTransmission(MAX17043_ADDRESS);
  Wire.write(address);
  Wire.write((byte)((data >> 8) & 0x00FF));
  Wire.write((byte)(data & 0x00FF));
  Wire.endTransmission();
}
