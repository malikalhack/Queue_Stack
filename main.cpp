/**
 * @file    main.cpp
 * @version 1.0.0
 * @authors Anton Chernov
 * @date    16/02/2022
 */

/****************************** Included files ********************************/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
/******************************** Definition **********************************/
//#define ADDITION_TEST
#define DISCARD_RETURN(f) ((void)f)

#define QUEUE_LENGTH    (10)
#define STACK_LENGTH    (10)
/******************************* Global variables *****************************/
uint8_t fixed_length_stack[STACK_LENGTH];
volatile uint8_t fixed_length_stack_top;
volatile bool empty_fixed_length_stack;
/*----------------------------------------------------------------------------*/
uint8_t fixed_length_queue[QUEUE_LENGTH];
volatile uint8_t fixed_length_queue_front;
volatile uint8_t fixed_length_queue_tail;
volatile bool empty_fixed_length_queue;
/*----------------------------------------------------------------------------*/
uint8_t *variable_length_stack;
uint8_t vl_stack_length;
volatile uint8_t variable_length_stack_top;
volatile bool empty_variable_length_stack;
/*----------------------------------------------------------------------------*/
uint8_t *variable_length_queue;
uint8_t vl_queue_length;
volatile uint8_t variable_length_queue_front;
volatile uint8_t variable_length_queue_tail;
volatile bool empty_variable_length_queue;
/*************************** Function's prototypes ****************************/
void create_fixed_length_stack(void);
bool push_fix_stack(uint8_t);
uint8_t pop_fix_stack(void);
uint8_t top_fix_stack(void);
bool is_empty_fix_stack(void);
/*----------------------------------------------------------------------------*/
void create_fixed_length_queue(void);
bool push_fix_queue(uint8_t);
uint8_t pop_fix_queue(void);
uint8_t front_fix_queue(void);
bool is_empty_fix_queue(void);
/*----------------------------------------------------------------------------*/
bool create_variable_length_stack(uint8_t);
bool push_var_stack(uint8_t);
uint8_t pop_var_stack(void);
uint8_t top_var_stack(void);
bool is_empty_var_stack(void);
/*----------------------------------------------------------------------------*/
bool create_variable_length_queue(uint8_t);
bool push_var_queue(uint8_t);
uint8_t pop_var_queue(void);
uint8_t front_var_queue(void);
bool is_empty_var_queue(void);
/********************************* Entry point ********************************/
int main() {
    create_fixed_length_stack();
    for (uint8_t i = 0; i < (STACK_LENGTH + 1); i++) {
        DISCARD_RETURN(push_fix_stack(48 + i));
    }

#ifdef ADDITION_TEST
    printf("%d\n", pop_fix_stack());
    printf("%d\n", pop_fix_stack());
    printf("%d\n", pop_fix_stack());
    DISCARD_RETURN(push_fix_stack(58));
    DISCARD_RETURN(push_fix_stack(59));
    DISCARD_RETURN(push_fix_stack(60));
#endif

    printf("The top of fixed-length stack: %d\n", top_fix_stack());
    printf("The content of fixed-length stack:\n");
    while (!is_empty_fix_stack()) {
        printf("%d\n", pop_fix_stack());
    }
/*----------------------------------------------------------------------------*/
    create_fixed_length_queue();
    for (uint8_t i = 0; i < (QUEUE_LENGTH + 1); i++) {
        DISCARD_RETURN(push_fix_queue(48 + i));
    }

#ifdef ADDITION_TEST
    printf("%d\n", pop_fix_queue());
    printf("%d\n", pop_fix_queue());
    printf("%d\n", pop_fix_queue());
    DISCARD_RETURN(push_fix_queue(58));
    DISCARD_RETURN(push_fix_queue(59));
    DISCARD_RETURN(push_fix_queue(60));
#endif

    printf("The front of fixed-length queue: %d\n", front_fix_queue());
    printf("The content of fixed-length queue:\n");
    while (!is_empty_fix_queue()) {
        printf("%d\n", pop_fix_queue());
    }
/*----------------------------------------------------------------------------*/
    if (create_variable_length_stack(STACK_LENGTH)) {
        for (uint8_t i = 0; i < (STACK_LENGTH + 1); i++) {
            DISCARD_RETURN(push_var_stack(48 + i));
        }

#ifdef ADDITION_TEST
        printf("%d\n", pop_var_stack());
        printf("%d\n", pop_var_stack());
        printf("%d\n", pop_var_stack());
        DISCARD_RETURN(push_var_stack(58));
        DISCARD_RETURN(push_var_stack(59));
        DISCARD_RETURN(push_var_stack(60));
#endif

        printf("The top of variable-length stack: %d\n", top_var_stack());
        printf("The content of variable-length stack:\n");
        while (!is_empty_var_stack()) {
            printf("%d\n", pop_var_stack());
        }

        free(variable_length_stack);
    }
/*----------------------------------------------------------------------------*/
    if (create_variable_length_queue(STACK_LENGTH)) {
        for (uint8_t i = 0; i < (QUEUE_LENGTH + 1); i++) {
            DISCARD_RETURN(push_var_queue(48 + i));
        }

#ifdef ADDITION_TEST
        printf("%d\n", pop_var_queue());
        printf("%d\n", pop_var_queue());
        printf("%d\n", pop_var_queue());
        DISCARD_RETURN(push_var_queue(58));
        DISCARD_RETURN(push_var_queue(59));
        DISCARD_RETURN(push_var_queue(60));
#endif

        printf("The front of variable-length queue: %d\n", front_var_queue());
        printf("The content of variable-length queue:\n");
        while (!is_empty_var_queue()) {
            printf("%d\n", pop_var_queue());
        }
        free(variable_length_queue);
    }
/*----------------------------------------------------------------------------*/
    getchar();
    return 0;
}
/********************* Application Programming Interface **********************/
void create_fixed_length_queue(void) {
    for (uint8_t i = 0; i < QUEUE_LENGTH; i++) {
        fixed_length_queue[i] = 0;
    }
    fixed_length_queue_front = 0;
    fixed_length_queue_tail = 0;
    empty_fixed_length_queue = true;
}
/******************************************************************************/
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
/******************************************************************************/
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
/******************************************************************************/
uint8_t front_fix_queue(void) {
    uint8_t result = 0;
    if (!empty_fixed_length_queue) {
        result = fixed_length_queue[fixed_length_queue_front];
    }
    return result;
}
/******************************************************************************/
bool is_empty_fix_queue(void) {
    return empty_fixed_length_queue;
}
/******************************************************************************/
void create_fixed_length_stack(void) {
    for (uint8_t i = 0; i < STACK_LENGTH; i++) {
        fixed_length_stack[i] = 0;
    }
    fixed_length_stack_top = 0;
    empty_fixed_length_stack = true;
}
/******************************************************************************/
bool push_fix_stack(uint8_t item) {
    bool result = false;
    if (empty_fixed_length_stack) {
        fixed_length_stack[fixed_length_stack_top] = item;
        empty_fixed_length_stack = false;
        result = true;
    }
    else {
        if (++fixed_length_stack_top < QUEUE_LENGTH) {
            fixed_length_stack[fixed_length_stack_top] = item;
            result = true;
        }
        else {
            fixed_length_stack_top = QUEUE_LENGTH - 1;
            printf("Buffer overflow\n");
        }
    }
    return result;
}
/******************************************************************************/
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
/******************************************************************************/
uint8_t top_fix_stack(void) {
    uint8_t result = 0;
    if (!empty_fixed_length_stack) {
        result = fixed_length_stack[fixed_length_stack_top];
    }
    return result;
}

bool is_empty_fix_stack(void) {
    return empty_fixed_length_stack;
}

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
/******************************************************************************/
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
/******************************************************************************/
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
/******************************************************************************/
uint8_t top_var_stack(void) {
    uint8_t result = 0;
    if (!empty_variable_length_stack) {
        result = variable_length_stack[variable_length_stack_top];
    }
    return result;
}
/******************************************************************************/
bool is_empty_var_stack(void) {
    return empty_variable_length_stack;
}
/******************************************************************************/
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
/******************************************************************************/
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
/******************************************************************************/
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
/******************************************************************************/
uint8_t front_var_queue(void) {
    uint8_t result = 0;
    if (!empty_variable_length_queue) {
        result = variable_length_queue[variable_length_queue_front];
    }
    return result;
}
/******************************************************************************/
bool is_empty_var_queue(void) {
    return empty_variable_length_queue;
}
/******************************************************************************/
