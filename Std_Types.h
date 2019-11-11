/*
 * Std_Types.h
 *
 *  Created on: Nov 8, 2019
 *      Author: Karim
 */

#ifndef STD_TYPES_H
#define STD_TYPES_H

/* Id for the company in the AUTOSAR
 * My id = 1000 :) */
#define STD_TYPES_VENDOR_ID                          (1000U)

#define STD_TYPES_MODULE_ID                          (49U)

#define STD_TYPES_INSTANCE_ID                        (0U)
/*
 * Module Version 1.0.0
 */
#define STD_TYPES_SW_MAJOR_VERSION                           (1U)
#define STD_TYPES_SW_MINOR_VERSION                           (0U)
#define STD_TYPES_SW_PATCH_VERSION                           (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION                   (4U)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION                   (3U)
#define STD_TYPES_AR_RELEASE_PATCH_VERSION                   (1U)



#include "Platform_Types.h" // STD001
/*
 * Checking autosar version for platform types.
 */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PLATFORM_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Platform_Types.h does not match the expected version"
#endif

#include "Compiler.h"       // STD001
/*
 * Checking autosar version for compiler.h
 */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != COMPILER_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != COMPILER_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Compiler.h does not match the expected version"
#endif

/* Type definitions */
typedef uint8 Std_ReturnType;    // STD005
typedef struct                   // STD015
{
   uint16   vendorID;
   uint16   moduleID;
   uint8    sw_major_version;
   uint8    sw_minor_version;
   uint8    sw_patch_version;
} Std_VersionInfoType;

/* Symbol definitions */
#ifndef STATUSTYPEDEFINED  // STD006
   #define STATUSTYPEDEFINED
   #define E_OK   0x00

   typedef unsigned char StatusType;
#endif

#define E_NOT_OK     0x01     // STD006

#define STD_HIGH     0x01     // STD007
#define STD_LOW      0x00

#define STD_ACTIVE   0x01     // STD013
#define STD_IDLE     0x00

#define STD_ON       0x01     // STD010
#define STD_OFF      0x00

#endif /* STD_TYPES_H */



