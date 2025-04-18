/**
 ****************************************************************************************************
 * @file        exIT.h
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2023-08-26
 * @brief       外部中断驱动代码
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 ESP32-S3 开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 ****************************************************************************************************
 */

#ifndef __EXIT_H_
#define __EXIT_H_

#include "driver/gpio.h"

/* 引脚定义 */
#define BOOT_INT_GPIO_PIN GPIO_NUM_0

/* 函数声明 */
void exit_init(void); /* 外部中断初始化程序 */

#endif
