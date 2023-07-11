/**
 * @file QF_Key.h
 * @brief Key management API
 * @copyright This software is the confidential and proprietary information of Suprema AI Inc. ("Confidential Information").  You shall not disclose such Confidential Information and shall use it only in accordance with the terms of the license agreement you entered into with Suprema AI Inc.
 * @note
 * `Encryption Key` menas a key for encrypting the data in the module such as the biometric template and the image. @n
 * `Initialization Vector` means a secondary key for encrypting the data in the module with the encryption key when the AES-256-CBC mode is used. @n
 * `Secure Key` means a key for the packet encryption key for secure packet communication between the host and the module.
 *
*/

#ifndef __KEY_H__
#define __KEY_H__

// definition
#define MODULE_KEY_SIZE 32
#define IV_KEY_SIZE 32
#define SECURE_KEY_SIZE 32
#define PUBLIC_KEY_SIZE 32
#define PRIVATE_KEY_SIZE 64

#define SECURE_PACKET_DATA_SIZE 32
#define ENCRYPTION_KEY_SIZE 32
#define CHECKSUM_4_SIZE 4
#define SECURE_CODE_SIZE 8

typedef enum
{
    /*! set encryption key */
    QF_KEY_OPTION_SET_ENCRYPTION_KEY = 0xC1,

    /*! set initialization vector */
    QF_KEY_OPTION_SET_INITIALIZATION_VECTOR = 0xC2,

    /*! set secure key */
    QF_KEY_OPTION_SET_SECURE_KEY = 0xC3,

    /*! set encryption key with verification */
    QF_KEY_OPTION_SET_ENCRYPTION_KEY_WITH_VERIFICATION = 0xC4,

    /*! set initialization vector with verification */
    QF_KEY_OPTION_SET_INITIALIZATION_VECTOR_WITH_VERIFICATION = 0xC5,

    /*! set secure key with verification */
    QF_KEY_OPTION_SET_SECURE_KEY_WITH_VERIFICATION = 0xC6,

    /*! reset initialization vector */
    QF_KEY_OPTION_RESET_INITIALIZATION_VECTOR = 0xCA,

    /*! reset secure key */
    QF_KEY_OPTION_RESET_SECURE_KEY = 0xCB,

    /*! reset encryption key */
    QF_KEY_OPTION_RESET_ENCRYPTION_KEY = 0xCC,

} QF_KEY_OPTION;

typedef enum
{
    QF_KEY_EXCHANGE_OPTION_SET_PUBLIC_KEY = 0xCD,
    QF_KEY_EXCHANGE_OPTION_GET_PUBLIC_KEY = 0xCE,
}QF_KEY_EXCHANGE_OPTION;

#endif
