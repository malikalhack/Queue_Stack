/**
 * @file    main.c
 * @version 1.2.0
 * @authors Anton Chernov
 * @date    16/02/2022
 * @date    23/02/2022
 */

/****************************** Included files ********************************/
#include "stack.h"
#include "queue.h"
#include <stdio.h>
/******************************** Definition **********************************/
#define FIXED_LENGTH_STACK_TEST (1)
#define FIXED_LENGTH_QUEUE_TEST (1)
#define VAR_LENGTH_STACK_TEST   (1)
#define VAR_LENGTH_QUEUE_TEST   (1)
#define ADDITIONAL_TEST         (0)

#define DISCARD_RETURN(f) ((void)f)
/********************************* Entry point ********************************/
int main() {
#if FIXED_LENGTH_STACK_TEST
    create_fixed_length_stack();
    for (uint8_t i = 0; i < (STACK_LENGTH + 1); i++) {
        DISCARD_RETURN(push_fix_stack(48 + i));
    }

#if ADDITIONAL_TEST
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
#endif
/*----------------------------------------------------------------------------*/
#if FIXED_LENGTH_QUEUE_TEST
    create_fixed_length_queue();
    for (uint8_t i = 0; i < (QUEUE_LENGTH + 1); i++) {
        DISCARD_RETURN(push_fix_queue(48 + i));
    }

#if ADDITIONAL_TEST
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
#endif
/*----------------------------------------------------------------------------*/
#if VAR_LENGTH_STACK_TEST
    if (create_variable_length_stack(STACK_LENGTH)) {
        for (uint8_t i = 0; i < (STACK_LENGTH + 1); i++) {
            DISCARD_RETURN(push_var_stack(48 + i));
        }

#if ADDITIONAL_TEST
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

        destroy_variable_length_stack();
    }
#endif
/*----------------------------------------------------------------------------*/
#if VAR_LENGTH_QUEUE_TEST
    if (create_variable_length_queue(STACK_LENGTH)) {
        for (uint8_t i = 0; i < (QUEUE_LENGTH + 1); i++) {
            DISCARD_RETURN(push_var_queue(48 + i));
        }

#if ADDITIONAL_TEST
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
        destroy_variable_length_queue();
    }
#endif
/*----------------------------------------------------------------------------*/
    getchar();
    return 0;
}
