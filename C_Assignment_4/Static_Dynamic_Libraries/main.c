#include "gemtek_mathlib.h"

int main()
{
    int fibo, dimension = 3;
    printf("Square: %d\n", calculate_square(dimension));
    printf("Cube: %d\n", calculate_cube(dimension));
    fibo = check_integer();
    if (check_fibonacci(fibo) == 1)
    {
        printf("%d is a fibonacci number.", fibo);
    }
    else
    {
        printf("%d is not a fibonacci number.", fibo);
    }
    return 0;
}