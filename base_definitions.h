/*!
    @file   base_definitions.h
    @brief  Basic definitions and types for embedded systems frameworks.
    ---------------------------------------------------------------------------

    MIT License
    Copyright (c) 2024 Io. D (Devcoons)

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#ifndef _BASE_DEFINITIONS_H_
#define _BASE_DEFINITIONS_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * Includes
 ******************************************************************************/

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

/******************************************************************************
 * Macros
 ******************************************************************************/

/**
 * @brief Calculate timeout based on start, current, and timeout values.
 */
#ifndef iTIMEOUT
#define iTIMEOUT(start, current, timeout) \
    (((start) < (current) ? (start) - (UINT_MAX - (current)) : (start) - (current)) < (timeout) ? 0 : 1)
#endif

/**
 * @brief Mark a variable as unused to avoid compiler warnings.
 */
#ifndef UNUSED
#define UNUSED(X) (void)(X)
#endif

/**
 * @brief Get array size
 */
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif

/**
 * @brief Minimum of two values
 */
#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

/**
 * @brief Maximum of two values
 */
#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

/**
 * @brief Clamp value within range
 */
#ifndef CLAMP
#define CLAMP(val, min, max) (MAX((min), MIN((val), (max)))) 
#endif

/**
 * @brief Set a bit in a variable.
 */
#ifndef SET_BIT
#define SET_BIT(var, bit)   ((var) |= (1U << (bit)))
#endif

/**
 * @brief Clear a bit in a variable.
 */
#ifndef CLEAR_BIT
#define CLEAR_BIT(var, bit) ((var) &= ~(1U << (bit)))
#endif

/**
 * @brief Toggle a bit in a variable.
 */
#ifndef TOGGLE_BIT
#define TOGGLE_BIT(var, bit) ((var) ^= (1U << (bit)))
#endif

/**
 * @brief Check if a bit is set in a variable.
 */
#ifndef IS_BIT_SET
#define IS_BIT_SET(var, bit) (((var) & (1U << (bit))) != 0)
#endif

/**
 * @brief Check if a bit is cleared in a variable.
 */
#ifndef IS_BIT_CLEAR
#define IS_BIT_CLEAR(var, bit) (((var) & (1U << (bit))) == 0)
#endif

/******************************************************************************
 * Enumerations and Typedefs
 ******************************************************************************/

/**
 * @brief Basic status codes.
 */
typedef enum {
    /* General Status */
    STATUS_OK               = 0x01, /* Operation successful */
    STATUS_ERROR            = 0x02, /* General error */
    STATUS_TIMEOUT          = 0x03, /* Operation timed out */
    STATUS_BUSY             = 0x04, /* Resource is busy */
    STATUS_IDLE             = 0x05, /* Resource is idle */
    STATUS_NOT_FOUND        = 0x06, /* Requested item not found */
    STATUS_UNSUPPORTED      = 0x07, /* Operation not supported */
    STATUS_INITIALIZED      = 0x08, /* Successfully initialized */
    STATUS_NOT_INITIALIZED  = 0x09, /* Not yet initialized */
    STATUS_IN_PROGRESS      = 0x0A, /* Operation in progress */
    STATUS_COMPLETED        = 0x0B, /* Operation completed */
    /* Memory and Alignment */
    STATUS_MEM_ALIGNED      = 0x10, /* Memory is aligned */
    STATUS_MEM_UNALIGNED    = 0x11, /* Memory is unaligned */
    STATUS_MEM_FULL         = 0x12, /* Memory is full */
    STATUS_MEM_EMPTY        = 0x13, /* Memory is empty */
    STATUS_OVERFLOW         = 0x14, /* Buffer overflow detected */
    STATUS_UNDERFLOW        = 0x15, /* Buffer underflow detected */
    /* Access and Permissions */
    STATUS_ACCESS_GRANTED   = 0x20, /* Access granted */
    STATUS_ACCESS_DENIED    = 0x21, /* Access denied */
    STATUS_LOCKED           = 0x22, /* Resource is locked */
    STATUS_UNLOCKED         = 0x23, /* Resource is unlocked */
    /* Activity States */
    STATUS_ACTIVE           = 0x30, /* Resource is active */
    STATUS_INACTIVE         = 0x31, /* Resource is inactive */
    STATUS_STOPPED          = 0x32, /* Operation is stopped */
    STATUS_RUNNING          = 0x33, /* Operation is running */
    STATUS_SLEEPING         = 0x34, /* Resource is in sleep mode */
    STATUS_STANDBY          = 0x35, /* Resource is in standby mode */
    STATUS_NOT_READY        = 0x36, /* Resource is not ready */
    STATUS_BUSY             = 0x37, /* Resource is currently busy */
    /* Debug and Warnings */
    STATUS_WARNING          = 0x40, /* General warning */
    STATUS_SELF_TEST_PASS   = 0xC0, /* Self-test passed */
    STATUS_SELF_TEST_FAIL   = 0xC1, /* Self-test failed */
    STATUS_DEBUG_1          = 0xE1, /* Debug status 1 */
    STATUS_DEBUG_2          = 0xE2, /* Debug status 2 */
    STATUS_DEBUG_3          = 0xE3, /* Debug status 3 */
    /* Reserved for Future Use */
    STATUS_NOT_IMPLEMENTED  = 0xFD, /* Feature not implemented */
    STATUS_UNKNOWN          = 0xFE  /* Unknown status */
} i_status;

/**
 * @brief Standard variable types.
 */
typedef enum {
    VAR_TYPE_U8         = 0x01, /* Unsigned 8-bit integer */
    VAR_TYPE_I8         = 0x11, /* Signed 8-bit integer */
    VAR_TYPE_U16        = 0x02, /* Unsigned 16-bit integer */
    VAR_TYPE_I16        = 0x12, /* Signed 16-bit integer */
    VAR_TYPE_U32        = 0x04, /* Unsigned 32-bit integer */
    VAR_TYPE_I32        = 0x14, /* Signed 32-bit integer */
    VAR_TYPE_U64        = 0x08, /* Unsigned 64-bit integer */
    VAR_TYPE_I64        = 0x18, /* Signed 64-bit integer */
    VAR_TYPE_U8_ARR     = 0x21, /* Array of unsigned 8-bit integers */
    VAR_TYPE_I8_ARR     = 0x31, /* Array of signed 8-bit integers */
    VAR_TYPE_U16_ARR    = 0x22, /* Array of unsigned 16-bit integers */
    VAR_TYPE_I16_ARR    = 0x32, /* Array of signed 16-bit integers */
    VAR_TYPE_U32_ARR    = 0x24, /* Array of unsigned 32-bit integers */
    VAR_TYPE_I32_ARR    = 0x34, /* Array of signed 32-bit integers */
    VAR_TYPE_U64_ARR    = 0x28, /* Array of unsigned 64-bit integers */
    VAR_TYPE_I64_ARR    = 0x38  /* Array of signed 64-bit integers */
} var_type;

/****************************************************************************
 * Structs
 ****************************************************************************/

/****************************************************************************
 * End of File
 ****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* _BASE_DEFINITIONS_H_ */
