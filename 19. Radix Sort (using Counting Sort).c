#include <stdio.h>

// Function to get max value in arr[]
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Counting sort for a specific digit (exp)
void countSortForRadix(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = {0};
    
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
        
    // Store cumulative count
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
        
    // Build output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    // Copy output back to arr[]
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main Radix Sort function
void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    
    // Do counting sort for every digit.
    // exp is 1, 10, 100...
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSortForRadix(arr, n, exp);
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    radixSort(arr, n);
    
    printf("Sorted array (Radix): ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}