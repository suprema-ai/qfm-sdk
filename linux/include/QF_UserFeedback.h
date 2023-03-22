/**
 * @file QF_UserFeedback.h
 * @brief User Feedback API
 * @copyright This software is the confidential and proprietary information of Suprema AI Inc. ("Confidential Information").  You shall not disclose such Confidential Information and shall use it only in accordance with the terms of the license agreement you entered into with Suprema AI Inc.
 */

#ifndef __QFM_SDK_USER_FEEDBACK_H__
#define __QFM_SDK_USER_FEEDBACK_H__

/**
 * @brief User feedback type
 * 
 */
typedef enum {
  USER_FEEDBACK_TYPE_MESSAGE_CODE  = 1<<0, // Message code
  USER_FEEDBACK_TYPE_HEAD_POSITION = 1<<1  // Coordinates of rectangle
}UserFeedbackType;

/**
 * @brief User feedback data structure
 * 
 */
typedef struct {
 int fields;     // Fields present here, example USER_MESSAGE|HEAD_POSITION
 int messageCode;
 struct {
   int topLeftX, topLeftY;
   int bottomRightX, bottomRightY;
 } headPosition;
} UserFeedbackData;


#endif
