/**
 * @file QF_Template.h
 * @brief User & Template Management API
 * @copyright This software is the confidential and proprietary information of Suprema AI Inc. ("Confidential Information").  You shall not disclose such Confidential Information and shall use it only in accordance with the terms of the license agreement you entered into with Suprema AI Inc.
 */

#ifndef __QFM_SDK_TEMPLATE_H__
#define __QFM_SDK_TEMPLATE_H__

#define MAXIMUM_TEMPLATE_SIZE 512

// option for ST command
#define QF_ADD_CHECKSUM 0x70

#define MAXIMUM_NUM_OF_TEMPLATE_PER_USER 20


typedef struct
{
	/*! User ID */
	UINT32 userID;
	/*! Number of template */
	BYTE numOfTemplate;
	/*! Reserved byte (0) */
	BYTE reserved_0;
	/*! Reserved byte (1) */
	BYTE reserved_1;
	/*! Reserved byte (2) */
	BYTE reserved_2;
} QFUserInfo;

typedef struct
{
	/*! User ID */
	UINT32 userID;
	/*! Checksum */
	UINT32 checksum[MAXIMUM_NUM_OF_TEMPLATE_PER_USER];
	/*! Number of template */
	BYTE numOfTemplate;
	/*! Template property */
	BYTE templateProperty : 4;
	/*! Encryption mode */
	BYTE encryptionMode : 4;
	/*! Sub ID */
	BYTE subID : 4;
	/*! Mast */
	BYTE mask : 4;
	/*! Reserved byte (0)*/
	BYTE reserved_0;
} QFUserInfoEx;

#define QF_VALID_TEMPLATE_DB 0x1f2f3f4f


#ifdef __cplusplus
extern "C"
{
#endif

#if defined(_WIN32)
	int __cdecl QF_SortByUserID(const void *elem1, const void *elem2);
#else
int QF_SortByUserID(const void *elem1, const void *elem2);
#endif

#ifdef __cplusplus
}

#endif

#endif
