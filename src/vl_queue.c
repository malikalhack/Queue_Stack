/**
 * @file    vl_queue.c
 * @version 1.2.2
 * @authors Anton Chernov
 * @date    23/02/2022
 * @date    09/10/2022
 */

 /****************************** Included files ********************************/
#include "common.h"
#include <stdlib.h>
#include <malloc.h>
/****************************** Private  variables ****************************/
uint8_t *queue;
uint8_t queue_length;
volatile uint8_t queue_front;
volatile uint8_t queue_tail;
volatile bool is_empty;
/********************* Application Programming Interface **********************/
bool create_vl_queue(uint8_t buf_size) {
    bool result = false;
    queue = (uint8_t*)calloc(buf_size + 1, 1);
    if (queue) {
        queue_length = buf_size;
        queue_front = 0;
        queue_tail = 0;
        is_empty = true;
        result = true;
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool push_vl_queue(uint8_t item) {
    bool result = false;
    if (is_empty) {
        queue[queue_front] = item;
        is_empty = false;
        result = true;
    }
    else {
        uint8_t old_variable_length_queue_tail = queue_tail++;
        queue_tail %= queue_length;

        if (queue_tail != queue_front) {
            queue[queue_tail] = item;
            result = true;
        }
        else {
            queue_tail = old_variable_length_queue_tail;
            printf("Buffer overflow\n");
        }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t pop_vl_queue(void) {
    uint8_t result = 0;
    if (!is_empty) {
        if (queue_tail == queue_front) {
            is_empty = true;
            result = queue[queue_front];
        }
        else {
            result = queue[queue_front++];
            queue_front %= queue_length;
        }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t front_vl_queue(void) {
    uint8_t result = 0;
    if (!is_empty) {
        result = queue[queue_front];
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool is_empty_vl_queue(void) {
    return is_empty;
}
/*----------------------------------------------------------------------------*/
void destroy_vl_queue(void) {
    free(queue);
    queue = NULL;
}
/******************************************************************************/
