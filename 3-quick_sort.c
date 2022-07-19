#include "sort.h"

/**
* swap_rows - swap rows of an array
* @i: first row
* @j: second row
*
* Return: void
*/

void swap_rows(int *i, int *j)
{
	int temp = *i;

	*i = *j;
	*j = temp;
}

/**
* partition - separet array using pivot
* @array: array to be sorted
* @lo: int
* @hi: int
* @size: size of the array
*
* Return: int
*/

int partition(int array[], int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = (lo - 1), j;

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_rows(&array[i], &array[j]);
				print_array(array, size);
				return (i + 1);
			}
		}
	}
	swap_rows(&array[i + 1], &array[hi]);
	print_array(array, size);
	return (i + 1);
}

/**
* quickSort - main of quick sort
* @array: array to be sorted
* @lo: int
* @hi: int
* @size: size of the array
*
* Return: void
*/

void quickSort(int array[], int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quickSort(array, lo, p - 1, size);
		quickSort(array, p + 1, hi, size);
	}
}

/**
* quick_sort - implementation of quick sort
* @array: array to be sorted
* @size: size of the array
*
* Return: void
*/

void quick_sort(int *array, size_t size)
{
	quickSort(array, 0, size - 1, size);
}
