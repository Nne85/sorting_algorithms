#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays of array[].
 * @array: Pointer to the array
 * @left: Index of the left subarray
 * @mid: Index of the middle point
 * @right: Index of the right subarray
 */
void merge(int *array, size_t left, size_t mid, size_t right)
{
    size_t i, j, k;
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;
    int *L = malloc(sizeof(int) * n1);
    int *R = malloc(sizeof(int) * n2);

    printf("Merging...\n");
    printf("[left]: ");
    for (i = 0; i < n1; i++)
    {
        L[i] = array[left + i];
        printf("%d", L[i]);
        if (i < n1 - 1)
            printf(", ");
    }
    printf("\n");

    printf("[right]: ");
    for (i = 0; i < n2; i++)
    {
        R[i] = array[mid + 1 + i];
        printf("%d", R[i]);
        if (i < n2 - 1)
            printf(", ");
    }
    printf("\n");

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }

    printf("[Done]: ");
    for (i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i < right)
            printf(", ");
    }
    printf("\n");

    free(L);
    free(R);
}

/**
 * merge_sort_helper - Sorts an array of integers in ascending order using the
 *                     Merge sort algorithm.
 * @array: Pointer to the array to be sorted
 * @left: Index of the leftmost element of the subarray
 * @right: Index of the rightmost element of the subarray
 */
void merge_sort_helper(int *array, size_t left, size_t right)
{
    if (left < right)
    {
        size_t mid = left + (right - left) / 2;
        merge_sort_helper(array, left, mid);
        merge_sort_helper(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              Merge sort algorithm.
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_sort_helper(array, 0, size - 1);
}
