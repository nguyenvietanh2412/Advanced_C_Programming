#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

/* FUNCTION=================================================================
 *  Function Name: input_matrix
 *  Description: Input the elements of the matrix
 ==========================================================================*/
void input_matrix(int row, int col, int **matrix) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

/* FUNCTION=================================================================
 *  Function Name: show_matrix
 *  Description: Display the matrix
 ==========================================================================*/
void show_matrix(int row, int col, int **matrix) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
}

/* FUNCTION=================================================================
 *  Function Name: add_two_matrix
 *  Description: Add two matrices and display the result
 ==========================================================================*/
void add_two_matrix(int row, int col, int **matrixA, int **matrixB) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d  ", matrixA[i][j] + matrixB[i][j]);
        }
        printf("\n");
    }
}

/* FUNCTION=================================================================
 *  Function Name: multiply_matrix
 *  Description: Multiply two matrices and display the result
 ==========================================================================*/
void multiply_matrix(int row, int col, int row_col, int **matrixA, int **matrixB, int **matrixC) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrixC[i][j] = 0;
            for (int k = 0; k < row_col; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    show_matrix(row, col, matrixC);
}

/* FUNCTION=================================================================
 *  Function Name: check_condition_for_adding
 *  Description: Check condition for adding matrices
 ==========================================================================*/
int check_condition_for_adding(int rowA, int colA, int rowB, int colB) {
    return (rowA == rowB && colA == colB);
}

/* FUNCTION=================================================================
 *  Function Name: check_condition_for_multiplying
 *  Description: Check condition for multiplying matrices
 ==========================================================================*/
int check_condition_for_multiplying(int colA, int rowB) {
    return (colA == rowB);
}

/* FUNCTION=================================================================
 *  Function Name: free_matrix
 *  Description: Free allocated memory for a matrix
 ==========================================================================*/
void free_matrix(int row, int **matrix) {
    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
