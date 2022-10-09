/**
 * @file    vl_stack.c
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
uint8_t *stack;
uint8_t stack_length;
volatile uint8_t stack_top;
volatile bool is_empty;
/********************* Application Programming Interface **********************/
bool create_vl_stack(uint8_t buf_size) {
    bool result = false;
    stack = (uint8_t*)calloc(buf_size + 1, 1);
    if (stack) {
        stack_length = buf_size;
        stack_top = 0;
        is_empty = true;

        result = true;
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool push_vl_stack(uint8_t item) {
    bool result = false;
    if (is_empty) {
        stack[stack_top] = item;
        is_empty = false;
        result = true;
    }
    else {
        if (++stack_top < stack_length) {
            stack[stack_top] = item;
            result = true;
        }
        else {
            stack_top = stack_length - 1;
            printf("Buffer overflow\n");
        }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t pop_vl_stack(void) {
    uint8_t result = 0;
    if (!is_empty) {
        if (!stack_top) {
            is_empty = true;
            result = stack[stack_top];
        }
        else result = stack[stack_top--];
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t top_vl_stack(void) {
    uint8_t result = 0;
    if (!is_empty) {
        result = stack[stack_top];
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool is_empty_vl_stack(void) {
    return is_empty;
}
/*----------------------------------------------------------------------------*/
void destroy_vl_stack(void) {
    free(stack);
    stack = NULL;
}
/******************************************************************************/
