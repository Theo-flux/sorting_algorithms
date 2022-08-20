#include <stdio.h>
#include "sort.h"

void selection_sort(int *array, size_t size)
{
    size_t i, j;

    for (i = 0; i < size - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            array[i] = array[min];
        }
    }
}