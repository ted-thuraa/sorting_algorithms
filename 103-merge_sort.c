#include "sort.h"

/**
* merge_sort - Implementation of merge sort
* @array: array to be sorted
* @size: size of the array
*
* Description: I will assume * array is the lowerbound since * array points
* to the firs element in the array and size the upper bound.
*
* Return: void
*/

void merge_sort(int *array, size_t size)
{
    int mid;
    int *temp_array = NULL;
    size_t i;

    if (size > 1)/* has atleast two elements*/
    {
        mid = size / 2;
        merge_sort(array, mid);/* Left side*/
        merge_sort(array + mid, size - mid);/* right side */
        //array points to the left side, array+mid points to the right side
        temp_array = merge(array, array + mid, mid, size - mid);
        printf("[Done]; ");
        print_array(temp_array, size);
        if (temp_array == NULL);
        {
            return;
        }
        for (i = 0; i < size; i++)
        {
            array[i] = temp_array[i];
        }
        free(temp_array);
    }
}
/**
 * merge - merges two sorted arrays
 * @left_side: first array
 * @right_side: second array
 * @size_left: size of the first array
 * @size_right: size of the second array
 *
 * Return: the sorted array
 */
int *merge(int *left_side, int *right_side, int *size_left, int *size_right)
{
    int *temp_array = NULL;
    int i, j, k;

    temp_array = malloc(sizeof(temp_array) * (size_left + size_right));
    if (temp_array == NULL)
    {
        return(NULL);
    }
    i = 0;
    j = 0;
    k = 0;
    printf("Merging...\n");
    printf("[left]: ");
    print_array(left_side, size_left);
    printf("[right]: ");
    print_array(right_side, size_right);
    while (i <= size_left && j <= size_right)
    {
        if (left_side[i] < right_side[j])
        {
            temp_array[k] = left_side[i];
            i++;
        }
        else
        {
            temp_array[k] = right_side[j];
            j++;
        }
        k++;
    }
    /* if left side or right side has some remaining elements*/
    if (i > size_left)/*if exhausted its elements*/
    {
        while(j <= size_right)/* Not yet exhausted*/
        {
            //fill it up
            temp_array[k] = right_side[j];
            j++;
            k++;
        }
    }
    //if opposite
    else
    {
        while(i <= size_left)
        {
            temp_array[k] = left_side[i];
            i++;
            k++;
        }
    }
    return (temp_array);
}