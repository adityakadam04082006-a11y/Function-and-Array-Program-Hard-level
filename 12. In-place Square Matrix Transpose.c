#include <stdio.h>
#define N 4

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to transpose a square matrix in-place
void transposeInPlace(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        // Only loop j from i to N
        // This processes the upper triangle only
        for (int j = i; j < N; j++) {
            if (i != j) {
                swap(&mat[i][j], &mat[j][i]);
            }
        }
    }
}

void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat[N][N] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
                     
    printf("Original Matrix:\n");
    printMatrix(mat);
    
    transposeInPlace(mat);
    
    printf("\nTransposed Matrix:\n");
    printMatrix(mat);
    
    return 0;
}