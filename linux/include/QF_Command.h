/**
 * @file QF_Command.h
 * @brief Command definition
 * @copyright This software is the confidential and proprietary information of Suprema AI Inc. ("Confidential Information").  You shall not disclose such Confidential Information and shall use it only in accordance with the terms of the license agreement you entered into with Suprema AI Inc.
 */

#ifndef __QFM_SDK_COMMAND_H__
#define __QFM_SDK_COMMAND_H__

#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

//
// Command definitions
//
typedef enum
{
	QF_COM_SW = 0x01,
	QF_COM_SF = 0x02,
	QF_COM_SR = 0x03,
	QF_COM_SS = 0x04,
	QF_COM_ES = 0x05,
	QF_COM_VS = 0x08,
	QF_COM_VT = 0x10,
	QF_COM_IS = 0x11,
	QF_COM_IT = 0x13,
	QF_COM_DT = 0x16,
	QF_COM_DA = 0x17,
	QF_COM_CT = 0x19,
	QF_COM_DS = 0x1E,
	QF_COM_CS = 0x1A,
	QF_COM_ST = 0x21,
	QF_COM_VH = 0x22,
	QF_COM_FP = 0x23,
	QF_COM_DP = 0x24,
	QF_COM_KW = 0x34,
	QF_COM_KS = 0x35,
	QF_COM_GR = 0x36,
	QF_COM_GW = 0x37,
	QF_COM_GC = 0x38,
	QF_COM_GD = 0x39,
	QF_COM_QR = 0x51,
	QF_COM_CA = 0x60,
	QF_COM_UG = 0x62,
	QF_COM_EIX = 0x80,
	QF_COM_IIX = 0x81,
	QF_COM_VIX = 0x82,
	QF_COM_SIX = 0x83,
	QF_COM_RIX = 0x84,
	QF_COM_LTX = 0x86,
	QF_COM_ETX = 0x87,
	QF_COM_RTX = 0x89,
	QF_COM_RS = 0xD0,
	QF_COM_FF = 0xFF,
	QF_COM_FR = 0xFA,
} QF_COMMAND;

int QF_CalculateTimeout(int dataSize);

#endif
