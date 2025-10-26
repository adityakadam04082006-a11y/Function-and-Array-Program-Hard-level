#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    // (rear + 1) % SIZE gives the next position.
    // If it's where 'front' is, the queue is full.
    if ((rear + 1) % SIZE == front)
        return 1;
    return 0;
}

int isEmpty() {
    if (front == -1)
        return 1;
    return 0;
}

void enqueue(int val) {
    if (isFull()) {
        printf("Queue is Full. Cannot enqueue %d\n", val);
    } else {
        if (front == -1) front = 0; // First element
        rear = (rear + 1) % SIZE; // Move rear (circularly)
        queue[rear] = val;
        printf("%d enqueued.\n", val);
    }
}

int dequeue() {
    int val;
    if (isEmpty()) {
        printf("Queue is Empty. Cannot dequeue.\n");
        return -1;
    } else {
        val = queue[front];
        if (front == rear) { // Last element
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE; // Move front (circularly)
        }
        return val;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); // Queue is full
    
    printf("Dequeued: %d\n", dequeue());
    enqueue(60); // Now there is space
    
    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());
    
    return 0;
}