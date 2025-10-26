#include <stdio.h>

// Function to find GCD of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// Function to rotate arr[] of size n by d
void rotateArray(int arr[], int d, int n) {
    d = d % n; // Handle cases where d >= n
    int g_c_d = gcd(n, d);
    int i, j, k, temp;
    
    for (i = 0; i < g_c_d; i++) {
        // Move i-th set of elements
        temp = arr[i];
        j = i;
        while (1) {
            k = j + d;
            if (k >= n)
                k = k - n;
            if (k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2; // Rotate by 2
    
    rotateArray(arr, d, n);
    
    printf("Rotated array is: \n");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}