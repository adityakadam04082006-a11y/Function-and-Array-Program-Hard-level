#include <stdio.h>
#include <string.h>

// Function to find max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find length of LCS
int lcs(char* X, char* Y, int m, int n) {
    // dp[i][j] stores length of LCS of X[0..i-1] and Y[0..j-1]
    int dp[m + 1][n + 1];
    int i, j;
    
    // Build the dp table from bottom up
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0; // Base case
            }
            else if (X[i - 1] == Y[j - 1]) {
                // Characters match
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                // Characters don't match
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    char str1[] = "AGGTAB";
    char str2[] = "GXTXAYB";
    
    int m = strlen(str1);
    int n = strlen(str2);
    
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("Length of LCS is %d\n", lcs(str1, str2, m, n)); // "GTAB" -> 4
    
    return 0;
}