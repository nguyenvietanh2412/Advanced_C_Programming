#ifndef MATRIX_H_
#define MATRIX_H_
#include <stdio.h>
#include <stdlib.h>
/**
 * Fill a matrix with user-input values.
 * 
 * @param row The number of rows in the matrix.
 * @param col The number of columns in the matrix.
 * @param matrix The matrix to be filled.
 */
void input_matrix(int row, int col, int **matrix);

/**
 * Display the contents of a matrix.
 * 
 * @param row The number of rows in the matrix.
 * @param col The number of columns in the matrix.
 * @param matrix The matrix to be displayed.
 */
void show_matrix(int row, int col, int **matrix);

/**
 * Add two matrices and display the result.
 * 
 * @param row The number of rows in the matrices.
 * @param col The number of columns in the matrices.
 * @param matrixA The first matrix to be added.
 * @param matrixB The second matrix to be added.
 */
void add_two_matrix(int row, int col, int **matrixA, int **matrixB);

/**
 * Multiply two matrices and display the result.
 * 
 * @param row The number of rows in the first matrix.
 * @param col The number of columns in the second matrix.
 * @param row_col The number of columns in the first matrix (equal to rows in the second matrix).
 * @param matrixA The first matrix to be multiplied.
 * @param matrixB The second matrix to be multiplied.
 * @param matrixC The resulting matrix.
 */
void multiply_matrix(int row, int col, int row_col, int **matrixA, int **matrixB, int **matrixC);

/**
 * Check if two matrices can be added.
 * 
 * @param rowA The number of rows in the first matrix.
 * @param colA The number of columns in the first matrix.
 * @param rowB The number of rows in the second matrix.
 * @param colB The number of columns in the second matrix.
 * @param row_col The same number for the rows in the first matrix and the columns in the second matrix.
 * @return 1 if addition is possible, 0 otherwise.
 */
int check_condition_for_adding(int rowA, int colA, int rowB, int colB);

/**
 * Check if two matrices can be multiplied.
 * 
 * @param colA The number of columns in the first matrix.
 * @param rowB The number of rows in the second matrix.
 * @return 1 if multiplication is possible, 0 otherwise.
 */
int check_condition_for_multiplying(int colA, int rowB);

/**
 * Free memory allocated for a matrix.
 * 
 * @param row The number of rows in the matrix.
 * @param matrix The matrix to be freed.
 */
void free_matrix(int row, int **matrix);

#endif // MATRIX_H_
