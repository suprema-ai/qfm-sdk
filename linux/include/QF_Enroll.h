/**
 *  	Enroll
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

#ifndef __QFM_SDK_ENROLL_H__
#define __QFM_SDK_ENROLL_H__

typedef enum
{
	QF_ENROLL_MODE_ONE_SHOT = 0x30,
} QF_ENROLL_MODE;

typedef enum
{
	QF_ENROLL_OPTION_ADD_NEW = 0x71,
	QF_ENROLL_OPTION_AUTO_ID = 0x79,
	QF_ENROLL_OPTION_CHECK_ID = 0x70,
	QF_ENROLL_OPTION_CHECK_FACE = 0x84,
	QF_ENROLL_OPTION_CHECK_FACE_AUTO_ID = 0x85,
} QF_ENROLL_OPTION;

#endif
