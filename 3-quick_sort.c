#include "sort.h"

void intSwap(int *x, int *y);
int lomutoPar(int *array, size_t size, int left, int right);
void lomutoSort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomutoPar - Orders a portion of an array of integers using
 * the Lomuto partition scheme with the last element as the pivot.
 * @arr: The array of integers.
 * @size: The size of the array.
 * @l: starting index to be ordered.
 * @r: ending index to be ordered.
 * Return: The final partition index.
 */

int lomutoPar(int *arr, size_t size, int l, int r)
{
	int *piv, up, down;

	piv = arr + r;
	for (up = down = l; down < r; down++)
	{
		if (arr[down] < *piv)
		{
			if (up < down)
			{
				intSwap(arr + down, arr + up);
				print_array(arr, size);
			}
			up++;
		}
	}

	if (arr[up] > *piv)
	{
		intSwap(arr + up, piv);
		print_array(arr, size);
	}

	return (up);
}

/**
 * lomutoSort - Implements the quicksort algorithm using recursion.
 * @arr: An array of integers to be sorted.
 * @size: The size of the array.
 * @l: The starting index of the array partition to be ordered.
 * @r: The ending index of the array partition to be ordered.
 *
 * Description: Applies the Lomuto partition scheme.
 */
void lomutoSort(int *arr, size_t size, int l, int r)
{
	int par;

	if (r - l > 0)
	{
		par = lomutoPar(arr, size, l, r);
		lomutoSort(arr, size, l, par - 1);
		lomutoSort(arr, size, par + 1, r);
	}
}

/**
 * quick_sort - Arrange an array of integers in ascending order
 * using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Applies the Lomuto partition scheme and prints
 * the array after each exchange of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomutoSort(array, size, 0, size - 1);
}
