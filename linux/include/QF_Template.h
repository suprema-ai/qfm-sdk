/**
 *  	User & Template Management
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

#ifndef __QFM_SDK_TEMPLATE_H__
#define __QFM_SDK_TEMPLATE_H__

#define MAXIMUM_TEMPLATE_SIZE 512

// option for ST command
#define QF_ADD_CHECKSUM 0x70

#define MAXIMUM_NUM_OF_TEMPLATE_PER_USER 20


typedef struct
{
	UINT32 userID;
	BYTE numOfTemplate;
	BYTE reserved_0;
	BYTE reserved_1;
	BYTE reserved_2;
} QFUserInfo;

typedef struct
{
	UINT32 userID;
	UINT32 checksum[MAXIMUM_NUM_OF_TEMPLATE_PER_USER];
	BYTE numOfTemplate;
	BYTE templateProperty : 4;
	BYTE encryptionMode : 4;
	BYTE subID : 4;
	BYTE mask : 4;
	BYTE reserved_0;
} QFUserInfoEx;

#define QF_VALID_TEMPLATE_DB 0x1f2f3f4f


typedef struct
{
	UINT32 userID;
	UINT32 userLevel; // entLimit << 24 | securityLevel << 16 | authMode << 8 | adminLevel
	UINT32 numOfTemplate;
	UINT32 checksum;
} QFUserItemHeader;

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
