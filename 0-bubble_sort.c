#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* bubble_sort - implementation of bubble sort
* @array: array to be sorted
* @size: size of the array
*
* Return: void
*/

void bubble_sort(int *array, size_t size)
{
	size_t temp;
	size_t i, j;
	int flag;

	if (size < 2)
	{
		return;
	}
	for (i = 0; i < (size - 1); i++)
	{
		flag = 0;
		for (j = 0; j < (size - 1 - i); j++) /* no of checks reduces by i */
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				/* Any time swaping occurs is a sign the loop should go on */
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
		{
			return;
		}
	}
}
