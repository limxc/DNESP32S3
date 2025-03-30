#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "led.h"
#include "key.h"
#include "exit.h"

void led_blink(void)
{
    led_init();

    while (1)
    {
        LED_TOGGLE();
        vTaskDelay(1000);
    }
}

void key_led(void)
{
    uint8_t key;
    led_init();
    key_init();

    while (1)
    {
        key = key_scan(0); /* 获取键值 */

        switch (key)
        {
        case BOOT_PRES: /* BOOT被按下 */
        {
            LED_TOGGLE(); /* LED状态翻转 */
            break;
        }
        default:
        {
            break;
        }
        }

        vTaskDelay(10);
    }
}

void exit_key_led(void)
{
    exit_init();
    led_init();

    while (1)
    {
        vTaskDelay(1000);
    }
}