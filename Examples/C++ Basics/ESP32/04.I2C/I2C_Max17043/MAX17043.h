#ifndef _MAX17043_h
#define _MAX17043_h

/**

  							         Typical		Max
  Active Current:  			  50uA		  75uA
  Sleep-Mode Current:		  0.5-1uA		1-3uA
  Output Logic-Low: ALRT	0.4V		  0.4V
  Mode Transition: tTRAN	1ms			  1ms
			-Time to enter sleep after Sleep command is sent.
			-Time to exit sleep on rising edge of SCL or SDA.
			
  The first update occurs within 250ms after POR of the IC. 
  
  Battery voltage is measured at the CELL pin input with respect to GND over a 0 to 5.00V range 
  with resolution of 1.25mV. The A/D calculates the average cell voltage for a period of 125ms
  after IC POR and then for a period of 500ms for every cycle afterwards. The VCELL register
  requires 500ms to update after exiting Sleep mode. The result is placed in the VCELL register
  at the end of each conversion period.
  
  In the Command Register Address, in lsb, default/Power Up is:
  0x1C in Hex, 28 decimal, and 00011100 binary
  
  	11100 - ATHD (Alert Threshold) - The power-up default value for is 4%.
  			ATHD UNITS: 1 LSB = 2�S COMPLEMENT 1%, ATHD RANGE: 11111b = 1% - 00000b = 32%
  	0 - ALRT (ALERT Flag) - The power-up default value for ALRT is logic 0.
  	0 - X
  	0 - SLEEP (Sleep Bit) - The power-up default value for SLEEP is logic 0

	0x9C, 156 decimal, and 10011100 binary would ensure SLEEP which is logic 1
**/

#include <Arduino.h>
#include <Wire.h>

//use a pin that is not possible to define not in use
#define MAX17043_NOT_USING_ALERT_PIN 255

/* THE MAX 17043 IC ADDRESS */
#define MAX17043_ADDRESS            0x36

	/* REGISTER START ADDRESSES:  Note:  each is 16-bits.  h stands for HEX. */
	
	//02h-03h.  Reports 12-bit A/D measurement of battery voltage.  READ-ONLY.
	#define MAX17043_VCELL           0x02
	
		/* VCELL VALUES */
		#define MAX17043_VCELL_VOLTAGE_FACTOR	0.00125 // vcell reports battery in 0.00125V (1/800V or 1.25mV) increments
	
	//04h-05h.  Reports 16-bit SOC result calculated by ModelGauge algorithm.  READ-ONLY.
	#define MAX17043_SOC             0x04
	
	//06h-07h.  Sends special commands to the IC.  WRITE-ONLY
	#define MAX17043_MODE            0x06
	
	//08h-09h.  Returns IC version.  READ-ONLY.
	#define MAX17043_VERSION         0x08
	
	//0Ch-0Dh.  Battery compensation. Adjusts IC performance based on application conditions.
	//READ & WRITE.  Default:  971Ch.
	#define MAX17043_CONFIG          0x0C
	
		/* CONFIG */
		#define MAX17043_AWAKE_DEFAULT     0x9700 //lsb is 00000000
		#define MAX17043_SLEEP_DEFAULT     0x9780 //lsb is 10000000
		#define MAX17043_IS_TRUE       	   0x01
		#define MAX17043_MAX_ALERT_PERCENTAGE 32
		#define MAX17043_MIN_ALERT_PERCENTAGE 1
	
	//FEh-FFh.  Sends special commands to the IC.  WRITE-ONLY.
	#define MAX17043_COMMAND         0xFE
	
		/* COMMAND */
		#define MAX17043_POWER_ON_RESET  0x5400
		#define MAX17043_QUICK_START     0x4000

class MAX17043{
    
public:
  	MAX17043(uint8_t alertThreshold, uint8_t alertPin);
  	MAX17043(uint8_t alertThreshold);
  	MAX17043();
  
  	void begin();
  	void reset();
  
  	/* 
	quickStart() issues a quick-start command to the MAX170433.
	A quick start allows the MAX170433 to restart fuel-gauge calculations
	in the same manner as initial power-up of the IC. If an application's
	power-up sequence is very noisy, such that excess error is introduced
	into the IC's first guess of SOC, the Arduino can issue a quick-start
	to reduce the error.
	*/
	void quickStart();
	
  	uint16_t getVersion();
  
  	/*
	batteryVoltage() returns a float value voltage based on the 12-bit ADC reading
	of the battery as reported by the MAX170433's VCELL register
	*/
	float getBatteryVoltage();
  
  	/*
	batteryPercentage() returns a float value of the battery percentage
	reported from the SOC register of the MAX170433.
	*/
	float getBatteryPercentage();
  
  	/* 
	setAlertThreshold(uint8_t percent) configures the config register of
	the MAX170143, specifically the alert threshold therein. Pass a 
	value between 1 and 32 to set the alert threshold to a value between
	1 and 32%. Anything below will be set to 1%, above 32%.
	*/
	void setAlertThreshold(uint8_t percent);
	//gets it from the instance
  	uint8_t getAlertThreshold();
  	//gets it from the register
  	uint8_t getAlertThresholdRegister();
  	boolean isAlerting();
  	void clearAlert();
  	
  	//gets it from the instance
  	boolean isSleeping();
  	//gets it from the register
  	boolean isSleepingRegister();
  	void sleep();
  	void wake();

private:
  	/** Pin connected to the ALRT (active LOW) */
  	const uint8_t _alertPin;
  	uint8_t _alertThreshold;
  	boolean _sleeping;
  
  	/* 
	i2cRead16(uint8_t address) reads a 16-bit value beginning
	at the 8-bit address, and continuing to the next address. A 16-bit
	value is returned.
	*/
	uint16_t i2cRead16(uint8_t address);
  
  	/* 
	i2cRead16(uint8_t address, uint8_t &msb, uint8_t &lsb) reads a 16-bit
	value beginning at the 8-bit address, and continuing to the next address.
	A 16-bit value is returned and placed in msb - most significant bit and
	lsb - least significant bit.
	*/
	void i2cRead16(uint8_t address, uint8_t &msb, uint8_t &lsb);
  
  	/*
	i2cWrite16(uint16_t data, uint8_t address) writes 16 bits
	of data beginning at an 8-bit address, and continuing to the next.
  	*/
  	void i2cWrite16(uint16_t data, uint8_t address);
  
};

#endif
