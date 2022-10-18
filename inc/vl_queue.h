/**
 * @file    vl_queue.h
 * @version 1.3.1
 * @authors Anton Chernov
 * @date    09/10/2022
 * @date    18/10/2022
 */

#ifndef VL_QUEUE_H_
#define VL_QUEUE_H_
/****************************** Included files ********************************/
#include "common.h"
/*************************** Function's prototypes ****************************/

/**
 * @brief Queue creation function.
 * @details This function creates the queue and initializes its hidden internal
 * variables. Attempting to use the queue without first calling this function
 * will result in an error.
 */
bool create_vl_queue(bsize_t);

/**
 * @brief Queue destroy function.
 * @details This function destroys the queue and initializes its hidden internal
 * variables again. Failure to call this function at the end of program execution
 * will result in memory leaks.
 */
void destroy_vl_queue(void);

/**
 * @brief The function of pushing an element in the queue.
 * @param[in] num - the element that is placed on the queue
 * @returns a boolean result that reports the success or failure
 * of placing the element on the queue.
 */
bool push_vl_queue(data_t);

/**
 * @brief The function of poping an element in the queue.
 * @returns the element of the queue.
 */
data_t pop_vl_queue(void);

/**
 * @brief The function to access the front element of the queue.
 * @returns the front element of the queue.
 */
data_t front_vl_queue(void);

/**
 * @brief The function of checking the queue for emptiness.
 * @returns a boolean asserting that the queue is empty.
 */
bool is_empty_vl_queue(void);
/******************************************************************************/
#endif // !VL_QUEUE_H_
