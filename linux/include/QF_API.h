/**
 *  	QFM SDK Main API
 */

/*
 *  Copyright (c) 2021-current Suprema AI Inc. All Rights Reserved.
 *
 *  This software is the confidential and proprietary information of
 *  Suprema AI Inc. ("Confidential Information").  You shall not
 *  disclose such Confidential Information and shall use it only in
 *  accordance with the terms of the license agreement you entered into
 *  with Suprema.
 */

#ifndef __QFM_SDK_API__
#define __QFM_SDK_API__

#ifdef _WIN32
#include <windows.h>
#include <winsock.h>
#endif // _WIN32

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "QF_Def.h"
#include "QF_Error.h"
#include "QF_Packet.h"
#include "QF_Command.h"
#include "QF_SysParameter.h"
#include "QF_Template.h"
#include "QF_Module.h"
#include "QF_Enroll.h"
#include "QF_Image.h"
#include "QF_Delete.h"
#include "QF_Serial.h"
#include "QF_Upgrade.h"
#include "QF_Socket.h"

#ifdef __cplusplus
extern "C"
{
#endif

    //
    // SDK version
    //
    QF_API void QF_GetSDKVersion(int *major, int *minor, int *revision);
    QF_API const char* QF_GetSDKVersionString();

    //
    // Initialize serial communication
    //
    QF_API QF_RET_CODE QF_InitCommPort(const char *commPort, int baudrate, BOOL asciiMode);
    QF_API QF_RET_CODE QF_CloseCommPort();
    QF_API QF_RET_CODE QF_InitSocket(const char *inetAddr, int port, BOOL asciiMode);
    QF_API QF_RET_CODE QF_CloseSocket();
    QF_API void QF_Reconnect();
    QF_API QF_RET_CODE QF_SetBaudrate(int baudrate);
    QF_API void QF_SetAsciiMode(BOOL asciiMode);


    //
    // Callback functions for the user-defined UART handler (Android)
    //

    // Set baudrate to the host handler of the user-defined UART handler
    QF_API void QF_SetSetupSerialCallback(void (*Callback)(int));
    // Read serial data by the host handler of the user-defined UART handler
    QF_API void QF_SetReadSerialCallback(int (*Callback)(BYTE *, int, int));
    // Write serial data by the host handler of the user-defined UART handler
    QF_API void QF_SetWriteSerialCallback(int (*Callback)(BYTE *, int, int));

    //
    // Basic packet interface
    //
    QF_API QF_RET_CODE QF_SendPacket(BYTE command, UINT32 param, UINT32 size, BYTE flag, int timeout);
    QF_API QF_RET_CODE QF_ReceivePacket(BYTE *packet, int timeout);
    QF_API QF_RET_CODE QF_SendRawData(BYTE *buf, UINT32 size, int timeout);
    QF_API QF_RET_CODE QF_ReceiveRawData(BYTE *buf, UINT32 size, int timeout, BOOL checkEndCode);
    QF_API QF_RET_CODE QF_SendDataPacket(BYTE command, BYTE *buf, UINT32 dataSize, UINT32 dataPacketSize);
    QF_API QF_RET_CODE QF_ReceiveDataPacket(BYTE command, BYTE *buf, UINT32 dataSize);
    QF_API void QF_SetSendPacketCallback(void (*Callback)(BYTE *));
    QF_API void QF_SetReceivePacketCallback(void (*Callback)(BYTE *));
    QF_API void QF_SetSendDataPacketCallback(void (*Callback)(int index, int numOfPacket));
    QF_API void QF_SetReceiveDataPacketCallback(void (*Callback)(int index, int numOfPacket));
    QF_API void QF_SetSendRawDataCallback(void (*Callback)(int writtenLen, int totalSize));
    QF_API void QF_SetReceiveRawDataCallback(void (*Callback)(int readLen, int totalSize));
    QF_API void QF_SetDefaultPacketSize(int defaultSize);
    QF_API int QF_GetDefaultPacketSize();

    //
    // Generic command interface
    //
    
    QF_API void QF_SetGenericCommandTimeout(int timeout);
    QF_API void QF_SetInputCommandTimeout(int timeout);
    QF_API int QF_GetGenericCommandTimeout();
    QF_API int QF_GetInputCommandTimeout();
    QF_API QF_RET_CODE QF_Command(BYTE command, UINT32 *param, UINT32 *size, BYTE *flag);
    QF_API QF_RET_CODE QF_CommandEx(BYTE command, UINT32 *param, UINT32 *size, BYTE *flag, BOOL (*msgCallback)(BYTE));
    QF_API QF_RET_CODE QF_CommandSendData(BYTE command, UINT32 *param, UINT32 *size, BYTE *flag, BYTE *data, UINT32 dataSize);
    QF_API QF_RET_CODE QF_CommandSendDataEx(BYTE command, UINT32 *param, UINT32 *size, BYTE *flag, BYTE *data, UINT32 dataSize, BOOL (*msgCallback)(BYTE), BOOL waitUserInput);
    QF_API QF_RET_CODE QF_Cancel(BOOL receivePacket);
    QF_API QF_RET_CODE QF_GetErrorCode(QF_PROTOCOL_RET_CODE retCode);

    //
    // Module information
    //
    QF_API QF_RET_CODE QF_GetModuleInfo(QF_MODULE_TYPE *type, QF_MODULE_VERSION *version, QF_HARDWARE_REVISION *hardware_revision);
    QF_API char *QF_GetModuleString(QF_MODULE_TYPE type, QF_MODULE_VERSION version, QF_HARDWARE_REVISION hardware_revision);
    QF_API QF_RET_CODE QF_SearchModule(const char *port, int *baudrate, BOOL *asciiMode, QF_PROTOCOL *protocol, UINT32 *moduleID, void (*callback)(const char *comPort, int baudrate));
    QF_API QF_RET_CODE QF_SearchModuleBySocket(const char *inetAddr, int tcpPort, BOOL *asciiMode, QF_PROTOCOL *protocol, UINT32 *moduleID);

        
    QF_API QF_RET_CODE QF_Reset();
    
    //
    // System parameters
    //
    QF_API void QF_InitSysParameter();
    QF_API QF_RET_CODE QF_GetSysParameter(QF_SYS_PARAM parameter, UINT32 *value);
    QF_API QF_RET_CODE QF_SetSysParameter(QF_SYS_PARAM parameter, UINT32 value);
    QF_API QF_RET_CODE QF_GetMultiSysParameter(int parameterCount, QF_SYS_PARAM *parameters, UINT32 *values);
    QF_API QF_RET_CODE QF_SetMultiSysParameter(int parameterCount, QF_SYS_PARAM *parameters, UINT32 *values);
    QF_API QF_RET_CODE QF_Save();

    //
    // Template management
    //
    QF_API QF_RET_CODE QF_GetNumOfTemplate(UINT32 *numOfTemplate);
    QF_API QF_RET_CODE QF_GetMaxNumOfTemplate(UINT32 *maxNumOfTemplate);
    QF_API QF_RET_CODE QF_GetAllUserInfo(QFUserInfo *userInfo, UINT32 *numOfUser, UINT32 *numOfTemplate);
    QF_API QF_RET_CODE QF_GetAllUserInfoEx(QFUserInfoEx *userInfo, UINT32 *numOfUser, UINT32 *numOfTemplate);
    QF_API void QF_SortUserInfo(QFUserInfo *userInfo, int numOfUser);
    QF_API void QF_SetUserInfoCallback(void (*callback)(int index, int numOfTemplate));
    QF_API QF_RET_CODE QF_SaveDB(const char *fileName);
    QF_API QF_RET_CODE QF_LoadDB(const char *fileName);
    QF_API QF_RET_CODE QF_CheckTemplate(UINT32 userID, UINT32 *numOfTemplate);
    QF_API QF_RET_CODE QF_ReadTemplate(UINT32 userID, UINT32 *numOfTemplate, BYTE *templateData);
    QF_API QF_RET_CODE QF_ReadOneTemplate(UINT32 userID, int subID, BYTE *templateData);
    QF_API void QF_SetScanCallback(void (*Callback)(BYTE));
    QF_API QF_RET_CODE QF_ScanTemplate(BYTE *templateData, UINT32 *templateSize, UINT32 *imageQuality);

    //
    // Image
    //    
    QF_API QF_RET_CODE QF_ReadImage(QFImage *image);
    QF_API QF_RET_CODE QF_ScanImage(QFImage *image);
#ifdef _WIN32
    QF_API HBITMAP QF_ConvertToBitmap(QFImage *image);
#endif

    //
    // Identify
    //
    QF_API void QF_SetIdentifyCallback(void (*Callback)(BYTE));
    QF_API QF_RET_CODE QF_Identify(UINT32 *userID, BYTE *subID);
    QF_API QF_RET_CODE QF_IdentifyTemplate(UINT32 templateSize, BYTE *templateData, UINT32 *userID, BYTE *subID);
    QF_API QF_RET_CODE QF_IdentifyImage(UINT32 imageSize, BYTE *imageData, UINT32 *userID, BYTE *subID);

    //
    // Verify
    //
    QF_API void QF_SetVerifyCallback(void (*Callback)(BYTE));
    QF_API QF_RET_CODE QF_Verify(UINT32 userID, BYTE *subID);
    QF_API QF_RET_CODE QF_VerifyTemplate(UINT32 templateSize, BYTE *templateData, UINT32 userID, BYTE *subID);
    QF_API QF_RET_CODE QF_VerifyHostTemplate(UINT32 numOfTemplate, UINT32 templateSize, BYTE *templateData);
    QF_API QF_RET_CODE QF_VerifyImage(UINT32 imageSize, BYTE *imageData, UINT32 userID, BYTE *subID);

    //
    // Enroll
    //
    QF_API void QF_SetEnrollCallback(void (*Callback)(BYTE errCode, QF_ENROLL_MODE enrollMode, int numOfSuccess));
    QF_API QF_RET_CODE QF_Enroll(UINT32 userID, QF_ENROLL_OPTION option, UINT32 *enrollID, UINT32 *imageQuality);
    QF_API QF_RET_CODE QF_EnrollTemplate(UINT32 userID, QF_ENROLL_OPTION option, UINT32 templateSize, BYTE *templateData, UINT32 *enrollID);
    QF_API QF_RET_CODE QF_EnrollMultipleTemplates(UINT32 userID, QF_ENROLL_OPTION option, int numOfTemplate, UINT32 templateSize, BYTE *templateData, UINT32 *enrollID);
    QF_API QF_RET_CODE QF_EnrollImage(UINT32 userID, QF_ENROLL_OPTION option, UINT32 imageSize, BYTE *imageData, UINT32 *enrollID, UINT32 *imageQuality);

    //
    // Delete
    //
    QF_API void QF_SetDeleteCallback(void (*Callback)(BYTE));
    QF_API QF_RET_CODE QF_Delete(UINT32 userID);
    QF_API QF_RET_CODE QF_DeleteOneTemplate(UINT32 userID, int subID);
    QF_API QF_RET_CODE QF_DeleteMultipleTemplates(UINT32 startUserID, UINT32 lastUserID, int *deletedUserID);
    QF_API QF_RET_CODE QF_DeleteAll();


    //
    // Upgrade
    //
    QF_API QF_RET_CODE QF_Upgrade(const char *firmwareFilename, int dataPacketSize);

    //
    // FileSystem (in QF_Upgrade.c)
    //
    QF_API QF_RET_CODE QF_FormatUserDatabase();
    QF_API QF_RET_CODE QF_ResetSystemConfiguration();


#ifdef __cplusplus
}
#endif

#endif
