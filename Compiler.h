/*
 * Compiler.h
 *
 *  Created on: Nov 8, 2019
 *      Author: Karim
 */

#ifndef COMPILER_H
#define COMPILER_H

/* Id for the company in the AUTOSAR
 * My ID = 1000 :) */
#define COMPILER_VENDOR_ID                                  (1000U)

/* Port Module Id */
#define COMPILER_MODULE_ID                                  (51U)

/* Port Instance Id */
#define COMPILER_INSTANCE_ID                                (0U)

/*
 * Module Version 1.0.0
 */
#define COMPILER_SW_MAJOR_VERSION                           (1U)
#define COMPILER_SW_MINOR_VERSION                           (0U)
#define COMPILER_SW_PATCH_VERSION                           (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define COMPILER_AR_RELEASE_MAJOR_VERSION                   (4U)
#define COMPILER_AR_RELEASE_MINOR_VERSION                   (3U)
#define COMPILER_AR_RELEASE_PATCH_VERSION                   (1U)

#include "Compiler_Cfg.h"


#define AUTOMATIC


#define TYPEDEF


#define NULL_PTR          ((void *)0)


#define INLINE            inline


#define LOCAL_INLINE      static inline

#define STATIC            static

#define FUNC(rettype, memclass) rettype
#define FUNC_P2CONST(rettype, ptrclass, memclass) const rettype *
#define FUNC_P2VAR(rettype, ptrclass, memclass) rettype *

#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const
#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname) ptrclass

#define CONST(consttype, memclass) const consttype
#define VAR(vartype, memclass) vartype


#endif

