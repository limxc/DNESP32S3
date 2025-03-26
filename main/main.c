#include "hw.h"
#include "led.h"
#include "key.h"
#include "button.h"

void key_led(void);

/**
 * @brief       程序入口
 * @param       无
 * @retval      无
 */
void app_main(void)
{
    nvs_init(); /* NVS初始化 */

    hwinfo(); /* 硬件信息 */

    // led_blink(); /* LED闪烁 */

    // key_led(); /* 按键切换灯 */

    bootbutton_click(); /* 按键触发 */

    while (1)
    {
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
