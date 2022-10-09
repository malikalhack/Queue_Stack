/**
 * @file    fl_queue.c
 * @version 1.2.2
 * @authors Anton Chernov
 * @date    23/02/2022
 * @date    09/10/2022
 */

/****************************** Included files ********************************/
#include "common.h"
/****************************** Private  variables ****************************/
uint8_t queue[QUEUE_LENGTH];
volatile uint8_t queue_front;
volatile uint8_t queue_tail;
volatile bool is_empty;
/********************* Application Programming Interface **********************/
void create_fl_queue(void) {
    for (uint8_t i = 0; i < QUEUE_LENGTH; i++) {
        queue[i] = 0;
    }
    queue_front = 0;
    queue_tail = 0;
    is_empty = true;
}
/*----------------------------------------------------------------------------*/
bool push_fl_queue(uint8_t item) {
    bool result = false;
    if (is_empty) {
        queue[queue_front] = item;
        is_empty = false;
        result = true;
    }
    else {
        uint8_t old_fixed_length_queue_tail = queue_tail++;
        queue_tail %= QUEUE_LENGTH;

        if (queue_tail != queue_front) {
            queue[queue_tail] = item;
            result = true;
        }
        else {
            queue_tail = old_fixed_length_queue_tail;
            printf("Buffer overflow\n");
        }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t pop_fl_queue(void) {
    uint8_t result = 0;
    if (!is_empty) {
        if (queue_tail == queue_front) {
            is_empty = true;
            result = queue[queue_front];
        }
        else {
            result = queue[queue_front++];
            queue_front %= QUEUE_LENGTH;
        }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t front_fl_queue(void) {
    uint8_t result = 0;
    if (!is_empty) {
        result = queue[queue_front];
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool is_empty_fl_queue(void) {
    return is_empty;
}
/******************************************************************************/
