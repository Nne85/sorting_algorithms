#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using the
 *              Shell sort algorithm, using the Knuth sequence
 * @array: The array to sort
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || size < 2)
		return;

	/* Calculate the largest gap using the Knuth sequence */
	for (gap = 1; gap < size / 3;)
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		/* Sort elements separated by the current gap using insertion sort */
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}

		print_array(array, size);
	}
}
