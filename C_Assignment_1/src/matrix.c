#include "matrix.h"

#include <stdio.h>

#include <stdlib.h>

/* FUNCTION=================================================================

 *  Function Name: check_valid_element

 *  Description: Check valid input for element

 ==========================================================================*/

float check_valid_element() {

    float element;

    while(scanf("%f", &element) != 1) {

        printf("Invalid element!\nEnter again:");

        while (getchar() != '\n');

    }

    return element;

}

/* FUNCTION=================================================================

 *  Function Name: check_valid_row_col

 *  Description: Check valid input for row and column

 ==========================================================================*/

int check_valid_row_col() {

    float num;

    while(scanf("%f", &num) != 1 || num < 1 || num - (int)num != 0) {

        printf("Invalid number!\n\nEnter again:");

        while (getchar() != '\n');

    }

    return (int)num;

}

/* FUNCTION=================================================================

 *  Function Name: input_matrix

 *  Description: Input the elements of the matrix

 ==========================================================================*/

void input_matrix(int row, int col, float **pp_matrix) {

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col; j++) {

            printf("Element [%d][%d]: ", i + 1, j + 1);

            pp_matrix[i][j] = check_valid_element();

        }

    }

}



/* FUNCTION=================================================================

 *  Function Name: show_matrix

 *  Description: Display the matrix

 ==========================================================================*/

void show_matrix(int row, int col, float **pp_matrix) {

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col; j++) {

            printf("%f  ", pp_matrix[i][j]);

        }

        printf("\n");

    }

}



/* FUNCTION=================================================================

 *  Function Name: add_two_matrix

 *  Description: Add two matrices and display the result

 ==========================================================================*/

void add_two_matrix(int row, int col, float **pp_matrix_a, float **pp_matrix_b) {

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col; j++) {

            printf("%d  ", pp_matrix_a[i][j] + pp_matrix_b[i][j]);

        }

        printf("\n");

    }

}



/* FUNCTION=================================================================

 *  Function Name: multiply_matrix

 *  Description: Multiply two matrices and display the result

 ==========================================================================*/

void multiply_matrix(int row, int col, int row_col, float **pp_matrix_a, float **pp_matrix_b, float **pp_matrix_c) {

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col; j++) {

            pp_matrix_c[i][j] = 0;

            for (int k = 0; k < row_col; k++) {

                pp_matrix_c[i][j] += pp_matrix_a[i][k] * pp_matrix_b[k][j];

            }

        }

    }

    show_matrix(row, col, pp_matrix_c);

}



/* FUNCTION=================================================================

 *  Function Name: check_condition_for_adding

 *  Description: Check condition for adding matrices

 ==========================================================================*/

int check_condition_for_adding(int row_a, int col_a, int row_B, int col_b) {

    return (row_a == row_B && col_a == col_b);

}



/* FUNCTION=================================================================

 *  Function Name: check_condition_for_multiplying

 *  Description: Check condition for multiplying matrices

 ==========================================================================*/

int check_condition_for_multiplying(int col_a, int row_B) {

    return (col_a == row_B);

}



/* FUNCTION=================================================================

 *  Function Name: free_matrix

 *  Description: Free allocated memory for a matrix

 ==========================================================================*/

void free_matrix(int row, float **pp_matrix) {

    for (int i = 0; i < row; i++) {

        free(pp_matrix[i]);

        pp_matrix[i] = NULL;

    }

    free(pp_matrix);

    pp_matrix = NULL;

}