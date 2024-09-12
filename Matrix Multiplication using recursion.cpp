#include <stdio.h>

#define N 3 // Assuming both matrices are square with size N x N

// Function to multiply two matrices recursively
void multiply(int matA[N][N], int matB[N][N], int result[N][N], int rowA, int colA, int rowB, int colB, int i, int j, int k) {
    // Base case: If all elements of current row and column have been multiplied
    if (i >= rowA || j >= colB || k >= colA)
        return;

    // Multiply the current elements and add to result
    result[i][j] += matA[i][k] * matB[k][j];

    // Move to the next element in the current row or column or matrix
    if (k + 1 < colA)
        multiply(matA, matB, result, rowA, colA, rowB, colB, i, j, k + 1);
    else if (j + 1 < colB)
        multiply(matA, matB, result, rowA, colA, rowB, colB, i, j + 1, 0);
    else if (i + 1 < rowA)
        multiply(matA, matB, result, rowA, colA, rowB, colB, i + 1, 0, 0);
}

// Function to print a matrix
void printMatrix(int mat[N][N], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matA[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matB[N][N] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[N][N] = {0};

    printf("Matrix A:\n");
    printMatrix(matA, N, N);

    printf("Matrix B:\n");
    printMatrix(matB, N, N);

    multiply(matA, matB, result, N, N, N, N, 0, 0, 0);

    printf("Resultant Matrix:\n");
    printMatrix(result, N, N);

    return 0;
}

