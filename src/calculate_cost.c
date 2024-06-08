#include "../include/push_swap.h"

/*if node is above the middle of the stack we rotate stack up, 
if under middle we rotae down.*/
void calculate_rotations(t_stack *stack, t_stack *node)
{
    int size;
    int index;
    t_stack *ptr;
    
    size = 0;
    ptr = stack;
    while (ptr != NULL) 
    {
        size++;
        ptr = ptr->next;
    }
    index = node->index;
    node->cost = (index <= size / 2) ? index : size - index;
    node->direction = (index <= size / 2) ? 0 : 1;
}

void    calculate_cost(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *node_b;
    t_stack *node_a;

    if (stack_b == NULL)
    {
        fprintf(stderr, "Error: stack_b is NULL.\n");
        return ;
    }
    node_b = stack_b;
    node_a = stack_a;
    while (node_b != NULL)
    {
        /*find index of current b node*/
        find_index(stack_b, node_b->data);
        /*calculate rotations of current b node*/
        calculate_rotations(stack_b, node_b);
        /*find index of target node and adjust pointer to target node*/
        find_target_index(stack_a, node_b->data, &node_a);
        /*assign index of target node to b node field*/
        node_b->target_index = node_a->index;
        /*calculate rotations of target node*/
        calculate_rotations(stack_a, node_a);
        /*to get a result cost of current b node*/
        node_b->sum_cost = node_b->cost + node_a->cost;
        node_b = node_b->next;
        node_a = stack_a;
    }
    return ;
}
