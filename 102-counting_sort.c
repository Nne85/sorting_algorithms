#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sort an array of integers in ascending order
 *                using the Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array to be sorted
 */
void counting_sort(int *array, size_t size)
{
    int i;
    int max = 0;
    int *count_array, *sorted_array;

    if (!array || size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < (int) size; i++)
        if (array[i] > max)
            max = array[i];

    /* Allocate the counting array */
    count_array = malloc(sizeof(int) * (max + 1));
    if (!count_array)
        return;

    /* Initialize the counting array */
    for (i = 0; i <= max; i++)
        count_array[i] = 0;

    /* Count the occurrences of each value */
    for (i = 0; i < (int) size; i++)
        count_array[array[i]]++;

    /* Modify the counting array to get the final positions of each element */
    for (i = 1; i <= max; i++)
        count_array[i] += count_array[i - 1];

    /* Allocate the sorted array */
    sorted_array = malloc(sizeof(int) * size);
    if (!sorted_array)
    {
        free(count_array);
        return;
    }

    /* Build the sorted array */
    for (i = (int) size - 1; i >= 0; i--)
    {
        sorted_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }

    /* Copy the sorted array into the original array */
    for (i = 0; i < (int) size; i++)
        array[i] = sorted_array[i];

    /* Print the counting array */
    printf("%d", count_array[0]);
    for (i = 1; i <= max; i++)
        printf(", %d", count_array[i]);
    printf("\n");

    /* Free the memory */
    free(count_array);
    free(sorted_array);
}
