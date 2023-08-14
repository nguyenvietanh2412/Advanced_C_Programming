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

void input_matrix(int row, int col, int **pp_matrix);



/**

 * Display the contents of a matrix.

 * 

 * @param row The number of rows in the matrix.

 * @param col The number of columns in the matrix.

 * @param pp_matrix The matrix to be displayed.

 */

void show_matrix(int row, int col, int **pp_matrix);



/**

 * Add two matrices and display the result.

 * 

 * @param row The number of rows in the matrices.

 * @param col The number of columns in the matrices.

 * @param pp_matrix_a The first matrix to be added.

 * @param pp_matrix_b The second matrix to be added.

 */

void add_two_matrix(int row, int col, int **pp_matrix_a, int **pp_matrix_b);



/**

 * Multiply two matrices and display the result.

 * 

 * @param row The number of rows in the first matrix.

 * @param col The number of columns in the second matrix.

 * @param row_col The number of columns in the first matrix (equal to rows in the second matrix).

 * @param pp_matrix_a The first matrix to be multiplied.

 * @param pp_matrix_b The second matrix to be multiplied.

 * @param pp_matrix_c The resulting matrix.

 */

void multiply_matrix(int row, int col, int row_col, int **pp_matrix_a, int **pp_matrix_b, int **pp_matrix_c);



/**

 * Check if two matrices can be added.

 * 

 * @param row_a The number of rows in the first matrix.

 * @param col_a The number of columns in the first matrix.

 * @param row_b The number of rows in the second matrix.

 * @param col_b The number of columns in the second matrix.

 * @param row_col The same number for the rows in the first matrix and the columns in the second matrix.

 * @return 1 if addition is possible, 0 otherwise.

 */

int check_condition_for_adding(int row_a, int col_a, int row_b, int col_b);



/**

 * Check if two matrices can be multiplied.

 * 

 * @param col_a The number of columns in the first matrix.

 * @param row_b The number of rows in the second matrix.

 * @return 1 if multiplication is possible, 0 otherwise.

 */

int check_condition_for_multiplying(int col_a, int row_b);



/**

 * Free memory allocated for a matrix.

 * 

 * @param row The number of rows in the matrix.

 * @param matrix The matrix to be freed.

 */

void free_matrix(int row, int **pp_matrix);



#endif // MATRIX_H_