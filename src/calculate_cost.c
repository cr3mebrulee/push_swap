#include "../include/push_swap.h"

/*if node is above the middle of the stack we rotate stack up, 
if under middle we rotae down.*/
void calculate_rotations(t_stack *stack, int index, int *cost)
{
    int middle;
    int size;
    
    list_size(stack, &size);
    middle = size / 2;
    if (index == -1)
    {
        // Error handle - do we need?
        *cost = -1;
        return;
    }
    if (index <= middle)
    {
        *cost = index;
        return ;
    }
    else
    {
        *cost = size - index;
        return ;
    }
}

void    calculate_cost(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmp_b;
    int index_b;
    int index_a;
    int cost_a;
    int cost_b;
    /*variable only for testing, should be deleted*/
    int i;

    i = 1;
    tmp_b = stack_b;
    while (tmp_b != NULL)
    {
        /*find index of current b node*/
        find_index(stack_b, tmp_b->data, &index_b);
        /*calculate rotations of current b node*/
        calculate_rotations(stack_b, index_b, &cost_b);
        /*find index of target node*/
        find_target_index(stack_a, tmp_b->data, &index_a);
        /*assign index of target node to b node field*/
        tmp_b->target_index = index_a;
        /*calculate rotations of target node*/
        calculate_rotations(stack_a, index_a, &cost_a);
        /*to get a result cost of current b node*/
        tmp_b->cost = cost_b + cost_a;
        i++;
        tmp_b = tmp_b->next;
    }
    return ;
}
