#include <stdio.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if queue is full
int isFull() {
    return rear == MAX_SIZE - 1;
}

// Function to check if queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Function to add an item (enqueue)
void enqueue(int item) {
    if (isFull()) {
        printf("Queue is Full! Cannot add %d.\n", item);
    } else {
        if (front == -1) front = 0; // First element
        rear++;
        queue[rear] = item;
        printf("%d added to queue.\n", item);
    }
}

// Function to remove an item (dequeue)
int dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty! Cannot remove.\n");
        return -1;
    } else {
        int item = queue[front];
        front++;
        return item;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    
    printf("%d removed from queue.\n", dequeue());
    printf("%d removed from queue.\n", dequeue());
    printf("%d removed from queue.\n", dequeue()); // Triggers empty
    
    return 0;
}