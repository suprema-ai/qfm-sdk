/**
 * @file QF_Error.h
 * @brief Error code definition
 * @copyright This software is the confidential and proprietary information of Suprema AI Inc. ("Confidential Information").  You shall not disclose such Confidential Information and shall use it only in accordance with the terms of the license agreement you entered into with Suprema AI Inc.
 */

#ifndef __QFM_SDK_ERROR_H__
#define __QFM_SDK_ERROR_H__

#include "QF_Def.h"

/**
 * @brief Return code of the SDK
 * 
 */
typedef enum
{

	/*! The function succeeds */
	QF_RET_SUCCESS = 0,

	/*! Cannot open the specified serial port */
	QF_ERR_CANNOT_OPEN_SERIAL = -1,

	/*! Cannot set the baud rate.*/
	QF_ERR_CANNOT_SETUP_SERIAL = -2,

	/*! Cannot write data to the serial port */
	QF_ERR_CANNOT_WRITE_SERIAL = -3,

	/*! Write timeout */
	QF_ERR_WRITE_SERIAL_TIMEOUT = -4,

	/*! Cannot read data from the serial port */
	QF_ERR_CANNOT_READ_SERIAL = -5,

	/*! Read timeout */
	QF_ERR_READ_SERIAL_TIMEOUT = -6,

	/*! Received packet has wrong checksum */
	QF_ERR_CHECKSUM_ERROR = -7,

	/*! Cannot set communication timeout */
	QF_ERR_CANNOT_SET_TIMEOUT = -8,

	/*! Cannot initialize the socket interface */
	QF_ERR_CANNOT_START_SOCKET = -301,

	/*! Cannot open the socket */
	QF_ERR_CANNOT_OPEN_SOCKET = -302,

	/*! Cannot connect to the socket */
	QF_ERR_CANNOT_CONNECT_SOCKET = -303,

	/*! Cannot read data from the socket */
	QF_ERR_CANNOT_READ_SOCKET = -304,

	/*! Read timeout */
	QF_ERR_READ_SOCKET_TIMEOUT = -305,

	/*! Cannot write data to the socket */
	QF_ERR_CANNOT_WRITE_SOCKET = -306,

	/*! Write timeout */
	QF_ERR_WRITE_SOCKET_TIMEOUT = -307,

	/*! The function fails */
	QF_ERR_FAILED = -100,

	/*! Face input has failed */
	QF_ERR_SCAN_FAIL = -101,

	/*! Identification failed, or the requested data is not found */
	QF_ERR_NOT_FOUND = -102,

	/*! Face does not match */
	QF_ERR_NOT_MATCH = -103,
	
	/*! Face image quality is not good */
	QF_ERR_TRY_AGAIN = -104,

	/*! Timeout for face input */
	QF_ERR_TIME_OUT = -105,

	/*! No more templates are allowed */
	QF_ERR_MEM_FULL = -106,

	/*! The specified user ID already exists */
	QF_ERR_EXIST_ID = -107,

	/*! The number of faces enrolled in same ID exceeds its limit */
	QF_ERR_FACE_TEMPLATE_LIMIT = -108,

	/*! The command is not supported */
	QF_ERR_UNSUPPORTED = -109,

	/*! The requested user ID is invalid or missing */
	QF_ERR_INVALID_ID = -110,

	/*! Timeout for face identification. */
	QF_ERR_TIMEOUT_MATCH = -111,

	/*! Module is processing another command */
	QF_ERR_BUSY = -112,

	/*! The command is canceled */
	QF_ERR_CANCELED = -113,

	/*! The checksum of a data packet is incorrect */
	QF_ERR_DATA_ERROR = -114,

	/*! The face is already enrolled */
	QF_ERR_EXIST_FACE = -115,

	/*! Scanned face is determined as a fake face */
	QF_ERR_FAKE_DETECTED = -122,

	/*! Out of memory */
	QF_ERR_OUT_OF_MEMORY = -200,

	/*! Invalid parameter */
	QF_ERR_INVALID_PARAMETER = -201,

	/*! File I/O failed */
	QF_ERR_FILE_IO = -202,

	/*! The configuration or DB file is invalid */
	QF_ERR_INVALID_FILE = -203,

	/*! Firmware is invalid */
	QF_ERR_INVALID_FIRMWARE = -204,

	/*! Module is failed to start booting */
	QF_ERR_RECOVERY_MODE = -401,

	/*! Module has no serial number */
	QF_ERR_NO_SERIAL_NUMBER = -402,

	/*! The format of the DB file is invalid */
	QF_ERR_INVALID_DATABASE_FORMAT = -403,

	/*! Image format is wrong */
	QF_ERR_WRONG_IMAGE_FORMAT = -404,

	/*! Image size is wrong */
	QF_ERR_WRONG_IMAGE_SIZE = -405,

	/*! Cannot verify the secure code for the secure packet protocol */
	QF_ERR_SECURE_CODE_VERIFICATION_FAIL = -501,

	/*! Unknown error */
	QF_ERR_UNKNOWN = -9999,
} QF_RET_CODE;

