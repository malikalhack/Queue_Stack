/**
 * @file    stack.c
 * @version 1.2.2
 * @authors Anton Chernov
 * @date    23/02/2022
 * @date    09/10/2022
 */

/****************************** Included files ********************************/
#include "common.h"
/****************************** Private  variables ****************************/
uint8_t stack[STACK_LENGTH];
volatile uint8_t stack_top;
volatile bool is_empty;
/********************* Application Programming Interface **********************/
void create_fl_stack(void) {
    for (uint8_t i = 0; i < STACK_LENGTH; i++) {
        stack[i] = 0;
    }
    stack_top = 0;
    is_empty = true;
}
/*----------------------------------------------------------------------------*/
bool push_fl_stack(uint8_t item) {
    bool result = false;
    if (is_empty) {
        stack[stack_top] = item;
        is_empty = false;
        result = true;
    }
    else {
        if (++stack_top < STACK_LENGTH) {
            stack[stack_top] = item;
            result = true;
        }
        else {
            stack_top = STACK_LENGTH - 1;
            printf("Buffer overflow\n");
        }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t pop_fl_stack(void) {
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
uint8_t top_fl_stack(void) {
    uint8_t result = 0;
    if (!is_empty) {
        result = stack[stack_top];
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool is_empty_fl_stack(void) {
    return is_empty;
}
/******************************************************************************/
