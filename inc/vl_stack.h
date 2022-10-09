/**
 * @file    vl_stack.h
 * @version 1.2.2
 * @authors Anton Chernov
 * @date    09/10/2022
 */

#ifndef VL_STACK_H_
#define VL_STACK_H_
/****************************** Included files ********************************/
#include "common.h"
/*************************** Function's prototypes ****************************/
bool create_vl_stack(uint8_t);
void destroy_vl_stack(void);
bool push_vl_stack(uint8_t);
uint8_t pop_vl_stack(void);
uint8_t top_vl_stack(void);
bool is_empty_vl_stack(void);
/******************************************************************************/
#endif // !VL_STACK_H_
