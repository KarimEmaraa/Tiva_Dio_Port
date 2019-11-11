/*
 * Dio.c
 *
 *  Created on: Nov 10, 2019
 *      Author: Karim
 */
//Tivaware Library
#include "stdint.h"
typedef _Bool bool;	//resolving type conflicts.
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"


#include "Dio_MemMap.h"
#include "Dio.h"
#include "Det.h"
#include "SchM_Dio.h"

STATIC uint32 portBaseAddress[DIO_MAX_PORT] = { 0x40004000,	//PORTA
												0x40005000,	//PORTB
												0x40006000,	//PORTC
												0x40007000,	//PORTD
												0x40024000,	//PORTE
												0x40025000,	//PORTF
												};

/******************************************************************************/
/*
 * Brief               <Returns the value of the specified DIO channel.>
 * ServiceId           <0x00>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ChannelId>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Dio_LevelType>
 * PreCondition        <>
 * CallByAPI           <>
 */
/******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
#if (DIO_DEV_ERROR_DETECT == TRUE)
	if (DIO_CONFIGURED_CHANNLES <= ChannelId)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_READ_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
	else
	{

	}
#endif

	Dio_LevelType returnval = (Dio_LevelType)GPIOPinRead
			(
			portBaseAddress[Dio_Configuration.Channels[ChannelId].Port_Num]
			, Dio_Configuration.Channels[ChannelId].Ch_Num
			);
	return returnval;
}

/******************************************************************************/
/*
 * Brief               <Service to set a level of a channel.>
 * ServiceId           <0x01>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ChannelId> <Level>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <>
 */
/******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
#if (DIO_DEV_ERROR_DETECT == TRUE)
	if (DIO_CONFIGURED_CHANNLES <= ChannelId)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
						DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
	else
	{

	}
#endif

	GPIOPinWrite((uint32)portBaseAddress[Dio_Configuration.Channels[ChannelId].Port_Num],
									 (uint8)Dio_Configuration.Channels[ChannelId].Ch_Num,
									 (uint8)Level);

}

/******************************************************************************/
/*
 * Brief               <Returns the level of all channels of that port.>
 * ServiceId           <0x02>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <PortId>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Dio_PortLevelType>
 * PreCondition        <>
 * CallByAPI           <>
 */
/******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
#if (DIO_DEV_ERROR_DETECT == TRUE)
	if (DIO_MAX_PORT <= PortId)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
						DIO_READ_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
	}
	else
	{

	}
#endif
	Dio_PortLevelType returnval = (Dio_PortLevelType)GPIOPinRead(portBaseAddress[PortId], 0xff);
		return returnval;
}

/******************************************************************************/
/*
 * Brief               <Service to set a value of the port.>
 * ServiceId           <0x03>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <PortId> <Level>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <PortLevelType>
 * PreCondition        <>
 * CallByAPI           <>
 */
/******************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
#if (DIO_DEV_ERROR_DETECT == TRUE)
	if (DIO_CONFIGURED_CHANNLES <= PortId)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
						DIO_WRITE_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
	}
	else
	{

	}
#endif

	GPIOPinWrite((uint32)portBaseAddress[PortId], 0xffU, (uint8)Level);
}

/******************************************************************************/
/*
 * Brief               <This Service reads a subset of the adjoining bits of a port.>
 * ServiceId           <0x04>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ChannelGroupIdPtr>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Dio_PortLevelType>
 * PreCondition        <>
 * CallByAPI           <>
 */
/******************************************************************************/
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
#if (DIO_DEV_ERROR_DETECT == TRUE)
	if (NULL_PTR == ChannelGroupIdPtr)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
						DIO_READ_CHANNEL_GROUP_SID, DIO_E_PARAM_POINTER);
	}
	else
	{

	}
#endif
	Dio_PortLevelType returnval = (Dio_PortLevelType)GPIOPinRead(
			portBaseAddress[ChannelGroupIdPtr->PortIndex],
			ChannelGroupIdPtr->mask
			);
		return returnval;
}
/******************************************************************************/
/*
 * Brief               <Service to set a subset of the adjoining bits of a port to a specified level.>
 * ServiceId           <0x05>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ChannelGroupIdPtr> <Level>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <>
 */
/******************************************************************************/
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level)
{
#if (DIO_DEV_ERROR_DETECT == TRUE)
	if (NULL_PTR == ChannelGroupIdPtr)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
						DIO_WRITE_CHANNEL_GROUP_SID, DIO_E_PARAM_POINTER);
	}
	else
	{

	}
#endif
	GPIOPinWrite(
			(uint32)portBaseAddress[ChannelGroupIdPtr->PortIndex],
			(uint8)ChannelGroupIdPtr->mask,
			(uint8)Level);

}

/******************************************************************************/
/*
 * Brief               <Service to get the version information of this module.>
 * ServiceId           <0x12>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <VersionInfo>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <>
 */
/******************************************************************************/
#if (DIO_VERSION_INFO_API == TRUE)
void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_GET_VERSION_INFO_SID, DIO_E_PARAM_POINTER);
	}
	else
#endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)DIO_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)DIO_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)DIO_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)DIO_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)DIO_SW_PATCH_VERSION;
	}
}
#endif

/******************************************************************************/
/*
 * Brief               <Service to flip (change from 1 to 0 or from 0 to 1)
 * 						the level of a channel and return the level of the channel after flip..>
 * ServiceId           <0x11>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ChannelId>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Dio_LevelType>
 * PreCondition        <>
 * CallByAPI           <>
 */
/******************************************************************************/

#if (DIO_FLIP_CHANNEL_API == TRUE)
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
#if (DIO_DEV_ERROR_DETECT == TRUE)
	if (DIO_CONFIGURED_CHANNLES <= ChannelId)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_FLIP_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
	else
	{

	}
#endif

	Dio_LevelType returnval = (Dio_LevelType)GPIOPinRead
				(
				portBaseAddress[Dio_Configuration.Channels[ChannelId].Port_Num]
				, Dio_Configuration.Channels[ChannelId].Ch_Num
				);

	returnval ^= 1;

	PIOPinWrite((uint32)portBaseAddress[Dio_Configuration.Channels[ChannelId].Port_Num],
										 (uint8)Dio_Configuration.Channels[ChannelId].Ch_Num,
										 (uint8)returnval);
	return returnval;

}
#endif



