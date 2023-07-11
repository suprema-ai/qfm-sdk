/**
 * @file QF_Serial.h
 * @brief Serial API
 * @copyright This software is the confidential and proprietary information of Suprema AI Inc. ("Confidential Information").  You shall not disclose such Confidential Information and shall use it only in accordance with the terms of the license agreement you entered into with Suprema AI Inc.
 */

#ifndef __QFM_SDK_SERIAL_H__
#define __QFM_SDK_SERIAL_H__

#include "QF_Def.h"

#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

typedef enum
{
	QF_SINGLE_PROTOCOL = 0,
} QF_PROTOCOL;

typedef enum
{
	QF_SERIAL_CHANNEL = 0,
	QF_SOCKET_CHANNEL = 1,
} QF_CHANNEL_TYPE;

#ifdef __cplusplus
extern "C"
{
#endif
	int QF_ReadSerial(unsigned char *buf, int size, int timeout);
	int QF_WriteSerial(unsigned char *buf, int size, int timeout);
	int QF_OpenSerial(const char *deviceName);
	int QF_CloseSerial();
	int QF_SetupSerial(int baudrate);
	int QF_ClearSerialReadBuffer();
	int QF_ClearSerialWriteBuffer();
	void QF_CancelReadSerial();
	void QF_CancelWriteSerial();
	QF_API int QF_GetBaudrate();

	void QF_SetSerialWriteCallback(void (*Callback)(int writtenLen, int totalSize));
	void QF_SetSerialReadCallback(void (*Callback)(int readLen, int totalSize));

#ifdef __cplusplus
}
#endif

#endif
