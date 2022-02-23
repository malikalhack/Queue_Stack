/**
* @file    stack.c
* @version 1.0.0
* @authors Anton Chernov
* @date    23/02/2022
*/

/****************************** Included files ********************************/
#include "stack.h"
#include <stdio.h>
/****************************** Private  variables ****************************/
uint8_t fixed_length_stack[STACK_LENGTH];
volatile uint8_t fixed_length_stack_top;
volatile bool empty_fixed_length_stack;
/*----------------------------------------------------------------------------*/
uint8_t *variable_length_stack;
uint8_t vl_stack_length;
volatile uint8_t variable_length_stack_top;
volatile bool empty_variable_length_stack;
/********************* Application Programming Interface **********************/
void create_fixed_length_stack(void) {
    for (uint8_t i = 0; i < STACK_LENGTH; i++) {
        fixed_length_stack[i] = 0;
    }
    fixed_length_stack_top = 0;
    empty_fixed_length_stack = true;
}
/*----------------------------------------------------------------------------*/
bool push_fix_stack(uint8_t item) {
    bool result = false;
    if (empty_fixed_length_stack) {
        fixed_length_stack[fixed_length_stack_top] = item;
        empty_fixed_length_stack = false;
        result = true;
    }
    else {
        if (++fixed_length_stack_top < STACK_LENGTH) {
            fixed_length_stack[fixed_length_stack_top] = item;
            result = true;
        }
        else {
            fixed_length_stack_top = STACK_LENGTH - 1;
            printf("Buffer overflow\n");
        }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t pop_fix_stack(void) {
    uint8_t result = 0;
    if (!empty_fixed_length_stack) {
        if (!fixed_length_stack_top) {
            empty_fixed_length_stack = true;
            result = fixed_length_stack[fixed_length_stack_top];
        }
        else result = fixed_length_stack[fixed_length_stack_top--];
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t top_fix_stack(void) {
    uint8_t result = 0;
    if (!empty_fixed_length_stack) {
        result = fixed_length_stack[fixed_length_stack_top];
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool is_empty_fix_stack(void) {
    return empty_fixed_length_stack;
}
/*----------------------------------------------------------------------------*/
bool create_variable_length_stack(uint8_t buf_size) {
    bool result = false;
    variable_length_stack = (uint8_t*)calloc(buf_size + 1, 1);
    if (variable_length_stack) {
        vl_stack_length = buf_size;
        variable_length_stack_top = 0;
        empty_variable_length_stack = true;

        result = true;
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool push_var_stack(uint8_t item) {
    bool result = false;
    if (empty_variable_length_stack) {
        variable_length_stack[variable_length_stack_top] = item;
        empty_variable_length_stack = false;
        result = true;
    }
    else {
        if (++variable_length_stack_top < vl_stack_length) {
            variable_length_stack[variable_length_stack_top] = item;
            result = true;
        }
        else {
            variable_length_stack_top = vl_stack_length - 1;
            printf("Buffer overflow\n");
        }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t pop_var_stack(void) {
    uint8_t result = 0;
    if (!empty_variable_length_stack) {
        if (!variable_length_stack_top) {
            empty_variable_length_stack = true;
            result = variable_length_stack[variable_length_stack_top];
        }
        else result = variable_length_stack[variable_length_stack_top--];
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t top_var_stack(void) {
    uint8_t result = 0;
    if (!empty_variable_length_stack) {
        result = variable_length_stack[variable_length_stack_top];
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool is_empty_var_stack(void) {
    return empty_variable_length_stack;
}
/*----------------------------------------------------------------------------*/
void destroy_variable_length_stack(void) {
    free(variable_length_stack);
}
/******************************************************************************/
