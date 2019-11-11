/*
 * Port.h
 *
 *  Created on: Nov 9, 2019
 *      Author: Karim
 */

#ifndef PORT_H
#define PORT_H

/* Id for the company in the AUTOSAR
 * My ID = 1000 :)
 */
#define PORT_VENDOR_ID    (1000U)

/* Port Module Id */
#define PORT_MODULE_ID    (40U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION                           (1U)
#define PORT_SW_MINOR_VERSION                           (0U)
#define PORT_SW_PATCH_VERSION                           (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define PORT_AR_RELEASE_MAJOR_VERSION                   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION                   (3U)
#define PORT_AR_RELEASE_PATCH_VERSION                   (1U)

#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Dio Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

#include "Port_Cfg.h"

#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

#include "Port_Bsp.h"

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/*Invalid Port Pin ID requested*/
#define PORT_E_PARAM_PIN                        (0x0A)
/*Port Pin not configured as changeable*/
#define PORT_E_DIRECTION_UNCHANGEABLE           (0x0B)
/*API Port_Init service called with wrong parameter.*/
#define PORT_E_INIT_FAILED                      (0x0C)
/*API Port_SetPinMode service called when mode is unchangeable.*/
#define PORT_E_PARAM_INVALID_MODE               (0x0D)
/*API Port_SetPinMode service called when mode is unchangeable*/
#define PORT_E_MODE_UNCHANGEABLE                (0x0E)
/*API service called without module initialization*/
#define PORT_E_UNINIT                           (0x0F)
/*APIs called with a Null Pointer*/
#define PORT_E_PARAM_POINTER                    (0x10)

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
#define PORT_INIT_SID                   (0x00)
#define PORT_SET_PIN_DIRECTION_SID      (0x01)
#define PORT_REFRESH_PORT_DIRECTION_SID (0x02)
#define PORT_GET_VERISON_INFO_SID       (0x03)
#define PORT_SET_PIN_MODE_SID           (0x04)



/******************************************************************************
 *                      Custom MACRO definitions                              *
 ******************************************************************************/
#define PIN_0              0x00000001  // GPIO pin 0
#define PIN_1              0x00000002  // GPIO pin 1
#define PIN_2              0x00000004  // GPIO pin 2
#define PIN_3              0x00000008  // GPIO pin 3
#define PIN_4              0x00000010  // GPIO pin 4
#define PIN_5              0x00000020  // GPIO pin 5
#define PIN_6              0x00000040  // GPIO pin 6
#define PIN_7              0x00000080  // GPIO pin 7


/*******************************************************************************
 *                           Custom Port Module Data Types                    *
 *******************************************************************************/

typedef enum {
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTF,
}Port_PortType;

typedef enum {
    GPIODR2R = 0x00000001,   //2mA drive current
    GPIODR4R = 0x00000002,   //4mA drive current
    GPIODR8R = 0x00000066,   //8mA drive current
	NONE = 0x00,
}Port_PinStrengthType;

typedef enum {
	PUSH_PULL = 0x00000008,
    PULL_UP = 0x0000000A,    //Pull up resistor
    PULL_DOWN = 0x0000000C,  //Pull down resistor
    OPEN_DRAIN = 0x00000009, //open drain.
}Port_PinMiscType;

typedef enum {
    HIGH,
    LOW,
}Port_PinInitialLevelType;
/*******************************************************************************
 *                           Autosar Port Module Data Types                    *
 *******************************************************************************/

typedef uint8 Port_PinType;
typedef enum
{
	DEFAULT = 0x00,				//INPUT WITH PULLDOWN
    PORT_PIN_DIO_MODE,
    PORT_PIN_I2C_DATA_MODE,
    PORT_PIN_I2C_SCL_MODE,
    PORT_PIN_TIMER_CCP_MODE,
    PORT_PIN_QEI_MODE,
    PORT_PIN_PWM_MODE,
    PORT_PIN_SSI_MODE,
    PORT_PIN_UART_MODE,
    PORT_PIN_CMP_ANALOG_INPUT_MODE,
    PORT_PIN_CMP_DIGITAL_OUTPUT_MODE,
    PORT_PIN_ADC_MODE,
    PORT_PIN_CAN_MODE,
    PORT_PIN_USB_DIGITAL,
    PORT_PIN_USB_ANALOG,
}Port_PinModeType;

typedef enum {
    PORT_PIN_IN = 0x00,
    PORT_PIN_OUT,
}Port_PinDirectionType;

typedef struct {
    Port_PortType port; //port name
    Port_PinType pin; //pin number
    Port_PinModeType mode; //pin mode
    Port_PinDirectionType dir;  //pin direction
    Port_PinMiscType misc;     //pull up/ down / odr
    Port_PinStrengthType strength;
    boolean Pin_dirChangable;
    boolean Pin_ModeChangable;
    Port_PinInitialLevelType initval;
}Port_PinConfigType;

typedef struct {
    Port_PinConfigType pins[CONFIG_PINS];
}Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/******************************************************************************/
/*
 * Brief               <Initializes the Port Drive module.>
 * ServiceId           <0x00>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <ConfigPtr: Pointer to configuration set.>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <>
 */
/******************************************************************************/
extern void Port_Init(const Port_ConfigType* ConfigPtr);

/******************************************************************************/
/*
 * Brief               <Sets the port pin direction.>
 * ServiceId           <0x01>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <Pin, Direction>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <>
 */
/******************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == TRUE)
extern void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
#endif

/******************************************************************************/
/*
 * Brief               <Refreshes port direction.>
 * ServiceId           <0x02>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <>
 */
/******************************************************************************/
extern void Port_RefreshPortDirection(void);

/******************************************************************************/
/*
 * Brief               <Returns the version information of this module.>
 * ServiceId           <0x03>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <versioninfo>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <>
 */
/******************************************************************************/
#if (PORT_VERSION_INFO_API == TRUE)
extern void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif
/******************************************************************************/
/*
 * Brief               <Sets the port pin mode.>
 * ServiceId           <0x04>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <Pin, Mode>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <>
 */
/******************************************************************************/
#if (PORT_SET_PIN_MODE_API == TRUE)
extern void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

extern const Port_ConfigType Port_Configuration;
#endif /* PORT_H */
