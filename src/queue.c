/**
* @file    queue.c
* @version 1.0.0
* @authors Anton Chernov
* @date    23/02/2022
*/

/****************************** Included files ********************************/
#include "queue.h"
#include <stdio.h>
/****************************** Private  variables ****************************/
uint8_t fixed_length_queue[QUEUE_LENGTH];
volatile uint8_t fixed_length_queue_front;
volatile uint8_t fixed_length_queue_tail;
volatile bool empty_fixed_length_queue;
/*----------------------------------------------------------------------------*/
uint8_t *variable_length_queue;
uint8_t vl_queue_length;
volatile uint8_t variable_length_queue_front;
volatile uint8_t variable_length_queue_tail;
volatile bool empty_variable_length_queue;
/********************* Application Programming Interface **********************/
void create_fixed_length_queue(void) {
    for (uint8_t i = 0; i < QUEUE_LENGTH; i++) {
        fixed_length_queue[i] = 0;
    }
    fixed_length_queue_front = 0;
    fixed_length_queue_tail = 0;
    empty_fixed_length_queue = true;
}
/*----------------------------------------------------------------------------*/
bool push_fix_queue(uint8_t item) {
    bool result = false;
    if (empty_fixed_length_queue) {
        fixed_length_queue[fixed_length_queue_front] = item;
        empty_fixed_length_queue = false;
        result = true;
    }
    else {
        uint8_t old_fixed_length_queue_tail = fixed_length_queue_tail++;
        if (fixed_length_queue_tail >= QUEUE_LENGTH) {
            fixed_length_queue_tail = 0;
        }
        if (fixed_length_queue_tail != fixed_length_queue_front) {
            fixed_length_queue[fixed_length_queue_tail] = item;
            result = true;
        }
        else {
            fixed_length_queue_tail = old_fixed_length_queue_tail;
            printf("Buffer overflow\n");
        }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t pop_fix_queue(void) {
    uint8_t result = 0;
    if (!empty_fixed_length_queue) {
        if (fixed_length_queue_tail == fixed_length_queue_front) {
            empty_fixed_length_queue = true;
            result = fixed_length_queue[fixed_length_queue_front];
        }
        else {
            result = fixed_length_queue[fixed_length_queue_front++];
            if (fixed_length_queue_front >= QUEUE_LENGTH) {
                fixed_length_queue_front = 0;
            }
        }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t front_fix_queue(void) {
    uint8_t result = 0;
    if (!empty_fixed_length_queue) {
        result = fixed_length_queue[fixed_length_queue_front];
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool is_empty_fix_queue(void) {
    return empty_fixed_length_queue;
}
/*----------------------------------------------------------------------------*/
bool create_variable_length_queue(uint8_t buf_size) {
    bool result = false;
    variable_length_queue = (uint8_t*)calloc(buf_size + 1, 1);
    if (variable_length_queue) {
        vl_queue_length = buf_size;
        variable_length_queue_front = 0;
        variable_length_queue_tail = 0;
        empty_variable_length_queue = true;
        result = true;
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool push_var_queue(uint8_t item) {
    bool result = false;
    if (empty_variable_length_queue) {
        variable_length_queue[variable_length_queue_front] = item;
        empty_variable_length_queue = false;
        result = true;
    }
    else {
        uint8_t old_variable_length_queue_tail = variable_length_queue_tail++;
        if (variable_length_queue_tail >= vl_queue_length) {
            variable_length_queue_tail = 0;
        }
        if (variable_length_queue_tail != variable_length_queue_front) {
            variable_length_queue[variable_length_queue_tail] = item;
            result = true;
        }
        else {
            variable_length_queue_tail = old_variable_length_queue_tail;
            printf("Buffer overflow\n");
        }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t pop_var_queue(void) {
    uint8_t result = 0;
    if (!empty_variable_length_queue) {
        if (variable_length_queue_tail == variable_length_queue_front) {
            empty_variable_length_queue = true;
            result = variable_length_queue[variable_length_queue_front];
        }
        else {
            result = variable_length_queue[variable_length_queue_front++];
            if (variable_length_queue_front >= vl_queue_length) {
                variable_length_queue_front = 0;
            }
        }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t front_var_queue(void) {
    uint8_t result = 0;
    if (!empty_variable_length_queue) {
        result = variable_length_queue[variable_length_queue_front];
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool is_empty_var_queue(void) {
    return empty_variable_length_queue;
}
/*----------------------------------------------------------------------------*/
void destroy_variable_length_queue(void) {
    free(variable_length_queue);
}
/******************************************************************************/
