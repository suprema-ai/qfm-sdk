/**
 * @file QF_UserFeedback.h
 * @brief User Feedback API
 * @copyright This software is the confidential and proprietary information of Suprema AI Inc. ("Confidential Information").  You shall not disclose such Confidential Information and shall use it only in accordance with the terms of the license agreement you entered into with Suprema AI Inc.
 */

#ifndef __QFM_SDK_USER_FEEDBACK_H__
#define __QFM_SDK_USER_FEEDBACK_H__

//
// User feedback
//
typedef enum 
{
    QF_USER_FEEDBACK_FACE_DETECTED = 0x0,
    QF_USER_FEEDBACK_LOOK_AT_THE_CAMERA_CORRECTLY = 0x1,
    QF_USER_FEEDBACK_TURN_YOUR_HEAD_RIGHT = 0x2,
    QF_USER_FEEDBACK_TURN_YOUR_HEAD_LEFT = 0x3,
    QF_USER_FEEDBACK_TURN_YOUR_HEAD_UP = 0x4,
    QF_USER_FEEDBACK_TURN_YOUR_HEAD_DOWN = 0x5,
    QF_USER_FEEDBACK_MOVE_FORWARD = 0x6,
    QF_USER_FEEDBACK_MOVE_BACKWARD = 0x7,
    // 0x8 and 0x9 are reserved
    QF_USER_FEEDBACK_OUT_OF_ENROLLMENT_AREA = 0xA,
    // 0xB ~ 0xFE are reserved
    QF_USER_FEEDBACK_FACE_NOT_DETECTED = 0xFF,

}QF_USER_FEEDBACK;


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
