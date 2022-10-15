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
static uint8_t s_size;
static volatile uint8_t top;
static volatile uint8_t count;
/****************************** Private  functions ****************************/
static bool stack_check(void) {
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
    stack = (uint8_t*)calloc(buf_size, 1);
    if (stack_check()) {
        s_size = buf_size;
        count  = 0u;
        top    = 0u;
        result = true;
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool push_vl_stack(uint8_t item) {
    bool result = false;
    if (stack_check()) {
        if (top < STACK_LENGTH - 1u) {
            if (count++) { stack[++top] = item; }
            else { stack[top] = item; }
            result = true;
        }
        else { printf("Buffer overflow\n"); }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t pop_vl_stack(void) {
    uint8_t result = 0u;
    if (stack_check()) {
        if (count) {
            if (!top) { result = stack[top]; }
            else { result = stack[top--]; }
            count--;
        }
        else { printf("Stack is empty\n"); }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t top_vl_stack(void) {
    uint8_t result = 0;
    if (stack_check()) {
        if (count) { result = stack[top]; }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool is_empty_vl_stack(void) {
    bool result = true;
    if (stack_check()) {
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
