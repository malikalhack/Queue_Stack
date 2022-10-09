/**
 * @file    fl_queue.h
 * @version 1.2.2
 * @authors Anton Chernov
 * @date    09/10/2022
 */

#ifndef FL_QUEUE_H_
#define FL_QUEUE_H_
/****************************** Included files ********************************/
#include "common.h"
/*************************** Function's prototypes ****************************/
void create_fl_queue(void);
bool push_fl_queue(uint8_t);
uint8_t pop_fl_queue(void);
uint8_t front_fl_queue(void);
bool is_empty_fl_queue(void);
/******************************************************************************/
#endif // !FL_QUEUE_H_
