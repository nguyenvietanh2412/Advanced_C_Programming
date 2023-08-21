#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#define MIN_ELEMENT 0
#define MAX_ELEMENT 50
/* FUNCTION=================================================================

 *  Function Name: check_number_element

 *  Description: Check valid number of elements of array

 ==========================================================================*/
int check_number_element()
{
    float number;
    printf("Enter number of elements:");
    while (scanf("%f", &number) != 1 || number < MIN_ELEMENT || number > MAX_ELEMENT || number - (int)number != 0)
    {
        printf("Invalid input. Enter again!\nEnter number of elements:");
        while (getchar() != '\n');
    }
    return (int)number;
}
/* FUNCTION=================================================================

 *  Function Name: check_element

 *  Description: Check valid elements of array

 ==========================================================================*/
static int check_element(int i)
{
    float element;
    printf("Enter element [%d]: ", i);
    while (scanf("%f", &element) != 1 || element - (int)element != 0)
    {
        printf("Invalid input. Enter again!\nEnter element [%d]:", i);
        while (getchar() != '\n');
    }
    return (int)element;
}
/* FUNCTION=================================================================

 *  Function Name: input_array

 *  Description: Input the elements of the array

 ==========================================================================*/
void input_array(int number, int array[])
{
    int i;
    for (i = 0; i < number; i++)
    {
        array[i] = check_element(i);
    }
}
/* FUNCTION=================================================================

 *  Function Name: swap

 *  Description: swap odd value and even value

 ==========================================================================*/
static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}
/* FUNCTION=================================================================

 *  Function Name: show_array

 *  Description: Show all the elements of the array

 ==========================================================================*/
void show_array(int number, int array[])
{
    int i;
    for(i = 0; i < number; i++)
    {
        printf("%d  ", array[i]);
    }
}

/* FUNCTION=================================================================

 *  Function Name: calculate_average_values

 *  Description: Calculate the average value of all elements of array

 ==========================================================================*/
void calculate_average_value(int number, int array[])
{
    int i, count, sum;
    float average;
    count = 0;
    average = 0.0;
    sum = 0;
    for (i = 0; i < number; i++)
    {
        sum += array[i];
    }
    average = (float) sum/number;
    for (i = 0; i < number; i++)
    {
        if (array[i] < average)
        {
            count++;
        }
    }
    printf("\nAverage value: %.3f\n", average);
    printf("Number of elements that is less than the average value: %d\n", count);
}

/* FUNCTION=================================================================

 *  Function Name: ove_even_right_and_odd_left

 *  Description: move even values to the right and odd values to the left

 ==========================================================================*/
void move_even_right_and_odd_left(int number, int array[])
{
    int left = 0;
    int right = number - 1;
    while(left < right)
    {
        while ((array[left] % 2 == 1) && (left < right))
        {
            left++;
        }
        while (( array[right] % 2 == 0) && ( left < right ))
        {
            right--;
        }
        if (left < right)
        {
            swap(&array[left], &array[right]);
        }
    }
}
