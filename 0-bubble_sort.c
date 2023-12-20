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
 * bubble_sort - function that sorts an array (ascending order).
 * @array: array to sort.
 * @size: size of array.
 * Description: sorts an array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t itr, length = size;
	boolean bub = false;

	if (array == NULL || size < 2)
		return;

	while (bub == false)
	{
		bub = true;
		for (itr = 0; itr < length - 1; itr++)
		{
			if (array[itr] > array[itr + 1])
			{
				intSwap(array + itr, array + itr + 1);
				print_array(array, size);
				bub = false;
			}
		}
		length--;
	}
}

