#ifndef __UART_H__
#define __UART_H__

#include "string.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
//#include "esp_spi_flash.h"
#include "freertos/queue.h"

static const int RX_BUF_SIZE = 1024;

#define TXD_PIN (GPIO_NUM_1)
#define RXD_PIN (GPIO_NUM_3)

void uart_init(void);
int sendData(const char* logName, const char* data);
void tx_task(void *arg);
void rx_task(void *arg);

#endif



