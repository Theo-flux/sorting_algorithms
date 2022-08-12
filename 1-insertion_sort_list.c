#include <stdio.h>
#include "sort.h"

/**
 * count_list - function to count nodes in a doubly linked list
 * @list: pointer to a doubly linked list
 * Return: the length of doubly linked list
 */
int count_list(listint_t *list)
{
    listint_t *temp;
    int i = 0;

    temp = (listint_t *)malloc(sizeof(listint_t));

    if (temp == NULL)
    {
        free(temp);
        return 0;
    }

    temp = list;

    while (temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }

    i++;
    return i;
}

/**
 * get_node_at_index - function to sort doubly linked list of integers
 * @list: pointer of pointer to a doubly linked list
 * @pos: node postion
 * Return: Print the list after each time you swap two elements
 */
listint_t *get_node_at_index(listint_t *list, int pos)
{
    listint_t *temp;
    int i = 0;

    temp = (listint_t *)malloc(sizeof(listint_t));

    if (temp == NULL)
    {
        free(temp);
    }

    temp = list;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }

    return temp;
}

/**
 * swap_nodes - function to sort doubly linked list of integers
 * @list: pointer of pointer to a doubly linked list
 * @j: node index to update
 * @i: node index to swap with
 * Return: Print the list after each time you swap two elements
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
    (*n1)->next = n2->next;
    if (n2->next != NULL)
        n2->next->prev = *n1;
    n2->prev = (*n1)->prev;
    n2->next = *n1;
    if ((*n1)->prev != NULL)
        (*n1)->prev->next = n2;
    else
        *h = n2;
    (*n1)->prev = n2;
    *n1 = n2->prev;
}

/**
 * inserion_sort_list - function to sort doubly linked list of integers
 * @list: pointer of pointer to a doubly linked list
 * Return: Print the list after each time you swap two elements
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *iter, *insert, *tmp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (iter = (*list)->next; iter != NULL; iter = tmp)
    {
        tmp = iter->next;
        insert = iter->prev;
        while (insert != NULL && iter->n < insert->n)
        {
            swap_nodes(list, &insert, iter);
            print_list((const listint_t *)*list);
        }
    }
}