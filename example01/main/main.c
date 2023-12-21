#include <stdio.h>
#include "string.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "esp_spi_flash.h"
#include "freertos/queue.h"
#include "LED.h"
#include "../components/uart/include/uart.h"
 


 
//主函数
int app_main()
{
    LED_GPIO_Init();
    uart_init();
    xTaskCreate(rx_task, "uart_rx_task", 1024*2, NULL, configMAX_PRIORITIES, NULL);
    xTaskCreate(tx_task, "uart_tx_task", 1024*2, NULL, configMAX_PRIORITIES-1, NULL);
   //  while(1)
   //  {   printf("LED ON!\n");  
   //     gpio_set_level(GPIO_LED,1);//开灯
   //     vTaskDelay(1000/portTICK_PERIOD_MS);//延时一秒
   //     printf("LED OFF!\n"); 
   //     gpio_set_level(GPIO_LED,0);//关灯
   //     vTaskDelay(1000/portTICK_PERIOD_MS);//延时一秒
   //  }
 return 0; 
}

