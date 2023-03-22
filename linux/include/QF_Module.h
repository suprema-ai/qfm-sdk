/**
 * @file QF_Module.h
 * @brief Module API
 * @copyright This software is the confidential and proprietary information of Suprema AI Inc. ("Confidential Information").  You shall not disclose such Confidential Information and shall use it only in accordance with the terms of the license agreement you entered into with Suprema AI Inc.
 */

#ifndef __QFM_SDK_MODULE_H__
#define __QFM_SDK_MODULE_H__

typedef enum
{
	QF_MODULE_PRO = 0,
	QF_MODULE_UNKNOWN = -1,
} QF_MODULE_TYPE;

typedef enum
{
	QF_VERSION_0_1 = 1,
	QF_VERSION_1_0 = 10,
	QF_VERSION_UNKNOWN = -1,
} QF_MODULE_VERSION;

typedef enum
{
	QF_HARDWARE_REVISION_A = 0,
	QF_HARDWARE_UNKNOWN = -1,
} QF_HARDWARE_REVISION;

#endif
