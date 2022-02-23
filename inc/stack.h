/**
* @file    stack.h
* @version 1.0.0
* @authors Anton Chernov
* @date    23/02/2022
*/

#ifndef STACK_H_
#define STACK_H_
/****************************** Included files ********************************/
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
/******************************** Definition **********************************/
#define STACK_LENGTH    (10)
/*************************** Function's prototypes ****************************/
void create_fixed_length_stack(void);
bool push_fix_stack(uint8_t);
uint8_t pop_fix_stack(void);
uint8_t top_fix_stack(void);
bool is_empty_fix_stack(void);
/*----------------------------------------------------------------------------*/
bool create_variable_length_stack(uint8_t);
void destroy_variable_length_stack(void);
bool push_var_stack(uint8_t);
uint8_t pop_var_stack(void);
uint8_t top_var_stack(void);
bool is_empty_var_stack(void);
/******************************************************************************/
#endif // !STACK_H_
