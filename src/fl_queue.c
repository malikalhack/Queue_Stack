/**
 * @file    fl_queue.c
 * @version 1.3.1
 * @authors Anton Chernov
 * @date    23/02/2022
 * @date    18/10/2022
 */

/****************************** Included files ********************************/
#include "common.h"
/****************************** Private  variables ****************************/
static data_t queue[QUEUE_LENGTH];
static volatile index_t head;
static volatile index_t tail;
static volatile bsize_t count;
/********************* Application Programming Interface **********************/
void create_fl_queue(void) {
    head  = 0;
    tail  = 0;
    count = 0;
}
/*----------------------------------------------------------------------------*/
bool push_fl_queue(data_t num) {
    if (count) {
        index_t tail_old = tail++;
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
data_t pop_fl_queue(void) {
    data_t result = 0;
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
data_t front_fl_queue(void) {
    return (count) ? queue[head] : 0;
}
/*----------------------------------------------------------------------------*/
bool is_empty_fl_queue(void) {
    return (count == 0);
}
/******************************************************************************/
