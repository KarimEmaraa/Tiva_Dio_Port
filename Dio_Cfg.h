/*
 * Dio_Cfg.h
 *
 *  Created on: Nov 10, 2019
 *      Author: Karim
 */

#ifndef DIO_CFG_H
#define DIO_CFG_H

/*
 * Module Version 1.0.0
 */
#define DIO_CFG_SW_MAJOR_VERSION              (1U)
#define DIO_CFG_SW_MINOR_VERSION              (0U)
#define DIO_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_CFG_AR_RELEASE_MINOR_VERSION     (3U)
#define DIO_CFG_AR_RELEASE_PATCH_VERSION     (1U)

/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT                (TRUE)

/* Pre-compile option for Version Info API */
#define DIO_VERSION_INFO_API                (FALSE)

/* Pre-compile option for presence of Dio_FlipChannel API */
#define DIO_FLIP_CHANNEL_API                (TRUE)

/* Number of the configured Dio Channels */
#define DIO_CONFIGURED_CHANNLES             (2U)
#define DIO_MAX_PORT						(6U)

#define DIO_PIN_0              0x00000001  // GPIO pin 0
#define DIO_PIN_1              0x00000002  // GPIO pin 1
#define DIO_PIN_2              0x00000004  // GPIO pin 2
#define DIO_PIN_3              0x00000008  // GPIO pin 3
#define DIO_PIN_4              0x00000010  // GPIO pin 4
#define DIO_PIN_5              0x00000020  // GPIO pin 5
#define DIO_PIN_6              0x00000040  // GPIO pin 6
#define DIO_PIN_7              0x00000080  // GPIO pin 7

#endif /* DIO_DIO_CFG_H */
