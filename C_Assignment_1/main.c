#include "matrix.h"



int main() {

    // Initialize variables to store the dimensions of matrices A and B

    int row_a, row_b, col_a, col_b;

    // Prompt the user to input dimensions for matrix A and matrix B
    printf("Type matrix A's row: ");
    row_a = check_valid_row_col();
    printf("Type matrix A's column: ");
    col_a = check_valid_row_col();
    printf("Type matrix B's row: ");
    row_b = check_valid_row_col();
    printf("Type matrix B's column: ");
    col_b = check_valid_row_col();

    // Allocate memory for matrices A, B, and C

    float **pp_matrix_a = (float **)malloc(row_a * sizeof(float *));

    float **pp_matrix_b = (float **)malloc(row_b * sizeof(float *));

    float **pp_matrix_c = (float **)malloc(row_a * sizeof(float *));

    for (int i = 0; i < row_a; i++) {

        pp_matrix_c[i] = (float *)malloc(col_b * sizeof(float));

        pp_matrix_a[i] = (float *)malloc(col_a * sizeof(float));

    }



    for (int i = 0; i < row_b; i++) {

        pp_matrix_b[i] = (float *)malloc(col_b * sizeof(float));

    }



    // Prompt the user to input elements for matrices A and B

    printf("Type A's elements:\n");

    input_matrix(row_a, col_a, pp_matrix_a);

    printf("Type B's elements:\n");

    input_matrix(row_b, col_b, pp_matrix_b);



    // Display matrices A and B

    printf("Matrix A:\n");

    show_matrix(row_a, col_a, pp_matrix_a);

    printf("Matrix B:\n");

    show_matrix(row_b, col_b, pp_matrix_b);



    // Check if matrices can be added and perform addition if possible

    if (check_condition_for_adding(row_a, col_a, row_b, col_b)) {

        printf("Sum of two matrices:\n");

        add_two_matrix(row_a, col_a, pp_matrix_a, pp_matrix_b);

    } else {

        printf("Cannot add these two matrices!\n");

    }



    // Check if matrices can be multiplied and perform multiplication if possible

    if (check_condition_for_multiplying(col_a, row_b)) {

        printf("Multiply two matrices: C = A x B:\n");

        multiply_matrix(row_a, col_b, col_a, pp_matrix_a, pp_matrix_b, pp_matrix_c);

    } else {

        printf("Cannot multiply these matrices!\n");

    }



    // Free allocated memory for matrices

    free_matrix(row_a, pp_matrix_a);

    free_matrix(row_b, pp_matrix_b);

    free_matrix(row_a, pp_matrix_c);



    return 0;

}