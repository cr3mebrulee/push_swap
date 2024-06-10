#include "../include/push_swap.h"

t_stack    *rotation_settings(t_stack *stack)
{
    int min;
    int i;

    find_min(stack, &min);
    i = 0;
    while(stack != NULL)
    {
        if (stack->data == min)
        {
            stack->index = i;
            printf("Stack minimum is %i, minimum index is %i\n", stack->data, stack->index);
            break;
        }
        i++;
        stack = stack->next;
    }
    return (stack);
}

void    final_rotation(t_stack **stack)
{
    int i;
    int size;
    int middle;
    t_stack *minimum;
    
    i = 0;
    minimum = rotation_settings(*stack);
    list_size(*stack, &size);
    middle = size / 2;
    //printf("Stack head is: %i, middle is");
    if (minimum->index <= middle)
    {
        i = minimum->index;
        while (i > 0)
        {
            ra(stack);
            i--;
        }
        write(1, "not_sorted: ra\n", 15);
    }
    else if (minimum->index > middle)
    {
        i = size - minimum->index;
        while (i > 0)
        {
            rra(stack);
            i--;
        }
    }
    if (!if_sorted(*stack))
    {
        write(1, "not sorted anyway!\n", sizeof("not sorted anyway!\n"));
        print_stack(*stack);
    }
    return ;
}