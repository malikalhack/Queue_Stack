/**
 * @file    fl_stack.c
 * @version 1.3.1
 * @authors Anton Chernov
 * @date    23/02/2022
 * @date    18/10/2022
 */

/****************************** Included files ********************************/
#include "common.h"
/****************************** Private  variables ****************************/
static data_t stack[STACK_SIZE];
static volatile index_t top;
static volatile bsize_t count;
/********************* Application Programming Interface **********************/
void create_fl_stack(void) {
    count = 0;
    top   = 0;
}
/*----------------------------------------------------------------------------*/
bool push_fl_stack(data_t num) {
    bool result = false;
    if (top < STACK_SIZE - 1u) {
        if (count++) { stack[++top] = num; }
        else { stack[top] = num; }
        result = true;
    }
    else { printf("Buffer overflow\n"); }
    return result;
}
/*----------------------------------------------------------------------------*/
data_t pop_fl_stack(void) {
    data_t result = 0;
    if (count) {
        if (!top) { result = stack[top]; }
        else { result = stack[top--]; }
        count--;
    }
    else { printf("Stack is empty\n"); }
    return result;
}
/*----------------------------------------------------------------------------*/
data_t top_fl_stack(void) {
    return (count) ? stack[top] : 0;
}
/*----------------------------------------------------------------------------*/
bool is_empty_fl_stack(void) {
    return (count == 0);
}
/******************************************************************************/
