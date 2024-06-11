#include "../include/push_swap.h"

void    lift_b_node(t_stack **stack_b, t_stack *node_b)
{
    int cost;
    
    cost = node_b->cost;
    if (cost == 0)
    {
        return ;
    }
    else if (node_b->direction == 0)
    {
        while (cost != 0)
        {
            rb(stack_b);
            cost--;
        }
    }
    else if (node_b->direction == 1)
    {
        while (cost != 0)
        {
            rrb(stack_b);
            cost--;
        }
    }
}


void    lift_a_node(t_stack **stack_a, t_stack *node_a)
{
    int cost;

    cost = node_a->cost;
    if (node_a->cost == 0)
    {
        return ;
    }
    else if (node_a->direction == 0)
    {
        while (cost != 0)
        {
            ra(stack_a);
            cost--;
        }
    }
    else if (node_a->direction == 1)
    {
        while (cost != 0)
        {
            rra(stack_a);
            cost--;
        }
    }
}

void    push_cheapest_node(t_stack **stack_b, t_stack **stack_a, t_stack *node_b, t_stack *node_a)
{
    int	value;

    if (stack_b == NULL || stack_a == NULL)
    {
        fprintf(stderr, "Error: Stack pointers cannot be NULL.\n");
        return;
    }
    if (*stack_b == NULL || *stack_a == NULL)
    {
        fprintf(stderr, "Error: Stacks cannot be empty.\n");
        return;
    }
    if (node_b == NULL || node_a == NULL)
    {
        fprintf(stderr, "Error: Node pointers cannot be NULL.\n");
        return;
    }
    lift_b_node(stack_b, node_b);
    lift_a_node(stack_a, node_a);
    if (pop(stack_b, &value) != 0)
    {
        push(stack_a, value);
        write(1, "pa\n", sizeof("pa\n"));
    }
}