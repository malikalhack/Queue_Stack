/**
 * @file    vl_stack.c
 * @version 1.3.0
 * @authors Anton Chernov
 * @date    23/02/2022
 * @date    14/10/2022
 */

 /****************************** Included files ********************************/
#include "common.h"
#include <stdlib.h>
#include <malloc.h>
/****************************** Private  variables ****************************/
static uint8_t *stack;
static uint8_t stack_length;
volatile uint8_t stack_top;
volatile uint8_t count;
/****************************** Private  functions ****************************/
static bool queue_check(void) {
    bool result = true;
    if (!stack) {
        printf("Memory access error\n");
        result = false;
    }
    return result;
}
/********************* Application Programming Interface **********************/
bool create_vl_stack(uint8_t buf_size) {
    bool result = false;
    stack = (uint8_t*)calloc(buf_size + 1, 1);
    if (queue_check()) {
        stack_length = buf_size;
        stack_top    = 0;
        count        = 0;
        result       = true;
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool push_vl_stack(uint8_t item) {
    bool result = false;
    if (queue_check()) {
        if (stack_top < STACK_LENGTH - 1u) {
            if (count++) { stack[++stack_top] = item; }
            else { stack[stack_top] = item; }
            result = true;
        }
        else { printf("Buffer overflow\n"); }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t pop_vl_stack(void) {
    uint8_t result = 0u;
    if (queue_check()) {
        if (count) {
            if (!stack_top) { result = stack[stack_top]; }
            else { result = stack[stack_top--]; }
            count--;
        }
        else { printf("Stack is empty\n"); }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t top_vl_stack(void) {
    uint8_t result = 0;
    if (queue_check()) {
        if (count) { result = stack[stack_top]; }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool is_empty_vl_stack(void) {
    bool result = true;
    if (queue_check()) {
        result = (count == 0u);
    }
    return result;
}
/*----------------------------------------------------------------------------*/
void destroy_vl_stack(void) {
    free(stack);
    stack = NULL;
}
/******************************************************************************/
