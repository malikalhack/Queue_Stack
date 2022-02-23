/**
* @file    queue.h
* @version 1.0.0
* @authors Anton Chernov
* @date    23/02/2022
*/

#ifndef QUEUE_H_
#define QUEUE_H_
/****************************** Included files ********************************/
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
/******************************** Definition **********************************/
#define QUEUE_LENGTH    (10)
/*************************** Function's prototypes ****************************/
void create_fixed_length_queue(void);
bool push_fix_queue(uint8_t);
uint8_t pop_fix_queue(void);
uint8_t front_fix_queue(void);
bool is_empty_fix_queue(void);
/*----------------------------------------------------------------------------*/
bool create_variable_length_queue(uint8_t);
void destroy_variable_length_queue(void);
bool push_var_queue(uint8_t);
uint8_t pop_var_queue(void);
uint8_t front_var_queue(void);
bool is_empty_var_queue(void);
/******************************************************************************/
#endif // !QUEUE_H_
