#include "LED.h"

#define GPIO_LED  GPIO_NUM_2

void LED_GPIO_Init(void)
{
    esp_rom_gpio_pad_select_gpio(GPIO_LED);                 // 选择GPIO口
    gpio_set_direction(GPIO_LED, GPIO_MODE_OUTPUT); // GPIO作为输出
    gpio_set_level(GPIO_LED, 0);                    // 默认低电平
}
