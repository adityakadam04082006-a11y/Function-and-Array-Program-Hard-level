#include <stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1; // Stack is initially empty

// Function to check if stack is full
int isFull() {
    return top == MAX_SIZE - 1;
}

// Function to check if stack is empty
int isEmpty() {
    return top == -1;
}

// Function to add an item to the stack
void push(int item) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d.\n", item);
    } else {
        top++;
        stack[top] = item;
        printf("%d pushed to stack.\n", item);
    }
}

// Function to remove an item from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1; // Return an error value
    } else {
        int item = stack[top];
        top--;
        return item;
    }
}

int main() {
    push(10);
    push(20);
    
    printf("%d popped from stack.\n", pop());
    printf("%d popped from stack.\n", pop());
    printf("%d popped from stack.\n", pop()); // Triggers underflow
    
    return 0;
}