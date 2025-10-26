#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0; // Current number of elements in heap

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to bubble an element up to its correct spot
void heapifyUp(int index) {
    if (index == 0) return; // At root
    
    int parent = (index - 1) / 2;
    
    // If child is smaller than parent, swap
    if (heap[index] < heap[parent]) {
        swap(&heap[index], &heap[parent]);
        // Recurse on parent's index
        heapifyUp(parent);
    }
}

// Function to insert a new key
void insert(int key) {
    if (size == MAX) {
        printf("Heap is full. Cannot insert %d\n", key);
        return;
    }
    
    // 1. Insert new key at the end
    heap[size] = key;
    
    // 2. Fix the min heap property
    heapifyUp(size);
    
    size++;
    printf("Inserted %d.\n", key);
}

int main() {
    insert(10);
    insert(5);
    insert(15);
    insert(3); // This will bubble up to the top
    
    printf("Heap array: ");
    for(int i=0; i<size; i++) printf("%d ", heap[i]);
    printf("\n"); // Should be 3, 5, 15, 10
    
    return 0;
}