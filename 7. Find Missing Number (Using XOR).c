#include <stdio.h>

// Function to find the missing number
int findMissing(int arr[], int n) {
    // n is the count of numbers in array (so n+1 is total)
    
    // 1. XOR all elements in the array
    int x1 = arr[0];
    for (int i = 1; i < n; i++)
        x1 = x1 ^ arr[i];
        
    // 2. XOR all numbers from 1 to (n+1)
    int x2 = 1;
    for (int i = 2; i <= n + 1; i++)
        x2 = x2 ^ i;
        
    // 3. XOR the two results
    // All matching numbers will cancel out, leaving the missing one.
    return (x1 ^ x2);
}

int main() {
    // Array has n=5 elements, so range is 1 to 6
    int arr[] = {1, 2, 4, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int missing = findMissing(arr, n);
    
    printf("The missing number is: %d\n", missing);
    
    return 0;
}