#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdio.h>
#include <stdlib.h>

/**

 * Input the elements of array from keyboard

 * 

 * @param number The number of array

 * @param array The array that is needed to add

 */
void input_array(int number, int array[]);
/**

 * Print all the elements of array

 * 

 * @param number The number of array

 * @param array The array that is added to show

 */
void show_array(int number, int array[]);
/**

 * Swap odd value and even value

 * 

 * @param a The first element need to be swapped

 * @param b The second element need to be swapped

 */
void swap(int *a, int *b);
/**

 * Calculate the average value of all elements

 * 

 * @param number The number of array

 * @param array The array that is added to calculate

 */
void calculate_average_value(int number, int array[]);
/**

 * Move even values to the right and odd values to the left

 * 

 * @param number The number of array

 * @param array The array that is added to calculate

 */
void move_even_right_and_odd_left(int number, int array[]);

#endif
