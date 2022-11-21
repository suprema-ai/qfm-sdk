/**
 *  	Type definition
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

#ifndef __QFM_SDK_DEF_H__
#define __QFM_SDK_DEF_H__

#ifdef QFM_SDK_STATIC_LIB
#define QF_API
#else
#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
#ifdef QFM_SDK_SHARED_LIB
#ifdef __GNUC__
#define QF_API __attribute__((dllexport)) 
#else
#ifdef EXPORTS_ORDINAL
#define QF_API
#else
#define QF_API __declspec(dllexport)
#endif
#endif
#else
#ifdef __GNUC__
#define QF_API __attribute__((dllimport))
#else
#define QF_API __declspec(dllimport)
#endif
#endif
#else
#if __GNUC__ >= 4
#define QF_API __attribute__((visibility("default")))
#else
#define QF_API
#endif
#endif
#endif

#if defined(_WIN32)
#include <windows.h>
#else

//
// Type definition
//
#include <stdint.h>
#include <stdbool.h>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

// DWORD, UINT32, and LONG must be used as unsigned 32-bit data for compatibility between 32-bit and 64-bit system.

#ifndef DWORD
typedef uint32_t DWORD;
#endif

#ifndef WORD
typedef uint16_t WORD;

#ifndef BYTE
typedef uint8_t BYTE;
#endif

#ifndef BOOL
#ifndef _Bool
typedef bool BOOL;
#else
typedef _Bool BOOL;
#endif
#endif

#ifndef UINT32
typedef uint32_t UINT32;
#endif

#ifndef USHORT
typedef uint16_t USHORT;
#endif

#ifndef LONG
typedef uint32_t LONG;
#endif

#ifndef HANDLE
typedef void *HANDLE;
#endif

#ifndef NULL
#define NULL 0
#endif

#endif
#endif
#endif
