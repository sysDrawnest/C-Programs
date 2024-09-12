#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum size for arrays

// Function to find the length of the Longest Common Subsequence (LCS)
int longestCommonSubsequence(char X[], char Y[], int m, int n, char lcs[]) {
    int LCS[MAX_SIZE][MAX_SIZE]; // Define the array with maximum size

    // Build LCS[m+1][n+1] bottom-up
    for (int lci = 0; lci <= m; lci++) {
        for (int j = 0; j <= n; j++) {
	    if (lci == 0 || j == 0)
		LCS[lci][j] = 0;
	    else if (X[lci - 1] == Y[j - 1])
		LCS[lci][j] = LCS[lci - 1][j - 1] + 1;
	    else
		LCS[lci][j] = LCS[lci - 1][j] > LCS[lci][j - 1] ? LCS[lci - 1][j] : LCS[lci][j - 1];
        }
    }

    // Constructing the Longest Common Subsequence
    int index = LCS[m][n]; // Length of LCS
    lcs[index] = '\0'; // Null terminate the character array

    // Start from the right-most bottom cell and fill LCS[] character array
    int i = m, j = n;
    while (i > 0 && j > 0) {
        // If current character in X[] and Y[] are same, then it is part of LCS
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1]; // Put current character in result
            i--;
            j--;
            index--;
        }
        // If not same, then find the larger of two and go in the direction of larger value
        else if (LCS[i - 1][j] > LCS[i][j - 1])
	    i--;
        else
            j--;
    }

    return LCS[m][n];
}

// Driver program to test above function
int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);
    char lcs[MAX_SIZE]; // To store the longest common subsequence

    int length = longestCommonSubsequence(X, Y, m, n, lcs);

    printf("Length of Longest Common Subsequence is %d\n", length);
    printf("Longest Common Subsequence is: %s\n", lcs);

    return 0;
}

