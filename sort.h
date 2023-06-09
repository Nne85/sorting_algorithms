#ifndef _SORT_H
#define _SORT_H
#include <stddef.h>


/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1



/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* print functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* prototypes*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);

/* Cocktail swap prototype */
void swap_nodes(listint_t *node_1, listint_t *node_2, listint_t **list);

void merge(int *array, size_t left, size_t mid, size_t right);
void merge_sort_helper(int *array, size_t left, size_t right);

/* heap sort prototype */
void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);

/* Radix sort */
int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/* Bitonic sort */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/*Quick Sort - Hoare Partition scheme */
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/*quick_sort prototypes */
void swap(int *a, int *b);
int partition(int *array, size_t size, int low, int high);
void quick_sort_recursive(int *array, size_t size, int low, int high);
#endif /* SORT_H */
