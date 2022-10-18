/**
 * @file    vl_queue.c
 * @version 1.3.1
 * @authors Anton Chernov
 * @date    23/02/2022
 * @date    18/10/2022
 */

 /****************************** Included files ********************************/
#include "common.h"
#include <stdlib.h>
#include <malloc.h>
/****************************** Private  variables ****************************/
static data_t *queue;
static bsize_t length;
static volatile index_t head;
static volatile index_t tail;
static volatile bsize_t count;
/****************************** Private  functions ****************************/
static bool queue_check(void) {
    bool result = true;
    if (!queue) {
        printf("Memory access error\n");
        result = false;
    }
    return result;
}
/********************* Application Programming Interface **********************/
bool create_vl_queue(bsize_t buf_size) {
    bool result = false;
    queue = (data_t*)calloc(buf_size, sizeof(data_t));
    if (queue_check()) {
        length = buf_size;
        head   = 0;
        tail   = 0;
        count  = 0;
        result = true;
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool push_vl_queue(data_t num) {
    bool result = false;
    if (queue_check()) {
        if (count) {
            index_t tail_old = tail;
            tail++;
            tail %= length;
            if (tail == head) {
                printf("Buffer overflow\n");
                tail = tail_old;
                return result;
            }
        }
        count++;
        *(queue + tail) = num;
        result = true;
    }
    return result;
}
/*----------------------------------------------------------------------------*/
data_t pop_vl_queue(void) {
    data_t result = 0;
    if (queue_check()) {
        if (count) {
            result = *(queue + head);
            if (--count) {
                head++;
                head %= length;
            }
        }
        else { printf("Stack is empty\n"); }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
data_t front_vl_queue(void) {
    data_t result = 0;
    if (queue_check()) {
        if (count) { result = *(queue + head); }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool is_empty_vl_queue(void) {
    bool result = true;
    if (queue_check()) {
        result = (count == 0);
    }
    return result;
}
/*----------------------------------------------------------------------------*/
void destroy_vl_queue(void) {
    free(queue);
    queue = NULL;
}
/******************************************************************************/
