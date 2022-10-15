/**
 * @file    vl_queue.h
 * @version 1.3.0
 * @authors Anton Chernov
 * @date    09/10/2022
 */

#ifndef VL_QUEUE_H_
#define VL_QUEUE_H_
/****************************** Included files ********************************/
#include "common.h"
/*************************** Function's prototypes ****************************/
bool create_vl_queue(uint8_t);
void destroy_vl_queue(void);
bool push_vl_queue(uint8_t);
uint8_t pop_vl_queue(void);
uint8_t front_vl_queue(void);
bool is_empty_vl_queue(void);
/******************************************************************************/
#endif // !VL_QUEUE_H_
