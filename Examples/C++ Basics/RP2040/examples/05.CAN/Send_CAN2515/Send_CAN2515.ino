/*  send a frame from can bus
    CAN Baudrate,

    #define CAN_5KBPS           1
    #define CAN_10KBPS          2
    #define CAN_20KBPS          3
    #define CAN_25KBPS          4
    #define CAN_31K25BPS        5
    #define CAN_33KBPS          6
    #define CAN_40KBPS          7
    #define CAN_50KBPS          8
    #define CAN_80KBPS          9
    #define CAN_83K3BPS         10
    #define CAN_95KBPS          11
    #define CAN_100KBPS         12
    #define CAN_125KBPS         13
    #define CAN_200KBPS         14
    #define CAN_250KBPS         15
    #define CAN_500KBPS         16
    #define CAN_666KBPS         17
    #define CAN_1000KBPS        18
*/

#include <mcp_can.h>
#include <SPI.h>

#define SPI_CS_PIN  21

MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  while (CAN_OK != CAN.begin(CAN_500KBPS))    // init can bus : baudrate = 500k
  {
    Serial.println("CAN BUS FAIL!");
    delay(100);
  }
  Serial.println("SEND: CAN BUS OK!");
  Serial.println("Master");
}

unsigned char stmp0[8] = {1, 2, 3, 4, 5, 6, 7, 8};
unsigned char stmp1[8] = {255, 255, 255, 255, 0, 0, 0, 0};

String data;
void loop()
{
  for (int i=0; i<8;i++)
  {
    data+=stmp0[i];
    data+="  ";
  }
  Serial.print("Trama enviada: canId: 000 " );
  //Serial.println(stmp0[0] + stmp0[1] + stmp0[2] + stmp0[3] + stmp0[4] + stmp0[5] + stmp0[6] + stmp0[7]);
  Serial.println(data);
  CAN.sendMsgBuf(0x000, 0, 8, stmp0);
  data="";
  delay(300);
  for (int i=0; i<8;i++)
  {
    data+=stmp1[i];
    data+="  ";
  }
  Serial.print("Trama enviada: canId: 001 " );
  //Serial.println(stmp0[0] + stmp0[1] + stmp0[2] + stmp0[3] + stmp0[4] + stmp0[5] + stmp0[6] + stmp0[7]);
  Serial.println(data);
  CAN.sendMsgBuf(0x001, 0, 8, stmp1);
  data="";
  delay(300);
}


