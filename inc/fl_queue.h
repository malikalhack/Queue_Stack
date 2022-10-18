/**
 * @file    fl_queue.h
 * @version 1.3.1
 * @authors Anton Chernov
 * @date    09/10/2022
 * @date    15/10/2022
 */

#ifndef FL_QUEUE_H_
#define FL_QUEUE_H_
/****************************** Included files ********************************/
#include "common.h"
/*************************** Function's prototypes ****************************/

/**
 * @brief Queue initialization function.
 * @details This function initializes the queue's hidden internal variables.
 * Using the queue without first calling this function will result in undefined
 * behaviour.
 */
void create_fl_queue(void);

/**
 * @brief The function of pushing an element in the queue.
 * @param[in] num - the element that is placed on the queue
 * @returns a boolean result that reports the success or failure
 * of placing the element on the queue.
 */
bool push_fl_queue(uint8_t);

/**
 * @brief The function of poping an element in the queue.
 * @returns the element of the queue.
 */
uint8_t pop_fl_queue(void);

/**
 * @brief The function to access the front element of the queue.
 * @returns the front element of the queue.
 */
uint8_t front_fl_queue(void);

/**
 * @brief The function of checking the queue for emptiness.
 * @returns a boolean asserting that the queue is empty.
 */
bool is_empty_fl_queue(void);
/******************************************************************************/
#endif // !FL_QUEUE_H_
