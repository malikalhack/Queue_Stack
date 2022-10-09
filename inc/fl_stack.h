/**
 * @file    fl_stack.h
 * @version 1.2.2
 * @authors Anton Chernov
 * @date    09/10/2022
 */

#ifndef FL_STACK_H_
#define FL_STACK_H_
/****************************** Included files ********************************/
#include "common.h"
/*************************** Function's prototypes ****************************/
void create_fl_stack(void);
bool push_fl_stack(uint8_t);
uint8_t pop_fl_stack(void);
uint8_t top_fl_stack(void);
bool is_empty_fl_stack(void);
/******************************************************************************/
#endif // !FL_STACK_H_
