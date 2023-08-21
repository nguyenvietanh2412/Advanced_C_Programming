#include "array.h"

int main()
{
    // Initialize the number of elements of array
    int number;
    number = check_number_element();
    // Initialize array with input number
    int array[number];

    // Prompt the user to input elements of array
    input_array(number, array);

    // Display array before sorting
    printf("Array before sorting:\n");
    show_array(number, array);

    // Calculate and display the average value and the number of value less than it
    calculate_average_value(number, array);

    // Move even values to the right and odd values to the left
    move_even_right_and_odd_left(number, array);

    // Display array after sorting
    printf("Array after sorting:\n");
    show_array(number, array);
    return 0;
}