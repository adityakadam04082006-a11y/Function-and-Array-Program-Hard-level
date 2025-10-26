#include <stdio.h>
#define N 3

// Function to rotate a matrix 90 degrees clockwise
void rotateMatrix(int mat[][N], int rotated[][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            // New row index is old column index
            // New column index is N - 1 - old row index
            rotated[j][N - 1 - i] = mat[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int mat[][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat[N][N] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};
                     
    int rotated[N][N];
    
    rotateMatrix(mat, rotated);
    
    printf("Original Matrix:\n");
    printMatrix(mat);
    
    printf("\nRotated Matrix:\n");
    printMatrix(rotated);
    
    return 0;
}