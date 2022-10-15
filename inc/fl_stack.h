/**
 * @file    fl_stack.h
 * @version 1.3.0
 * @authors Anton Chernov
 * @date    09/10/2022
 * @date    15/10/2022
 */

#ifndef FL_STACK_H_
#define FL_STACK_H_
/****************************** Included files ********************************/
#include "common.h"
/*************************** Function's prototypes ****************************/

/**
 * @brief Stack initialization function.
 * @details This function initializes the stack's hidden internal variables.
 * Using the stack without first calling this function will result in undefined
 * behaviour.
 */
void create_fl_stack(void);

/**
 * @brief The function of pushing an element in the stack.
 * @param[in] num - the element that is placed on the stack
 * @returns a boolean result that reports the success or failure
 * of placing the element on the stack.
 */
bool push_fl_stack(uint8_t);

/**
 * @brief The function of poping an element in the stack.
 * @returns the element of the stack.
 */
uint8_t pop_fl_stack(void);

/**
 * @brief The function to access the top element of the stack.
 * @returns the top element of the stack.
 */
uint8_t top_fl_stack(void);

/**
 * @brief The function of checking the stack for emptiness.
 * @returns a boolean asserting that the stack is empty.
 */
bool is_empty_fl_stack(void);
/******************************************************************************/
#endif // !FL_STACK_H_
