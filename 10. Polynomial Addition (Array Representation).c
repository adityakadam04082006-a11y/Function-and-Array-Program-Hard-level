#include <stdio.h>
#define MAX 10 // Max degree of polynomial + 1

// Function to add two polynomials
// poly1, poly2 are input, polySum is output
void polyAdd(int poly1[], int poly2[], int polySum[], int n) {
    for (int i = 0; i < n; i++) {
        polySum[i] = poly1[i] + poly2[i];
    }
}

// Function to print a polynomial
void printPoly(int poly[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%dx^%d", poly[i], i);
            if (i != 0) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

int main() {
    // 5x^2 + 0x^1 + 10x^0
    int P1[MAX] = {10, 0, 5, 0, 0}; 
    // 0x^3 + 10x^2 + 5x^1 + 2x^0
    int P2[MAX] = {2, 5, 10, 0, 0};
    int P_Sum[MAX];
    
    polyAdd(P1, P2, P_Sum, MAX);
    
    printf("Polynomial 1: ");
    printPoly(P1, MAX);
    printf("Polynomial 2: ");
    printPoly(P2, MAX);
    printf("Sum: ");
    printPoly(P_Sum, MAX);
    
    return 0;
}