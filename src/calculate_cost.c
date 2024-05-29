#include "../include/push_swap.h"

/*sum operations in a to op in b*/
/*calculate how much operations to bring target node to the top*/
/*find a target node in stack a*/
/*calculate how much operations to bring b to the top*/

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

void calculate_cost(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmp_b;
    int index_a;
    int index_b;
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
        /*calculate rotations to bring b to the top*/
        calculate_rotations(stack_b, index_b, &cost_b);
        /*find target node for b node in a stack*/
        find_target_node(stack_a, tmp_b->data, &index_a);
        /*calclate rotations for a target node*/
        calculate_rotations(stack_a, index_a, &cost_a);
        /*calculate cost of both nodes*/
        tmp_b->cost = cost_b + cost_a;
        printf("Sum cost of node %i b %d\n", i, tmp_b->cost);
        i++;
        /*go to the next node*/
        tmp_b = tmp_b->next;
    }
    return ;
}
