#include <stdio.h>

#define MAXIMUM 100

struct Stack {
    char data[MAXIMUM];
    int top;
};

// Initialize stack
void InitializeStack(struct Stack *stack) {
    stack->top = -1;
}

// Checking if the stack is empty
char IsEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Checking if the stack is full
char IsFull(struct Stack *stack) {
    return stack->top == MAXIMUM - 1;
}

// Push operation
void Push(struct Stack *stack, char value) {
    if (IsFull(stack)) {
        printf("Stack Overflow\n");
    } else {
        stack->top++;
        stack->data[stack->top] = value;
    }
}

// Pop operation
char Pop(struct Stack *stack) {
    if (IsEmpty(stack)) {
        printf("Stack Empty\n");
        return -1; // Return -1 indicating an error or underflow
    } else {
        char value = stack->data[stack->top];
        stack->top--;
        return value;
    }
}
// Function to reverse a string using a stack
void ReverseStringUsingStack(char* str) {
    struct Stack stack;
    InitializeStack(&stack);

    // Push characters of the string onto the stack
    for (int i = 0; i < strlen(str); i++) {
        Push(&stack, str[i]);
    }

    // Pop characters from the stack to reverse the string
    int index = 0;
    while (!IsEmpty(&stack)) {
        str[index++] = Pop(&stack);
    }
}

int main(void) {
    char str[] = "Hello, World!";
    printf("Original string: %s\n", str);

    // Reverse the string using the stack
    ReverseStringUsingStack(str);
    printf("Reversed string: %s\n", str);

    return 0;
}