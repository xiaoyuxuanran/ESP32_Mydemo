#include <stdio.h>
#include "driver/gpio.h"
#include "./include/uart.h"
#include "LED.h"
void uart_init(void) {
    const uart_config_t uart_config = {
        .baud_rate = 115200,//波特率
        .data_bits = UART_DATA_8_BITS,//数据位
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,//停止位
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };
    // We won't use a buffer for sending data.
    uart_driver_install(UART_NUM_1, RX_BUF_SIZE * 2, 0, 0, NULL, 0);
    uart_param_config(UART_NUM_1, &uart_config);
    uart_set_pin(UART_NUM_1, TXD_PIN, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}

int sendData(const char* logName, const char* data)
{
    const int len = strlen(data);
    const int txBytes = uart_write_bytes(UART_NUM_1, data, len);
    ESP_LOGI(logName, "Wrote %d bytes", txBytes);
    return txBytes;
}

void tx_task(void *arg)
{
    static const char *TX_TASK_TAG = "TX_TASK";
    esp_log_level_set(TX_TASK_TAG, ESP_LOG_INFO);
    while (1) {
        sendData(TX_TASK_TAG, "hello world");
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}

void rx_task(void *arg)
{
    static const char *RX_TASK_TAG = "RX_TASK";
    static int led_flag = 0;
    esp_log_level_set(RX_TASK_TAG, ESP_LOG_INFO);
    uint8_t* data = (uint8_t*) malloc(RX_BUF_SIZE+1);
    while (1) {
        const int rxBytes = uart_read_bytes(UART_NUM_1, data, RX_BUF_SIZE, 1000 / portTICK_PERIOD_MS);
        if (rxBytes > 0) {
            data[rxBytes] = 0;
            if(data[0]=='o'&&data[1]=='p'&&data[2]=='e'&&data[3]=='n')
            {
                led_flag=1;
            }
            if(data[0]=='c'&&data[1]=='l'&&data[2]=='o'&&data[3]=='s'&&data[4]=='e')
            {
                led_flag=0;
            }
            if (led_flag==1)
            {
                gpio_set_level(GPIO_NUM_2,1);
            }
            if (led_flag==0)
            {
                gpio_set_level(GPIO_NUM_2,0);
            }          
            ESP_LOGI(RX_TASK_TAG, "Read %d bytes: '%s'", rxBytes, data);
            printf("%d\n",(int)data);
            ESP_LOG_BUFFER_HEXDUMP(RX_TASK_TAG, data, rxBytes, ESP_LOG_INFO);
        }
    }
    free(data);
} 
