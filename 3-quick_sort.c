#include "sort.h"
#include <stdio.h>

/**
 * quick_sort - Sorts an array of integers using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}

/**
 * quick_sort_recursive - Recursively sorts array of integers using the Quick
 * sort algorithm and the Lomuto partition scheme
 * @array: The array to be sorted
 * @size: The size of the array
 * @low: The index of the first element of the partition to be sorted
 * @high: The index of the last element of the partition to be sorted
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, size, low, high);
		quick_sort_recursive(array, size, low, pivot - 1);
		quick_sort_recursive(array, size, pivot + 1, high);
	}
}

/**
 * partition - Partitions array of integers using the Lomuto partition scheme
 * @array: The array to be sorted
 * @size: The size of the array
 * @low: The index of the first element of the partition to be sorted
 * @high: The index of the last element of the partition to be sorted
 *
 * Return: The final position of the pivot element
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high], i = low - 1, j;

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	return (i);
}

/**
 * swap - Swaps two integers in an array
 * @a: The first integer
 * @b: The second integer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
