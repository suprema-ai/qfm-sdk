/**
 *  	System Parameters
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

#ifndef __QFM_SDK_SYSPARAMETER_H__
#define __QFM_SDK_SYSPARAMETER_H__

#include "QF_API.h"
#include "QF_Error.h"

#define QF_SYS_PARAMETER_NOT_FOUND 0xffffffff
#define QF_SYS_PARAMETER_NOT_READ 0x00

typedef struct
{
	int parameter;
	UINT32 value;
} SysParameter;

/* System Parameter */
extern SysParameter s_SysParameter[];

/* System Parameter List (String Name)*/
extern char s_SysParameterList[][30];

typedef enum
{
	QF_SYS_TIMEOUT = 0x62,
	QF_SYS_TEMPLATE_SIZE = 0x64,
	QF_SYS_ENROLL_MODE = 0x65,
	QF_SYS_SECURITY_LEVEL = 0x66,
	QF_SYS_ENCRYPTION_MODE = 0x67,
	QF_SYS_FIRMWARE_VERSION = 0x6e,
	QF_SYS_SERIAL_NUMBER = 0x6f,
	QF_SYS_BAUDRATE = 0x71,
	QF_SYS_ENROLLED_TEMPLATES = 0x73,
	QF_SYS_AVAILABLE_TEMPLATES = 0x74,
	QF_SYS_SEND_SCAN_SUCCESS = 0x75,
	QF_SYS_ASCII_PACKET = 0x76,
	QF_SYS_ROTATE_IMAGE = 0x77,
	QF_SYS_SENSITIVITY = 0x80,
	QF_SYS_IMAGE_QUALITY = 0x81,
	QF_SYS_AUTO_RESPONSE = 0x82,
	QF_SYS_FREE_SCAN = 0x84,
	QF_SYS_PROVISIONAL_ENROLL = 0x85,
	QF_SYS_RESPONSE_DELAY = 0x87,
	QF_SYS_MATCHING_TIMEOUT = 0x88,
	QF_SYS_BUILD_NUMBER = 0x89,
	QF_SYS_LIGHTING_CONDITION = 0x90,
	QF_SYS_FREESCAN_DELAY = 0x91,
	QF_SYS_TEMPLATE_TYPE = 0x96,
	QF_SYS_FAKE_DETECTION = 0x98,
	QF_SYS_PROTOCOL_INTERFACE = 0X9e,
	QF_SYS_KERNEL_VERSION = 0xa3,
	QF_SYS_RESERVED = 0xff,
} QF_SYS_PARAM;

#define QF_VALID_CONFIG_FILE 0xf1f2f3f4

#ifdef __cplusplus
extern "C"
{
#endif

	QF_RET_CODE QF_ReadSysParameter(QF_SYS_PARAM parameter, UINT32 *value);
	QF_RET_CODE QF_WriteSysParameter(QF_SYS_PARAM parameter, UINT32 value);
	QF_RET_CODE QF_ReadMultiSysParameter(int parameterCount, QF_SYS_PARAM *parameters, UINT32 *values);
	QF_RET_CODE QF_WriteMultiSysParameter(int parameterCount, QF_SYS_PARAM *parameters, UINT32 *values);

#ifdef __cplusplus
}
#endif

#endif
