#include <stdio.h>
#define R 4
#define C 5

// Function to create sparse 3-tuple representation
int createSparse(int mat[R][C], int sparse[R * C][3]) {
    int i, j;
    int k = 0; // Current row in sparse matrix
    
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;       // Store row
                sparse[k][1] = j;       // Store column
                sparse[k][2] = mat[i][j]; // Store value
                k++; // Move to next row in sparse
            }
        }
    }
    return k; // Return number of non-zero elements
}

int main() {
    int matrix[R][C] = {{0, 0, 3, 0, 4},
                        {0, 0, 5, 7, 0},
                        {0, 0, 0, 0, 0},
                        {0, 2, 6, 0, 0}};
                        
    // Max non-zero can be R*C
    int sparseMatrix[R * C][3];
    
    int nonZeroCount = createSparse(matrix, sparseMatrix);
    
    printf("Sparse Matrix (Row, Col, Value):\n");
    for (int i = 0; i < nonZeroCount; i++) {
        printf("%d\t %d\t %d\n", 
            sparseMatrix[i][0], 
            sparseMatrix[i][1], 
            sparseMatrix[i][2]);
    }
    return 0;
}