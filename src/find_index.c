#include "../include/push_swap.h"

int find_index(t_stack *stack, int  number)
{
    t_stack *ptr;
    int i;

    i = 0;
    ptr = stack;
    while (ptr != NULL)
    {
        if (ptr->data == number)
        {
            ptr->index = i;
            return (0);
        }
        ptr = ptr->next;
        i++;
    }
    return (-1);
}