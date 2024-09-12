/*
#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 5 // Maximum number of matrices

// Matrix Chain Multiplication function
int matrixChainMultiplication(int dims[], int n) {
    // Create a table to store results of subproblems
    int dp[MAX_SIZE][MAX_SIZE];

    // Initialize the table with 0
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    // For chains of length 2 to n
    for (int chainLen = 2; chainLen < n; chainLen++) {
        for (int i = 1; i < n - chainLen + 1; i++) {
            int j = i + chainLen - 1;
            dp[i][j] = INT_MAX;
	    for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    // Return the minimum cost to multiply the matrices
    return dp[1][n - 1];
}

// Driver code
int main() {
    int dims[MAX_SIZE] = {40, 20, 30, 10, 30}; // New dimensions of matrices
    int n = MAX_SIZE; // Number of matrices

    // Function call
    int minCost = matrixChainMultiplication(dims, n);
    printf("Minimum number of multiplications needed: %d\n", minCost);

    return 0;
}

*/
// C code to implement the
// matrix chain multiplication using recursion

#include <limits.h>
#include <stdio.h>

// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1 . . . n
int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;

	// Place parenthesis at different places
	// between first and last matrix,
	// recursively calculate count of multiplications
	// for each parenthesis placement
	// and return the minimum count
	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k)
				+ MatrixChainOrder(p, k + 1, j)
				+ p[i - 1] * p[k] * p[j];

		if (count < min)
			min = count;
	}

	// Return minimum count
	return min;
}

// Driver code
int main()
{
	int arr[] = { 1, 2, 3, 4, 3 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	printf("Minimum number of multiplications is %d ",
		MatrixChainOrder(arr, 1, N - 1));
	getchar();
	return 0;
}

