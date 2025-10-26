#include <stdio.h>
#include <string.h>
#define RANGE 10 // Assuming numbers are 0-9

// Function to perform counting sort
void countingSort(int arr[], int n, int output[]) {
    // 1. Create a count array
    int count[RANGE] = {0};
    int i;
    
    // 2. Store count of each number
    for (i = 0; i < n; i++)
        count[arr[i]]++;
        
    // 3. Store cumulative count
    // count[i] now contains actual position of this number
    for (i = 1; i < RANGE; i++)
        count[i] += count[i - 1];
        
    // 4. Build the output array (traverse input from end)
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--; // Decrease count for this number
    }
}

int main() {
    int arr[] = {1, 4, 1, 2, 7, 5, 2, 9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int output[n];
    
    countingSort(arr, n, output);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", output[i]);
    printf("\n");
    
    return 0;
}