/**
 * @file    vl_stack.c
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
static data_t *stack;
static bsize_t s_size;
static volatile index_t top;
static volatile bsize_t count;
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
bool create_vl_stack(bsize_t buf_size) {
    bool result = false;
    stack = (data_t*)calloc(buf_size, sizeof(data_t));
    if (stack_check()) {
        s_size = buf_size;
        count  = 0;
        top    = 0;
        result = true;
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool push_vl_stack(data_t num) {
    bool result = false;
    if (stack_check()) {
        if (top < s_size - 1u) {
            if (count++) { stack[++top] = num; }
            else { stack[top] = num; }
            result = true;
        }
        else { printf("Buffer overflow\n"); }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
data_t pop_vl_stack(void) {
    data_t result = 0;
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
data_t top_vl_stack(void) {
    data_t result = 0;
    if (stack_check()) {
        if (count) { result = stack[top]; }
    }
    return result;
}
/*----------------------------------------------------------------------------*/
bool is_empty_vl_stack(void) {
    bool result = true;
    if (stack_check()) {
        result = (count == 0);
    }
    return result;
}
/*----------------------------------------------------------------------------*/
void destroy_vl_stack(void) {
    free(stack);
    stack = NULL;
}
/******************************************************************************/
