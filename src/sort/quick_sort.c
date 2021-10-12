#include "sort.h"

static void swap(int64_t* a, int64_t* b)
{
	int64_t t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
static int partition(int64_t arr[], int64_t low, int64_t high)
{
	int64_t pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	while (low <= high - 1)
	{
		// If current element is smaller than the pivot
		if (arr[low] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[low]);
		}
		low++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quick_sort(int64_t *arr, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[pi] is now
		at right place */
		int64_t pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}
