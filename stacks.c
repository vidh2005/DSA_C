#include <stdio.h>
#define MAX 100 // Maximum capacity of the stack

typedef struct {
    int data[MAX];
    int top;
} Stack;

// Function to initialize the stack
void create(Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is full
int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push %d onto the stack.\n", value);
        return;
    }
    stack->data[++stack->top] = value;
    printf("Pushed %d onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. No elements to pop.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Function to display the stack elements
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

// Main function to test the stack operations
int main() {
    Stack stack;
    create(&stack);
    
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped %d from the stack.\n", value);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
