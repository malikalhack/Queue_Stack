/**
 * @file    main.c
 * @version 1.3.1
 * @authors Anton Chernov
 * @date    16/02/2022
 * @date    18/10/2022
 */

/****************************** Included files ********************************/
#include"fl_stack.h"
#include"fl_queue.h"
#include"vl_stack.h"
#include"vl_queue.h"
/******************************** Definition **********************************/
#define FIXED_SIZE_STACK_TEST   (1)
#define FIXED_LENGTH_QUEUE_TEST (1)
#define VAR_SIZE_STACK_TEST     (1)
#define VAR_LENGTH_QUEUE_TEST   (1)
#define ADDITIONAL_TEST         (1)

#define DISCARD_RETURN(f) ((void)f)
#define TEST_START(name)\
    printf("\n>>> Test start for a %s <<<\n\n", name)
#define TEST_FINISH \
    printf("***************************************************************\n")
/********************************* Entry point ********************************/
int main() {
#if FIXED_SIZE_STACK_TEST
    TEST_START("fixed-size stack (LIFO)");
    create_fl_stack();
    printf("Added symbols with ASCII codes from 48 to 58 into a stack\n");
    for (uint8_t i = 0; i < STACK_SIZE + 1; i++) {
        DISCARD_RETURN(push_fl_stack(48 + i));
    }

#if ADDITIONAL_TEST
    printf("\nGet three characters from the stack:\n");
    for (uint8_t i = 0; i < 3; i++) {
        printf("%c\n", pop_fl_stack());
    }
    printf("Added new symbols with ASCII codes from 65 to 67\n");
    DISCARD_RETURN(push_fl_stack(65));
    DISCARD_RETURN(push_fl_stack(66));
    DISCARD_RETURN(push_fl_stack(67));

    printf("\nThe content of the fixed-size stack:\n");
    for (uint8_t i = 0; i < STACK_SIZE + 1; i++) {
        printf("%c\n", pop_fl_stack());
    }
    printf("Added new symbols with ASCII codes from 68 to 70\n");
    DISCARD_RETURN(push_fl_stack(68));
    DISCARD_RETURN(push_fl_stack(69));
    DISCARD_RETURN(push_fl_stack(70));
#endif

    printf("The top of fixed-size stack: %c\n", top_fl_stack());
    printf("The content of fixed-size stack:\n");
    while (!is_empty_fl_stack()) {
        printf("%c\n", pop_fl_stack());
    }
    TEST_FINISH;
#endif
/*----------------------------------------------------------------------------*/
#if FIXED_LENGTH_QUEUE_TEST
    TEST_START("fixed-length queue (FIFO)");
    create_fl_queue();
    printf("\nAdded symbols with ASCII codes from 48 to 58 into a queue\n");
    for (uint8_t i = 0; i < QUEUE_LENGTH + 1; i++) {
        DISCARD_RETURN(push_fl_queue(48 + i));
    }

#if ADDITIONAL_TEST
    printf("\nGet three characters from the queue:\n");
    for (uint8_t i = 0; i < 3; i++) {
        printf("%c\n", pop_fl_queue());
    }
    printf("Added new symbols with ASCII codes from 65 to 67\n");
    DISCARD_RETURN(push_fl_queue(65));
    DISCARD_RETURN(push_fl_queue(66));
    DISCARD_RETURN(push_fl_queue(67));

    printf("\nThe content of the fixed-length queue:\n");
    for (uint8_t i = 0; i < QUEUE_LENGTH + 1; i++) {
        printf("%c\n", pop_fl_queue());
    }
    printf("Added new symbols with ASCII codes from 68 to 70\n");
    DISCARD_RETURN(push_fl_queue(68));
    DISCARD_RETURN(push_fl_queue(69));
    DISCARD_RETURN(push_fl_queue(70));
#endif

    printf("The front of fixed-length queue: %c\n", front_fl_queue());
    printf("The content of fixed-length queue:\n");
    while (!is_empty_fl_queue()) {
        printf("%c\n", pop_fl_queue());
    }
    TEST_FINISH;
#endif
/*----------------------------------------------------------------------------*/
#if VAR_SIZE_STACK_TEST
    TEST_START("variable-size stack (LIFO)");
    if (create_vl_stack(STACK_SIZE)) {
        printf("\nAdded symbols with ASCII codes from 48 to 58 into a stack\n");
        for (uint8_t i = 0; i < STACK_SIZE + 1; i++) {
            DISCARD_RETURN(push_vl_stack(48 + i));
        }

#if ADDITIONAL_TEST
        printf("\nGet three characters from the stack:\n");
        for (uint8_t i = 0; i < 3; i++) {
            printf("%c\n", pop_vl_stack());
        }
        printf("Added new symbols with ASCII codes from 65 to 67\n");
        DISCARD_RETURN(push_vl_stack(65));
        DISCARD_RETURN(push_vl_stack(66));
        DISCARD_RETURN(push_vl_stack(67));

        printf("\nThe content of the variable-size stack:\n");
        for (uint8_t i = 0; i < STACK_SIZE + 1; i++) {
            printf("%c\n", pop_vl_stack());
        }
        printf("Added new symbols with ASCII codes from 68 to 70\n");
        DISCARD_RETURN(push_vl_stack(68));
        DISCARD_RETURN(push_vl_stack(69));
        DISCARD_RETURN(push_vl_stack(70));
#endif

        printf("The top of variable-size stack: %c\n", top_vl_stack());
        printf("The content of variable-size stack:\n");
        while (!is_empty_vl_stack()) {
            printf("%c\n", pop_vl_stack());
        }

        destroy_vl_stack();
    }
    TEST_FINISH;
#endif
/*----------------------------------------------------------------------------*/
#if VAR_LENGTH_QUEUE_TEST
    TEST_START("variable-length queue (FIFO)");
    if (create_vl_queue(QUEUE_LENGTH)) {
        printf("\nAdded symbols with ASCII codes from 48 to 58 into a queue\n");
        for (uint8_t i = 0; i < QUEUE_LENGTH + 1; i++) {
            DISCARD_RETURN(push_vl_queue(48 + i));
        }

#if ADDITIONAL_TEST
        printf("\nGet three characters from the queue:\n");
        for (uint8_t i = 0; i < 3; i++) {
            printf("%c\n", pop_vl_queue());
        }
        printf("Added new symbols with ASCII codes from 65 to 67\n");
        DISCARD_RETURN(push_vl_queue(65));
        DISCARD_RETURN(push_vl_queue(66));
        DISCARD_RETURN(push_vl_queue(67));

        printf("\nThe content of variable-length queue:\n");
        for (uint8_t i = 0; i < QUEUE_LENGTH + 1; i++) {
            printf("%c\n", pop_vl_queue());
        }
        printf("Added new symbols with ASCII codes from 68 to 70\n");
        DISCARD_RETURN(push_vl_queue(68));
        DISCARD_RETURN(push_vl_queue(69));
        DISCARD_RETURN(push_vl_queue(70));
#endif

        printf("The front of variable-length queue: %c\n", front_vl_queue());
        printf("The content of variable-length queue:\n");
        while (!is_empty_vl_queue()) {
            printf("%c\n", pop_vl_queue());
        }
        destroy_vl_queue();
    }
    TEST_FINISH;
#endif
/*----------------------------------------------------------------------------*/
    getchar();
    return 0;
}
