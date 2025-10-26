#include <stdio.h>

// Function to print A - B (elements in A but not B)
void printDifference(int arr1[], int n1, int arr2[], int n2) {
    int i = 0, j = 0;
    
    printf("Difference (A - B): ");
    
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            // Element is unique to arr1
            printf("%d ", arr1[i]);
            i++;
        } else if (arr2[j] < arr1[i]) {
            // Element is unique to arr2, ignore
            j++;
        } else {
            // Element is common, ignore and advance both
            i++;
            j++;
        }
    }
    
    // Print remaining elements of arr1
    while (i < n1) {
        printf("%d ", arr1[i]);
        i++;
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 2, 5, 7, 9, 10};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int arr2[] = {2, 3, 5, 8, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printDifference(arr1, n1, arr2, n2); // Should print 1, 7, 9
    
    return 0;
}