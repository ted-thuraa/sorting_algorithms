#include "sort.h"

/**
* insertion_sort_list - implementation of insertion sort
* @list: doubly linked list to be sorted
*
* Return: void
*/

void insertion_sort_list(listint_t **list)
{
    listint_t *head;
    listint_t *current;
    listint_t *holder;

    if (list == NULL)
    {
        return;
    }
    if ((*list)->next == NULL)
    {
        return;
    }

    head = *list;
    while (head != NULL)
    {
        if (head->prev != NULL)
        {
            holder = head;
            head = head->next;
            while (holder->prev != NULL)
            {
                first = (holder->prev)->n;
                second = holder->n;
                if (first <= second)
                {
                    break;
                }
                swap_nodes(holder->prev, holder);
                if (holder->prev == NULL)
                {
                    *list = holder;
                }
                print_list(*list);

            }
        }
        else:
        {
            head = head->next;
        }
    }
}

/**
* swap_nodes - swap adjacent nodes of a doubly linked list
* @first: first node
* @second: second node
*
* Return: void
*/
void swap_nodes(listint_t *first, listint_t *second)
{
    if (first->prev != NULL)
    {
        (first->prev)->next = second;
    }
    if (second->next != NULL)
    {
        (second->next)->prev = first;
    }
    second->prev = first->prev;
    first->prev = second;
    first->next = second->next;
    second->next = first;
}
