/*get the integer as index of a node*/
/*return the found index*/
/*compare each element with searched element*/
/*to assign first node to the pointer*/
/*to declare integer to iterate over elements*/
/*to pass the value of a node which we want to find as integer*/
/*to pass the linked list for read-only*/

#include "../include/push_swap.h"

int find_index(t_stack *stack, int  number, int *index)
{
    t_stack *ptr;
    int i;

    i = 0;
    ptr = stack;
    while (ptr != NULL)
    {
        if (ptr->data == number)
        {
            *index = i;
            return (0);
        }
        ptr = ptr->next;
        i++;
    }
    return (-1);
}