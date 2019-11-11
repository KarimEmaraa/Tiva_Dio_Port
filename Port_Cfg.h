/*
 * Port_Cfg.h
 *
 *  Created on: Nov 9, 2019
 *      Author: Karim
 */

#ifndef PORT_CFG_H
#define PORT_CFG_H


/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION                           (1U)
#define PORT_CFG_SW_MINOR_VERSION                           (0U)
#define PORT_CFG_SW_PATCH_VERSION                           (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION                   (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION                   (3U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION                   (1U)

/******************************************************************************
 *                      Pre Compile Configurations                            *
 ******************************************************************************/

#define PORT_DEV_ERROR_DETECT           TRUE
#define PORT_SET_PIN_DIRECTION_API      FALSE
#define PORT_SET_PIN_MODE_API           TRUE
#define PORT_VERSION_INFO_API           TRUE



#endif /*PORT_CFG_H_*/
