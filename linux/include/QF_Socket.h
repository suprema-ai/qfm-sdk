/**
 * @file QF_Socket.h
 * @brief Wrapper API for socket communication
 * @copyright This software is the confidential and proprietary information of Suprema AI Inc. ("Confidential Information").  You shall not disclose such Confidential Information and shall use it only in accordance with the terms of the license agreement you entered into with Suprema AI Inc.
 */

#ifndef __QFM_SDK_SOCKET_H__
#define __QFM_SDK_SOCKET_H__

#include "QF_API.h"

#ifdef __cplusplus
extern "C"
{
#endif

    int QF_ReadSocket(unsigned char *buf, int size, int timeout);
    int QF_WriteSocket(unsigned char *buf, int size, int timeout);

    void QF_SetSocketWriteCallback(void (*Callback)(int writtenLen, int totalSize));
    void QF_SetSocketReadCallback(void (*Callback)(int readLen, int totalSize));

    int QF_ClearSocketReadBuffer();
    int QF_ClearSocketWriteBuffer();

#ifdef __cplusplus
}
#endif

#endif
