#include "sort.h"

/**
 * intSwap - Function that swaps two integers in an array.
 * @x: first integer.
 * @y: second integer.
 */

 void intSwap(int *x, int *y)
{
	int z;

	z = *x;
	*x = *y;
	*y = z;
}

/**
 * selection_sort - function that sorts an array (ascending order).
 * @array: array.
 * @size: size of array.
 * Description: prints array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	int *low;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		low = array + a;
		for (b = a + 1; b < size; b++)
			low = (array[b] < *low) ? (array + b) : low;

		if ((array + a) != low)
		{
			intSwap(array + a, low);
			print_array(array, size);
		}
	}
}
