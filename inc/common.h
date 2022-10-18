/**
 * @file    common.h
 * @version 1.3.1
 * @authors Anton Chernov
 * @date    09/10/2022
 * @date    18/10/2022
 */

#ifndef COMMON_H_
#define COMMON_H_
/****************************** Included files ********************************/
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
/******************************** Definition **********************************/
typedef uint8_t data_t;  ///< Data type (can be any numeric type)
typedef uint8_t bsize_t; ///< Buffer size type (cannot be negative or non-integer)
typedef bsize_t index_t; ///< Index type (identical to buffer size type)

#define STACK_SIZE      (10u) ///< Fixed stack size (is used in the test)
#define QUEUE_LENGTH    (10u) ///< Fixed queue size (is used in the test)
/******************************************************************************/
#endif /* !COMMON_H_ */
