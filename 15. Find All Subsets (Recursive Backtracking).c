#include <stdio.h>

// Function to print the current subset
void printSubset(int subset[], int n) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

// Recursive backtracking function
// arr[] = input array
// subset[] = current subset being built
// index = current index in arr[]
// sub_index = current index in subset[]
void findAllSubsets(int arr[], int n, int subset[], int index, int sub_index) {
    
    // 1. Print the current subset
    printSubset(subset, sub_index);
    
    // 2. Iterate through remaining elements
    for (int i = index; i < n; i++) {
        // Include arr[i] in the subset
        subset[sub_index] = arr[i];
        
        // Recurse for elements after i
        findAllSubsets(arr, n, subset, i + 1, sub_index + 1);
        
        // Exclude arr[i] (this is the "backtrack" step,
        // as the next loop iteration overwrites it)
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int subset[n]; // Temp array to hold a subset
    
    printf("All subsets of {1, 2, 3}:\n");
    findAllSubsets(arr, n, subset, 0, 0);
    
    return 0;
}