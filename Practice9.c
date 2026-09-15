Problem 30:
#include <stdio.h>
#include <ctype.h>


int main(int argc, char *argv[]) {


    if (argc != 3) {
        printf("Usage: ./convert <input_file> <output_file>");
        return 1;
    }


    FILE *fp1 = fopen(argv[1], "r");
    if (fp1 == NULL) {
        printf("Error opening file");
        return 1;
    }


    FILE *fp2 = fopen(argv[2], "w");
    if (fp2 == NULL) {
        printf("Error opening file");
        return 1;
    }


    int ch;
    while((ch = fgetc(fp1)) != EOF) {
        char upper = toupper(ch);
        fputc(upper, fp2);
    }
 
    return 0;
}

Problem 31:
#include <stdio.h>
#include <stdlib.h>


typedef enum {
    STACK_OK, STACK_EMPTY, STACK_MEM_ERROR
} StackStatus;


typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicStack;


void initStack(DynamicStack *s, int initialCapacity);
StackStatus push(DynamicStack *s, int value);
StackStatus pop(DynamicStack *s, int *outValue);
void freeStack(DynamicStack *s);


int main() {
    DynamicStack myStack;
    initStack(&myStack, 2);


    printf("Pushing numbers 10, 20, 30, 40, 50...\n");
    for (int i = 1; i <= 5; i++) {
        push(&myStack, i * 10);
    }


    printf("\nPopping all elements:\n");
    int val;
    while (pop(&myStack, &val) == STACK_OK) {
        printf("Popped: %d\n", val);
    }


    freeStack(&myStack);


    return 0;
}


void initStack(DynamicStack *s, int initialCapacity) {
    s->capacity = initialCapacity;
    s->size = 0;
    s->data = malloc(initialCapacity*sizeof(int));
    if (s->data == NULL) {
        printf("Error in allocation");
        return;
    }
}


StackStatus push(DynamicStack *s, int value) {
    if (s->size == s->capacity) {
        s->capacity *= 2;
        int *temp = realloc(s->data, s->capacity*sizeof(int));
        if (temp == NULL) {
            printf("Error in realloc");
            return STACK_MEM_ERROR;
        }
        s->data = temp;
    }


    s->data[s->size] = value;
    s->size++;
    return STACK_OK;
}


StackStatus pop(DynamicStack *s, int *outValue) {
    if (s->size == 0) {
        return STACK_EMPTY;
    }


    *outValue = s->data[s->size - 1];
    s->size--;
    return STACK_OK;
}


void freeStack(DynamicStack *s) {
    free(s->data);
    s->data = NULL;
    s->size = 0;
    s->capacity = 0;
}
