/**
 * @file QF_Enroll.h
 * @brief Enroll API
 * @copyright This software is the confidential and proprietary information of Suprema AI Inc. ("Confidential Information").  You shall not disclose such Confidential Information and shall use it only in accordance with the terms of the license agreement you entered into with Suprema AI Inc.
 */

#ifndef __QFM_SDK_ENROLL_H__
#define __QFM_SDK_ENROLL_H__

typedef enum
{
	/*! Scans a face and enrolls it. */
	QF_ENROLL_MODE_ONE_SHOT = 0x30,

} QF_ENROLL_MODE;

/**
 * @brief Enroll options
 * 
 */
typedef enum
{
	/*! Adds templates to the same user ID. */
	QF_ENROLL_OPTION_ADD_NEW = 0x71,
	
	/*! The user ID will be assigned automatically by the module. */
	QF_ENROLL_OPTION_AUTO_ID = 0x79,
	
	/*! Before enrolling, checks if the user ID has already some templates. If it does, \ref QF_ERR_EXIST_ID will be returned. This option is useful when users do not want to overwrite existing templates. */
	QF_ENROLL_OPTION_CHECK_ID = 0x70,
	
	/*! Before enrolling, checks if the same face is already enrolled. If the identification succeeds, return \ref QF_ERR_EXIST_FACE error. If the identification fails, continue enroll process with \ref QF_ENROLL_OPTION_ADD_NEW option. */
	QF_ENROLL_OPTION_CHECK_FACE = 0x84,

	/*! Before enrolling, checks if the same face is already enrolled. If the identification succeeds, return \ref QF_ERR_EXIST_FACE error. If the identification fails, continue enroll process with \ref QF_ENROLL_OPTION_AUTO_ID option. */
	QF_ENROLL_OPTION_CHECK_FACE_AUTO_ID = 0x85,
} QF_ENROLL_OPTION;

#endif