/**
 * @brief Return code of the protocol.
 * This is used for the protocol between the host and the module
 * 
 */
typedef enum
{
	/*! Failed */
	QF_PROTO_RET_FAILED = 0x60,

	/*! Successfully completed. */
	QF_PROTO_RET_SUCCESS = 0x61,

	/*! Face input has succeeded. */
	QF_PROTO_RET_SCAN_SUCCESS = 0x62,

	/*! Face input has failed. */
	QF_PROTO_RET_SCAN_FAIL = 0x63,

	/*! Identification failed, or the requested data is not found */
	QF_PROTO_RET_NOT_FOUND = 0x69,

	/*! Face does not match. */
	QF_PROTO_RET_NOT_MATCH = 0x6A,

	/*! Face image quality is not good. */
	QF_PROTO_RET_TRY_AGAIN = 0x6B,

	/*! Timeout for face input. */
	QF_PROTO_RET_TIME_OUT = 0x6C,

	/*! Maximum template capacity exceeded. */
	QF_PROTO_RET_MEM_FULL = 0x6D,

	/*! The specified user ID already exists. */
	QF_PROTO_RET_EXIST_ID = 0x6E,

	/*! The number of faces enrolled in same ID exceeds its limit. */
	QF_PROTO_RET_FACE_TEMPLATE_LIMIT = 0x72,

	/*! There is more data to be sent. */
	QF_PROTO_RET_CONTINUE = 0x74,

	/*! The command is not supported. */
	QF_PROTO_RET_UNSUPPORTED = 0x75,

	/*! The requested user ID is invalid or missing */
	QF_PROTO_RET_INVALID_ID = 0x76,

	/*! Timeout for face identification. */
	QF_PROTO_RET_TIMEOUT_MATCH = 0x7A,

	/*! Firmware is invalid */
	QF_PROTO_RET_INVALID_FIRMWARE = 0x7C,

	/*! Module is processing another command */
	QF_PROTO_RET_BUSY = 0x80,

	/*! The command is canceled */
	QF_PROTO_RET_CANCELED = 0x81,

	/*! The checksum of a data packet is incorrect */
	QF_PROTO_RET_DATA_ERROR = 0x82,

	/*! The checksum of a data packet is correct */
	QF_PROTO_RET_DATA_OK = 0x83,

	/*! The face is already enrolled */
	QF_PROTO_RET_EXIST_FACE = 0x86,

	/*! No sreial number */
	QF_PROTO_RET_NO_SERIAL_NUMBER = 0xA2,

	/*! Input face is determined as a fake face. */
	QF_PROTO_RET_FAKE_DETECTED = 0xB0,

	/*! The format of the DB file is invalid */
	QF_PROTO_RET_INVALID_DATABASE_FORMAT = 0xB2,

	/*! Image format is wrong */
	QF_PROTO_RET_WRONG_IMAGE_FORMAT = 0xB3,

	/*! Image size is wrong */
	QF_PROTO_RET_WRONG_IMAGE_SIZE = 0XB4,

	/*! User feedback */
	QF_PROTO_RET_USER_FEEDBACK = 0xB5,

} QF_PROTOCOL_RET_CODE;

#endif
