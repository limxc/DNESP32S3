#include "hw.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_psram.h"

void hwinfo(void)
{
    uint32_t flash_size;
    esp_chip_info_t chip_info; /* 定义芯片信息结构体变量 */

    esp_flash_get_size(NULL, &flash_size); /* 获取FLASH大小 */
    esp_chip_info(&chip_info);
    printf("内核：cup数量%d\n", chip_info.cores); /* 获取CPU内核数并显示 */
    /* 获取FLASH大小并显示 */
    printf("FLASH size:%ld MB flash\n", flash_size / (1024 * 1024));
    /* 获取PARAM大小并显示 */
    printf("PSRAM size: %d bytes\n", esp_psram_get_size());
}

void nvs_init(void)
{
    esp_err_t ret;

    ret = nvs_flash_init(); /* 初始化NVS */

    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
}