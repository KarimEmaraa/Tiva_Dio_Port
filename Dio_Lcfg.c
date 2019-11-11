/*
 * Dio_Lcfg.c
 *
 *  Created on: Nov 10, 2019
 *      Author: Karim
 */

#include "Dio_MemMap.h"
#include "Dio.h"

const Dio_ConfigType Dio_Configuration = {
		.Channels[0] = { DIO_PORTF, DIO_PIN_1 },
		.Channels[1] = { DIO_PORTF, DIO_PIN_2 }
};
