#include "sort.h"

/**
 * heap_sort - implementation of heap sort, applies the sift down method
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
    size_t n = size
    /*Start from the no leaf nodes*/
    for (i = n / 2; i >= 1; i--)
    {
        /*Build the max heap*/
        heapify(array, n, i);
    }
    /*Start deletion from the root node only*/
    for (i = n; i >= 1; i--)
    {
        swap(array[1], array[i], array);
        /*after swapping the array is no longer a max heap so*/
        heapify(array, n, 1)/*why 1? heapify will be called only on the root node only during deletion*/
    }
}
void heapify(int *array, size_t size, int i)
{
    int largest = i;
    /*child nodes*/
    int left = (i * 2);
    int right = (i * 2) + 1;

    while (left < size && array[left] > array[largest])
    {
        largest = left;
    }
    while (right < n && array[right] > array[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(array[largest], array[i], array);
        heapify(array, size, largest);
    }

}
void swap(int a, int b, int * array)
{
    int temp;

    temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}