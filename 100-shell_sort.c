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
 * shell_sort - Arrange an array of integers in ascending order
 * with the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Applies the Knuth interval sequence for sorting.
 */

void shell_sort(int *array, size_t size)
{
	size_t GAP, x, y;

	if (array == NULL || size < 2)
		return;

	for (GAP = 1; GAP < (size / 3);)
		GAP = GAP * 3 + 1;

	for (; GAP >= 1; GAP /= 3)
	{
		for (x = GAP; x < size; x++)
		{
			y = x;
			while (y >= GAP && array[y - GAP] > array[y])
			{
				intSwap(array + y, array + (y - GAP));
				y -= GAP;
			}
		}
		print_array(array, size);
	}
}
