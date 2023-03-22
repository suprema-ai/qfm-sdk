/**
 * @file QF_SysParameter.h
 * @brief System Parameter API
 * @copyright This software is the confidential and proprietary information of Suprema AI Inc. ("Confidential Information").  You shall not disclose such Confidential Information and shall use it only in accordance with the terms of the license agreement you entered into with Suprema AI Inc.
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

/**
 * @brief Parameter ID
 */
typedef enum
{
	/*! Timeout */
	QF_SYS_TIMEOUT = 0x62,

	/*! Template size */
	QF_SYS_TEMPLATE_SIZE = 0x64,

	/*! Enrollment mode */
	QF_SYS_ENROLL_MODE = 0x65,

	/*! Security level */
	QF_SYS_SECURITY_LEVEL = 0x66,

	/*! Encryption mode */
	QF_SYS_ENCRYPTION_MODE = 0x67,

	/*! Firmware version */
	QF_SYS_FIRMWARE_VERSION = 0x6e,

	/*! Serial number */
	QF_SYS_SERIAL_NUMBER = 0x6f,

	/*! Baudrate */
	QF_SYS_BAUDRATE = 0x71,

	/*! Number of enrolled templates */
	QF_SYS_ENROLLED_TEMPLATES = 0x73,

	/*! Number of available templates */
	QF_SYS_AVAILABLE_TEMPLATES = 0x74,

	/*! Scan success */
	QF_SYS_SEND_SCAN_SUCCESS = 0x75,

	/*! ASCII packet */
	QF_SYS_ASCII_PACKET = 0x76,

	/*! Rotate image */
	QF_SYS_ROTATE_IMAGE = 0x77,

	/*! Sensitivity */
	QF_SYS_SENSITIVITY = 0x80,

	/*! Image quality */
	QF_SYS_IMAGE_QUALITY = 0x81,

	/*! Auto response */
	QF_SYS_AUTO_RESPONSE = 0x82,

	/*! Free scan mode */
	QF_SYS_FREE_SCAN = 0x84,

	/*! Provisional enrollment */
	QF_SYS_PROVISIONAL_ENROLL = 0x85,

	/*! Response delay */
	QF_SYS_RESPONSE_DELAY = 0x87,

	/*! Matching timeout */
	QF_SYS_MATCHING_TIMEOUT = 0x88,

	/*! Build number */
	QF_SYS_BUILD_NUMBER = 0x89,

	/*! Lighing Condition */
	QF_SYS_LIGHTING_CONDITION = 0x90,

	/*! Freescan delay */
	QF_SYS_FREESCAN_DELAY = 0x91,

	/*! Template type */
	QF_SYS_TEMPLATE_TYPE = 0x96,

	/*! Fake detection */
	QF_SYS_FAKE_DETECTION = 0x98,

	/*! Protocol interface */
	QF_SYS_PROTOCOL_INTERFACE = 0X9e,

	/*! Kernel version */
	QF_SYS_KERNEL_VERSION = 0xa3,

	/*! Mask check level */
	QF_SYS_MASK_CHECK_LEVEL = 0xb1,
	
	/*! User feedback */
	QF_SYS_USER_FEEDBACK = 0xb2,
	QF_SYS_RESERVED = 0xff,
} QF_SYS_PARAM;

#define QF_VALID_CONFIG_FILE 0xf1f2f3f4

#endif
