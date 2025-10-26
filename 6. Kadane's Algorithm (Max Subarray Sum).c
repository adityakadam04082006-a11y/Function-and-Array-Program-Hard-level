#include <stdio.h>
#include <limits.h> // For INT_MIN

// Function to find max subarray sum
int maxSubArraySum(int arr[], int size) {
    int max_so_far = INT_MIN;
    int current_max = 0;
    int start = 0, end = 0, s = 0;

    for (int i = 0; i < size; i++) {
        current_max = current_max + arr[i];

        if (max_so_far < current_max) {
            max_so_far = current_max;
            start = s;
            end = i;
        }

        if (current_max < 0) {
            current_max = 0;
            s = i + 1;
        }
    }
    
    printf("Max sum subarray is from index %d to %d\n", start, end);
    return max_so_far;
}

int main() {
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    
    int max_sum = maxSubArraySum(a, n);
    
    printf("Maximum contiguous sum is %d\n", max_sum);
    
    return 0;
}