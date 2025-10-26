#include <stdio.h>

// Function to find max of two integers
int max(int a, int b) { return (a > b) ? a : b; }
// Function to find min of two integers
int min(int a, int b) { return (a < b) ? a : b; }

// Function to get median of a single array
int median(int arr[], int n) {
    if (n % 2 == 0)
        return (arr[n / 2] + arr[n / 2 - 1]) / 2;
    else
        return arr[n / 2];
}

// Recursive function to find median
int getMedian(int ar1[], int ar2[], int n) {
    // Base cases
    if (n <= 0) return -1;
    if (n == 1) return (ar1[0] + ar2[0]) / 2;
    if (n == 2) return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;
    
    int m1 = median(ar1, n); // Get median of ar1
    int m2 = median(ar2, n); // Get median of ar2
    
    if (m1 == m2) return m1;
    
    if (m1 < m2) {
        // If m1 < m2, median must be in ar1[m1...] or ar2[...m2]
        if (n % 2 == 0)
            return getMedian(ar1 + n / 2 - 1, ar2, n - n / 2 + 1);
        return getMedian(ar1 + n / 2, ar2, n - n / 2);
    } else {
        // If m1 > m2, median must be in ar1[...m1] or ar2[m2...]
        if (n % 2 == 0)
            return getMedian(ar2 + n / 2 - 1, ar1, n - n / 2 + 1);
        return getMedian(ar2 + n / 2, ar1, n - n / 2);
    }
}

int main() {
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};
    int n = sizeof(ar1) / sizeof(ar1[0]);
    
    printf("Median is %d\n", getMedian(ar1, ar2, n)); // Should be 16
    
    return 0;
}