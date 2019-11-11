/*
 * Port.c
 *
 *  Created on: Nov 9, 2019
 *      Author: Karim
 */


//Tivaware Library
#include "stdint.h"
typedef _Bool bool;	//resolving type conflicts.
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

//Autosar Dependencies.
#include "Port.h"
#include "Port_MemMap.h"
#include "Det.h"
#include "SchM_Port.h"

#if (DIO_DEV_ERROR_DETECT == TRUE)

#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC uint32 portBaseAddress[NUM_OF_PORTS] = { 0x40004000,	//PORTA
												0x40005000,	//PORTB
												0x40006000,	//PORTC
												0x40007000,	//PORTD
												0x40024000,	//PORTE
												0x40025000,	//PORTF
};

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
void Port_Init(const Port_ConfigType * ConfigPtr)
{
#if (PORT_DEV_ERROR_DETECT == TRUE)
	if(NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_INIT_FAILED);
	}
	else
	{

	}
#endif
	for(uint32 i = 0; i < CONFIG_PINS; i++)
	{
		uint32 portmask = 0xf0000800 | ConfigPtr->pins[i].port;
		SysCtlPeripheralEnable(portmask);
		//Check if peripheral is enabled.
		while(!SysCtlPeripheralReady(portmask));
		switch(ConfigPtr->pins[i].mode)
		{
			case	PORT_PIN_DIO_MODE:
					if (PORT_PIN_IN == ConfigPtr->pins[i].dir )
					{
						#if (PORT_DEV_ERROR_DETECT == TRUE)
							if(OPEN_DRAIN == ConfigPtr->pins[i].misc || ConfigPtr->pins[i].strength != NONE)
							{
								Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_INIT_FAILED);
							}
							else
							{

							}
						#endif

						GPIOPinTypeGPIOInput(portBaseAddress[ConfigPtr->pins[i].port],
											 ConfigPtr->pins[i].pin);

						GPIOPadConfigSet(portBaseAddress[ConfigPtr->pins[i].port],
										 ConfigPtr->pins[i].pin ,
										 ConfigPtr->pins[i].strength ,
										 ConfigPtr->pins[i].misc);
					}
					else if(PORT_PIN_OUT == ConfigPtr->pins[i].dir)
					{
						#if (PORT_DEV_ERROR_DETECT == TRUE)
							if(PULL_DOWN == ConfigPtr->pins[i].misc || PULL_UP == ConfigPtr->pins[i].misc )
							{
								Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_INIT_FAILED);
							}
							else
							{

							}
						#endif
						GPIOPinTypeGPIOOutput(portBaseAddress[ConfigPtr->pins[i].port],
											  ConfigPtr->pins[i].pin);

						GPIOPadConfigSet(portBaseAddress[ConfigPtr->pins[i].port],
																 ConfigPtr->pins[i].pin ,
																 ConfigPtr->pins[i].strength ,
																 ConfigPtr->pins[i].misc);

						if(ConfigPtr->pins[i].initval == HIGH)
						{
							GPIOPinWrite(portBaseAddress[ConfigPtr->pins[i].port],
															 ConfigPtr->pins[i].pin,
															 ConfigPtr->pins[i].pin);
						}
						else
						{
							GPIOPinWrite(portBaseAddress[ConfigPtr->pins[i].port],
										ConfigPtr->pins[i].pin,
										0x00);
						}
					}
				break;
			case 	PORT_PIN_I2C_DATA_MODE:
				break;
			case	PORT_PIN_I2C_SCL_MODE:
				break;
			case 	PORT_PIN_TIMER_CCP_MODE:
				break;
			case 	PORT_PIN_QEI_MODE:
				break;
			case 	PORT_PIN_PWM_MODE:
				break;
			case    PORT_PIN_SSI_MODE:
				break;
			case    PORT_PIN_UART_MODE:
				break;
			case    PORT_PIN_CMP_ANALOG_INPUT_MODE:
				break;
			case    PORT_PIN_CMP_DIGITAL_OUTPUT_MODE:
				break;
			case    PORT_PIN_ADC_MODE:
				break;
			case    PORT_PIN_CAN_MODE:
				break;
			case    PORT_PIN_USB_DIGITAL:
				break;
			case    PORT_PIN_USB_ANALOG:
				break;
			default:

					GPIOPinTypeGPIOInput(portBaseAddress[ConfigPtr->pins[i].port],
															 ConfigPtr->pins[i].pin);

					GPIOPadConfigSet(portBaseAddress[ConfigPtr->pins[i].port],
															 ConfigPtr->pins[i].pin ,
															 NONE ,
															 PULL_DOWN);
				break;
		}
	}
}

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
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{

}
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
void Port_RefreshPortDirection(void)
{

}

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
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
#if (PORT_DEV_ERROR_DETECT == TRUE)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_GET_VERISON_INFO_SID, PORT_E_PARAM_POINTER);
	}
	else
#endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
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
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
#if (PORT_DEV_ERROR_DETECT == TRUE)
	if((uint32)Pin >= CONFIG_PINS)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
						PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
	}
	else if((uint32)Mode > (uint32)PORT_PIN_USB_ANALOG)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
								PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
	}
	else if(Port_Configuration.pins[Pin].Pin_ModeChangable != TRUE)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
										PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
	}
	else
	{

	}
#endif

	switch(Port_Configuration.pins[Pin].mode)
			{
				case	PORT_PIN_DIO_MODE:
						if (PORT_PIN_IN == Port_Configuration.pins[Pin].dir )
						{
							GPIOPinTypeGPIOInput(portBaseAddress[Port_Configuration.pins[Pin].port],
												 Port_Configuration.pins[Pin].pin);


						}
						else if(PORT_PIN_OUT == Port_Configuration.pins[Pin].dir)
						{

							GPIOPinTypeGPIOOutput(portBaseAddress[Port_Configuration.pins[Pin].port],
												  Port_Configuration.pins[Pin].pin);


							if(Port_Configuration.pins[Pin].initval == HIGH)
							{
								GPIOPinWrite(portBaseAddress[Port_Configuration.pins[Pin].port],
																 Port_Configuration.pins[Pin].pin,
																 Port_Configuration.pins[Pin].pin);
							}
							else
							{
								GPIOPinWrite(portBaseAddress[Port_Configuration.pins[Pin].port],
											Port_Configuration.pins[Pin].pin,
											0x00);
							}
						}
					break;
				case 	PORT_PIN_I2C_DATA_MODE:
					break;
				case	PORT_PIN_I2C_SCL_MODE:
					break;
				case 	PORT_PIN_TIMER_CCP_MODE:
					break;
				case 	PORT_PIN_QEI_MODE:
					break;
				case 	PORT_PIN_PWM_MODE:
					break;
				case    PORT_PIN_SSI_MODE:
					break;
				case    PORT_PIN_UART_MODE:
					break;
				case    PORT_PIN_CMP_ANALOG_INPUT_MODE:
					break;
				case    PORT_PIN_CMP_DIGITAL_OUTPUT_MODE:
					break;
				case    PORT_PIN_ADC_MODE:
					break;
				case    PORT_PIN_CAN_MODE:
					break;
				case    PORT_PIN_USB_DIGITAL:
					break;
				case    PORT_PIN_USB_ANALOG:
					break;
				default:

						GPIOPinTypeGPIOInput(portBaseAddress[Port_Configuration.pins[Pin].port],
																 Port_Configuration.pins[Pin].pin);

						GPIOPadConfigSet(portBaseAddress[Port_Configuration.pins[Pin].port],
																 Port_Configuration.pins[Pin].pin ,
																 NONE ,
																 PULL_DOWN);
					break;
			}
}
#endif
