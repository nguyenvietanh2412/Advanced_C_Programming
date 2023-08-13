#include "matrix.h"

int main() {
    // Initialize variables to store the dimensions of matrices A and B
    int rowA, rowB, colA, colB;

    // Prompt the user to input dimensions for matrix A and matrix B
    printf("Type matrix A's row and column: ");
    scanf("%d %d", &rowA, &colA);
    printf("Type matrix B's row and column: ");
    scanf("%d %d", &rowB, &colB);

    // Allocate memory for matrices A, B, and C
    int **matrixA = (int **)malloc(rowA * sizeof(int *));
    int **matrixB = (int **)malloc(rowB * sizeof(int *));
    int **matrixC = (int **)malloc(rowA * sizeof(int *));
    for (int i = 0; i < rowA; i++) {
        matrixC[i] = (int *)malloc(colB * sizeof(int));
        matrixA[i] = (int *)malloc(colA * sizeof(int));
    }

    for (int i = 0; i < rowB; i++) {
        matrixB[i] = (int *)malloc(colB * sizeof(int));
    }

    // Prompt the user to input elements for matrices A and B
    printf("Type A's elements:\n");
    input_matrix(rowA, colA, matrixA);
    printf("Type B's elements:\n");
    input_matrix(rowB, colB, matrixB);

    // Display matrices A and B
    printf("Matrix A:\n");
    show_matrix(rowA, colA, matrixA);
    printf("Matrix B:\n");
    show_matrix(rowB, colB, matrixB);

    // Check if matrices can be added and perform addition if possible
    if (check_condition_for_adding(rowA, colA, rowB, colB)) {
        printf("Sum of two matrices:\n");
        add_two_matrix(rowA, colA, matrixA, matrixB);
    } else {
        printf("Cannot add these two matrices!\n");
    }

    // Check if matrices can be multiplied and perform multiplication if possible
    if (check_condition_for_multiplying(colA, rowB)) {
        printf("Multiply two matrices: C = A x B:\n");
        multiply_matrix(rowA, colB, colA, matrixA, matrixB, matrixC);
    } else {
        printf("Cannot multiply these matrices!\n");
    }

    // Free allocated memory for matrices
    free_matrix(rowA, matrixA);
    free_matrix(rowB, matrixB);
    free_matrix(rowA, matrixC);

    return 0;
}
