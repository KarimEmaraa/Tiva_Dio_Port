/*
 * Port_PBcfg.c
 *
 *  Created on: Nov 9, 2019
 *      Author: Karim
 */

/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (3U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (1U)

#include "Port.h"

#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

#include "Port_MemMap.h"

#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_MEMMAP_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_MEMMAP_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_MEMMAP_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

const Port_ConfigType Port_Configuration = {
   .pins[PORT_F_PIN_1] = {
        PORTF,
        PIN_1,
        PORT_PIN_DIO_MODE,
        PORT_PIN_OUT,
		PUSH_PULL,
        GPIODR4R,
        TRUE,
        TRUE,
        LOW,
    },
    .pins[PORT_F_PIN_2] = {
         PORTF,
         PIN_2,
         PORT_PIN_DIO_MODE,
         PORT_PIN_OUT,
		 PUSH_PULL,
         GPIODR4R,
         TRUE,
         TRUE,
         LOW,
    }
};



