#include <stdio.h>
#define N 3

// Function to multiply two matrices
void multiplyMatrix(int mat1[][N], int mat2[][N], int res[][N]) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            res[i][j] = 0;
            for (k = 0; k < N; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
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
    int mat1[N][N] = {{1, 1, 1},
                      {2, 2, 2},
                      {3, 3, 3}};
                      
    int mat2[N][N] = {{1, 2, 3},
                      {1, 2, 3},
                      {1, 2, 3}};
                      
    int res[N][N]; // To store result
    
    multiplyMatrix(mat1, mat2, res);
    
    printf("Result of matrix multiplication:\n");
    printMatrix(res);
    
    return 0;
}