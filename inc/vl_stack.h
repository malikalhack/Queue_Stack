/**
 * @file    vl_stack.h
 * @version 1.3.1
 * @authors Anton Chernov
 * @date    09/10/2022
 * @date    18/10/2022
 */

#ifndef VL_STACK_H_
#define VL_STACK_H_
/****************************** Included files ********************************/
#include "common.h"
/*************************** Function's prototypes ****************************/

/**
 * @brief Stack creation function.
 * @details This function creates the stack and initializes its hidden internal
 * variables. Attempting to use the stack without first calling this function
 * will result in an error.
 */
bool create_vl_stack(bsize_t);

/**
 * @brief Stack destroy function.
 * @details This function destroys the stack and initializes its hidden internal
 * variables again. Failure to call this function at the end of program execution
 * will result in memory leaks.
 */
void destroy_vl_stack(void);

/**
 * @brief The function of pushing an element in the stack.
 * @param[in] num - the element that is placed on the stack
 * @returns a boolean result that reports the success or failure
 * of placing the element on the stack.
 */
bool push_vl_stack(data_t);

/**
 * @brief The function of poping an element in the stack.
 * @returns the element of the stack.
 */
data_t pop_vl_stack(void);

/**
 * @brief The function to access the top element of the stack.
 * @returns the top element of the stack.
 */
data_t top_vl_stack(void);

/**
 * @brief The function of checking the stack for emptiness.
 * @returns a boolean asserting that the stack is empty.
 */
bool is_empty_vl_stack(void);
/******************************************************************************/
#endif // !VL_STACK_H_
