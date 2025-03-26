/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "esp_log.h"
#include "iot_button.h"
#include "button_gpio.h"

/* Most development boards have "boot" button attached to GPIO0.
 * You can also change this to another pin.
 */

static void bootbutton_event_cb(void *arg, void *data)
{
    iot_button_print_event((button_handle_t)arg);

    ESP_LOGI("BOOT BUTTON", "BUTTON_SINGLE_CLICK");
}

void bootbutton_click(void)
{
    button_config_t btn_cfg = {0};
    button_gpio_config_t gpio_cfg = {
        .gpio_num = 0,
        .active_level = 0,
    };

    button_handle_t btn;
    esp_err_t ret = iot_button_new_gpio_device(&btn_cfg, &gpio_cfg, &btn);
    assert(ret == ESP_OK);
    if (NULL == btn)
    {
        ESP_LOGE("BOOT BUTTON", "Button create failed");
    }

    ret = iot_button_register_cb(btn, BUTTON_SINGLE_CLICK, NULL, bootbutton_event_cb, NULL);

    ESP_ERROR_CHECK(ret);
}
