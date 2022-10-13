/**
 * @file    stack.c
 * @version 1.3.0
 * @authors Anton Chernov
 * @date    23/02/2022
 * @date    14/10/2022
 */

/****************************** Included files ********************************/
#include "common.h"
/****************************** Private  variables ****************************/
static uint8_t stack[STACK_LENGTH];
volatile uint8_t stack_top;
volatile uint8_t count;
/********************* Application Programming Interface **********************/
void create_fl_stack(void) {
    stack_top = 0u;
    count     = 0u;
}
/*----------------------------------------------------------------------------*/
bool push_fl_stack(uint8_t item) {
    bool result = false;
    if (stack_top < STACK_LENGTH - 1u) {
        if (count++) { stack[++stack_top] = item; }
        else { stack[stack_top] = item; }
        result = true;
    } 
    else { printf("Buffer overflow\n"); }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t pop_fl_stack(void) {
    uint8_t result = 0u;
    if (count) {
        if (!stack_top) { result = stack[stack_top]; }
        else { result = stack[stack_top--]; }
        count--;
    }
    else { printf("Stack is empty\n"); }
    return result;
}
/*----------------------------------------------------------------------------*/
uint8_t top_fl_stack(void) {
    return (count) ? stack[stack_top] : 0u;
}
/*----------------------------------------------------------------------------*/
bool is_empty_fl_stack(void) {
    return (count == 0u);
}
/******************************************************************************/
