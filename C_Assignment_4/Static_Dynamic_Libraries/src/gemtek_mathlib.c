#include <stdio.h>
#include "gemtek_mathlib.h"
int calculate_square(int dimension)
{
    return dimension*dimension;
}
int calculate_cube(int dimension)
{
    return dimension*dimension*dimension;
}
int check_integer()
{  
    float n;
    printf("Enter a number:");
    while (scanf("%f", &n) != 1 || n < 0 || n - (int)n != 0)
    {
        printf("Invalid integer. Enter again.\nEnter a number:");
        while (getchar() != '\n');
    }
    getchar();
    return (int)n;
}
int calculate_fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return calculate_fibonacci(n-2) + calculate_fibonacci(n-1);
    }
}
int check_fibonacci(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (calculate_fibonacci(i) == n)
        {
            return 1;
        }
    }
    return 0;
}
