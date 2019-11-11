/*
 * Dio.h
 *
 *  Created on: Nov 10, 2019
 *      Author: Karim
 */

#ifndef DIO_H
#define DIO_H

#define DIO_VENDOR_ID    (1000U)

/* Dio Module Id */
#define DIO_MODULE_ID    (120U)

/* Dio Instance Id */
#define DIO_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define DIO_SW_MAJOR_VERSION           (1U)
#define DIO_SW_MINOR_VERSION           (0U)
#define DIO_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define DIO_AR_RELEASE_MAJOR_VERSION   (4U)
#define DIO_AR_RELEASE_MINOR_VERSION   (3U)
#define DIO_AR_RELEASE_PATCH_VERSION   (1U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Dio Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Dio Pre-Compile Configuration Header file */
#include "Dio_Cfg.h"

/* AUTOSAR Version checking between Dio_Cfg.h and Dio.h files */
#if ((DIO_CFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Dio_Cfg.h does not match the expected version"
#endif

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for DIO read Channel */
#define DIO_READ_CHANNEL_SID           (uint8)0x00

/* Service ID for DIO write Channel */
#define DIO_WRITE_CHANNEL_SID          (uint8)0x01

/* Service ID for DIO read Port */
#define DIO_READ_PORT_SID              (uint8)0x02

/* Service ID for DIO write Port */
#define DIO_WRITE_PORT_SID             (uint8)0x03

/* Service ID for DIO read Channel Group */
#define DIO_READ_CHANNEL_GROUP_SID     (uint8)0x04

/* Service ID for DIO write Channel Group */
#define DIO_WRITE_CHANNEL_GROUP_SID    (uint8)0x05

/* Service ID for DIO GetVersionInfo */
#define DIO_GET_VERSION_INFO_SID       (uint8)0x12

/* Service ID for DIO flip Channel */
#define DIO_FLIP_CHANNEL_SID           (uint8)0x11

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Channel */
#define DIO_E_PARAM_INVALID_CHANNEL_ID (uint8)0x0A

/* Dio_Init API service called with NULL pointer parameter */
#define DIO_E_PARAM_CONFIG             (uint8)0x10

/* DET code to report Invalid Port */
#define DIO_E_PARAM_INVALID_PORT_ID    (uint8)0x14

/* DET code to report Invalid Channel Group */
#define DIO_E_PARAM_INVALID_GROUP      (uint8)0x1F

/*
 * The API service shall return immediately without any further action,
 * beside reporting this development error.
 */
#define DIO_E_PARAM_POINTER             (uint8)0x20

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8 Dio_ChannelType;

/* Type definition for Dio_PortType used by the DIO APIs */
typedef uint8 Dio_PortType;

/* Type definition for Dio_LevelType used by the DIO APIs */
typedef uint8 Dio_LevelType;

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint8 Dio_PortLevelType;

/* Structure for Dio_ChannelGroup */
typedef struct
{
  /* Mask which defines the positions of the channel group */
  uint8 mask;
  /* Position of the group from LSB */
  uint8 offset;
  /* This shall be the port on which the Channel group is defined. */
  Dio_PortType PortIndex;
} Dio_ChannelGroupType;

typedef enum{
	DIO_PORTA = 0,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD,
	DIO_PORTE,
	DIO_PORTF,
}Dio_PortId;

typedef struct
{
	Dio_PortId Port_Num;
	uint8 Ch_Num;
}Dio_ConfigChannel;

/* Data Structure required for Dio Driver */
typedef struct
{
	Dio_ConfigChannel Channels[DIO_CONFIGURED_CHANNLES];
} Dio_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/


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
extern Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

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
extern void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

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
extern Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

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
extern void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

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
extern Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);

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
extern void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);

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
extern void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo);
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
extern Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
#endif



/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Dio and other modules */
extern const Dio_ConfigType Dio_Configuration;

#endif /* DIO_H_ */
