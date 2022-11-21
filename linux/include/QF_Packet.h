/**
 *  	Packet definition
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

#ifndef __QFM_SDK_PACKET_H__
#define __QFM_SDK_PACKET_H__

#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

//
// Constants
//
#define QF_PACKET_START_CODE 0x40
#define QF_NETWORK_PACKET_START_CODE 0x41
#define QF_SECURE_PACKET_START_CODE 0x50
#define QF_SECURE_NETWORK_PACKET_START_CODE 0x51
#define QF_PACKET_END_CODE 0x0a
#define QF_PACKET_LEN 13
#define QF_NETWORK_PACKET_LEN 15
#define QF_SECURE_PACKET_LEN 35         // 32byte encrypted data + 4byte checksum + start code + end code
#define QF_SECURE_NETWORK_PACKET_LEN 40 // 32byte encrypted data + 4byte checksum + start code + end code + module id

#define QF_PACKET_COMMAND 0
#define QF_PACKET_TERMINAL_ID 1
#define QF_PACKET_PARAM 2
#define QF_PACKET_SIZE 3
#define QF_PACKET_FLAG 4
#define QF_PACKET_CHECKSUM 5

//
// Byte position of packet components
//
#define QF_PACKET_START_CODE_POS 0
#define QF_PACKET_COMMAND_POS 1
#define QF_PACKET_PARAM_POS 2
#define QF_PACKET_SIZE_POS 6
#define QF_PACKET_FLAG_POS 10
#define QF_PACKET_CHECKSUM_POS 11
#define QF_PACKET_END_CODE_POS 12

//
// Data packet
//
#define QF_DEFAULT_DATA_PACKET_SIZE (4 * 1024)

#ifdef __cplusplus
extern "C"
{
#endif

    QF_API UINT32 QF_GetPacketValue(int component, BYTE *packet);
    
    int QF_ReadData(unsigned char *buf, int size, int timeout);
    int QF_WriteData(unsigned char *buf, int size, int timeout);

    int QF_ClearReadBuffer();
    int QF_ClearWriteBuffer();

#ifdef __cplusplus
}
#endif

#endif
