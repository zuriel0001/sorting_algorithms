#include <stdlib.h>
#include <stdio.h>

/**
* print_array - Function that Prints an array of integers
*
* @array: Array to be printed
* @size: the Number of elements in @array
*/
void print_array(const int *array, size_t size)
{
size_t i;

i = 0;
while (array && i < size)
{
if (i > 0)
printf(", ");
printf("%d", array[i]);
++i;
}
printf("\n");
}
