#include <stdio.h>
#include <stdlib.h>
void InfoMatrix(int row, int col, int **matrix)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("Element [%d][%d]:",i+1,j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void ShowMatrix(int row, int col, int **matrix)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
}

void AddTwoMatrix(int row, int col, int **matrixA, int **matrixB)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d  ",matrixA[i][j]+matrixB[i][j]);
        }
        printf("\n");
    }
}

void MultiplyMatrix(int row, int col, int row_col, int **matrixA, int **matrixB, int **matrixC)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            matrixC[i][j] = 0;
            for(int k = 0; k < row_col; k++)
            {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    ShowMatrix(row, col, matrixC);
}

int main()
{
    // row and column of each matrix
    int rowA, rowB, colA, colB;
    printf("Type matrix A's row and column: ");
    scanf("%d %d", &rowA, &colA);
    printf("Type matrix B's row and column: ");
    scanf("%d %d", &rowB, &colB);

    // allocate matrices' pointers dynamically
    int **matrixA = (int **)malloc(rowA*sizeof(int *));
    int **matrixB = (int **)malloc(rowB*sizeof(int *));
    int **matrixC = (int **)malloc(rowA*sizeof(int *));
    for(int i = 0; i < rowA; i++)
    {
        matrixC[i] = (int *)malloc(colB*sizeof(int));
        matrixA[i] = (int *)malloc(colA*sizeof(int));
    }   

    for(int i = 0; i < rowB; i++)
    {
        matrixB[i] = (int *)malloc(colB*sizeof(int));
    }

    // get matrices info from keyboard
    printf("Type A's elements:\n");
    InfoMatrix(rowA, colA, matrixA);
    printf("Type B's elements:\n");   
    InfoMatrix(rowB, colB, matrixB);

    // print two matrices
    printf("Matrix A:\n");
    ShowMatrix(rowA, colA, matrixA);
    printf("Matrix B:\n");
    ShowMatrix(rowB, colB, matrixB);

    // add two matrices
    if(rowA == rowB && colA == colB)
        {
            printf("Sum of two matrices:\n");
            AddTwoMatrix(rowA, colA, matrixA, matrixB);
        }
    else printf("Cannot add these two matrices!\n");

    //multiply two matrices
    if(colA == rowB)
    {
        printf("Multiply two matrices: C = A x B:\n");
        MultiplyMatrix(rowA, colB, colA, matrixA, matrixB, matrixC);
    }
    else printf("Cannot multiply these matrices!\n");

    // free matrixA, matrixB, matrixC
    for(int i = 0; i < rowA; i++)
    {
        free(matrixA[i]);
        free(matrixC[i]);
    }
    for(int i = 0; i < rowB; i++)
    {
        free(matrixB[i]);
    }
    free(matrixA);
    free(matrixB);
    free(matrixC);
    return 0;
}
