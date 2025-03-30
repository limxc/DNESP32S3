#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "demo.h"
#include "hw.h"

#include "button.h"

/**
 * @brief       程序入口
 * @param       无
 * @retval      无
 */
void app_main(void)
{
    nvs_init(); /* NVS初始化 */

    hwinfo(); /* 硬件信息 */

    //led_blink(); /* LED闪烁 */

    //bootbutton_click(); /* 按键触发 */

    //key_led(); /* 按键切换灯 */

    exit_key_led(); /* 外部中断触发按键切换灯 */

    while (1)
    {
        vTaskDelay(1000);
    }
}
