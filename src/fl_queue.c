/**
 * @file    fl_queue.c
 * @version 1.3.1
 * @authors Anton Chernov
 * @date    23/02/2022
 * @date    15/10/2022
 */

/****************************** Included files ********************************/
#include "common.h"
/****************************** Private  variables ****************************/
static uint8_t queue[QUEUE_LENGTH];
static volatile uint8_t head;
static volatile uint8_t tail;
static volatile uint8_t count;
/********************* Application Programming Interface **********************/
void create_fl_queue(void) {
    head  = 0u;
    tail  = 0u;
    count = 0u;
}
/*----------------------------------------------------------------------------*/
bool push_fl_queue(uint8_t num) {
    if (count) {
        uint8_t tail_old = tail++;
        tail %= QUEUE_LENGTH;
        if (tail == head) {
            printf("Buffer overflow\n");
            tail = tail_old;
            return false;
        }
    }
    count++;
    *(queue + tail) = num;
    return true;
}
/*----------------------------------------------------------------------------*/
uint8_t pop_fl_queue(void) {
    uint8_t result = 0u;
    if (count) {
        result = *(queue + head);
        if (--count) {
            head++;
            head %= QUEUE_LENGTH;
        }
    }
    else { printf("Stack is empty\n"); }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t front_fl_queue(void) {
    return (count) ? queue[head] : 0u;
}
/*----------------------------------------------------------------------------*/
bool is_empty_fl_queue(void) {
    return (count == 0u);
}
/******************************************************************************/
