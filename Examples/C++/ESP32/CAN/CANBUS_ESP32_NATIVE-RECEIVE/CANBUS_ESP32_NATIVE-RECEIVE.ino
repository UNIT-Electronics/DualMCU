#include <driver/can.h>
#include <driver/gpio.h>
void setup() {
  Serial.begin(115200);
  Serial.println("Dual MCU receive CANbus data");
  setup_can_driver();
}

void setup_can_driver() //This function will setup CAN driver
{
  can_general_config_t general_config = {
    .mode = CAN_MODE_NORMAL,
    .tx_io = (gpio_num_t)GPIO_NUM_26,
    .rx_io = (gpio_num_t)GPIO_NUM_25,
    .clkout_io = (gpio_num_t)CAN_IO_UNUSED,
    .bus_off_io = (gpio_num_t)CAN_IO_UNUSED,
    .tx_queue_len = 0,  // I will not be transmiting in this example
    .rx_queue_len = 65,
    .alerts_enabled = CAN_ALERT_ALL,
    .clkout_divider = 0
  };
  can_timing_config_t timing_config = CAN_TIMING_CONFIG_500KBITS();  //I will be usiing can bus speed of 500 kbit/s
  can_filter_config_t filter_config = CAN_FILTER_CONFIG_ACCEPT_ALL();

  esp_err_t error;
  error = can_driver_install(&general_config, &timing_config, &filter_config);

  if (error == ESP_OK) {
    Serial.println("CAN Driver Instalation OK");
  } else {
    Serial.println("CAN Driver Instalation Failed");
  }
  error = can_start();

  if (error == ESP_OK) {
    Serial.println("CAN Driver Started");
  } else {
    Serial.println("CAN Driver Instalation Failed");
  }
}

void loop() {
  can_message_t rx_frame;
  if (can_receive(&rx_frame, pdMS_TO_TICKS(1000)) == ESP_OK)
  {
    printf("from 0x%08X,DLC%d,Data", rx_frame.identifier, rx_frame.data_length_code);
    for (int i = 0; i < rx_frame.data_length_code; i++) {
      printf(" 0x%02X ", rx_frame.data[i]);
    }
    printf("\n");
  }
}
