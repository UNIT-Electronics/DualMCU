/* 
 *  UNIT Electronics 2022
 *  Capacitive Touch Sensor
 *  T0(GPIO4),T2(GPIO2) & T3(GPIO15) for DualMCU - ESP32 */

int touch_sensor_value=0;
void setup()
{
Serial.begin(115200);
Serial.println("Touch sensor tutorial ESP32");
}

void loop()
{

touch_sensor_value = touchRead(T0); //Select the Capacitive Touch pin on the DualMCU: T0(GPIO4),T2(GPIO2) & T3(GPIO15) from ESP32
Serial.print("Touch0 value is = ");
Serial.println( touch_sensor_value);
delay(1000);
}
