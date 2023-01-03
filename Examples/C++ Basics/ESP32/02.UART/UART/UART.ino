/*
 * ESP32 has 3 serial ports: UART0, UART1, UART2
 * UART0 -> Is connected to serial communication between ESP32 and computer, used for loading Arduino code to ESP32. GPIO 1 - RX, GPIO 3 - TX
 * UART1 -> This pins are internally connected to the SPI flash memory, we can not use UART1 directly without reassigning pins in Arduino IDE
 * UART2 -> GPIO 16 - RX, GPIO 17 - TX
 */
#define RXD2 16   //Define pins for UART2
#define TXD2 17
 
void setup() {
  /*
   * Method to begin and specify the serial port:
   * Serial[Port].begin(baud rate, protocol, Rx pin, Tx pin)
   */
  Serial.begin(9600);   //To start UART0 only need Serial.begin function and specify the baud rate
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);    //Function to start UART2
}

void loop() {
  Serial2.println("UNIT ");   //Function to send data via UART2, pin 17
  
  while(Serial.available()){  //Function to receive data via UART0, pin 1 
    Serial.print(char(Serial.read()));    //Serial.read() is the function that store the data receive on UART0
  }
  delay(500);
  
  Serial.println("Electronics\n");    //Function to send data via UART0, pin 3
  
  while(Serial2.available()){     //Function to receive data via UART2, pin 17
    Serial.print(char(Serial2.read()));    //Serial2.read() is the function that store the data receive on UART2
  }
  delay(500);
}
