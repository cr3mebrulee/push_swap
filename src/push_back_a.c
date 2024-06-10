#include "../include/push_swap.h"

// void print_target_indexes(t_stack *stack)
// {
//     t_stack *current = stack;
//     while (current != NULL) 
//     {
//         printf("%i %d\n", current->data, current->target_index);
//         current = current->next;
//     }
// }

void find_target_node(t_stack *stack_a, int target_index, t_stack **target_node)
{
    int i;
    i = 0;
    *target_node = stack_a;
    while(i <= target_index && *target_node != NULL)
    {
        if (i == target_index)
        {
            return ;
        }
        *target_node = (*target_node)->next;
        i++;
    }
    *target_node = NULL;
}

/*compare the costs of each node and find cheapest*/
int find_cheapest_node(t_stack *stack, t_stack **cheapest_node)
{
    if (stack == NULL)
    {
        return (-1);
    }
    /*Assume that first node is cheapest*/
    *cheapest_node = stack;
    /*Adjust pointer to compare each next node*/
    t_stack *current = stack->next;

    while (current != NULL) 
    {
        if (current->sum_cost == 0) 
        {
            *cheapest_node = current;
            break;
        }
        if (current->sum_cost < (*cheapest_node)->sum_cost) 
        { 
            *cheapest_node = current;
        }
        current = current->next;
    } 
    return (0);
}

void    push_back_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheapest_node;
    t_stack *target_node;

    cheapest_node = NULL;
    target_node = NULL;
    while(stack_b != NULL)
    {
        if (!stack_b || !*stack_b)
        {
            return ;
        }     
        /*calculate cost of each node in b*/
        calculate_cost(*stack_a, *stack_b);
        /*compare the costs of each node and find cheapest*/  
        find_cheapest_node(*stack_b, &cheapest_node);
        /*get the pointer to target node in stack a*/
        find_target_node(*stack_a, cheapest_node->target_index, &target_node);
        /*push b node to a node, not ready*/
        push_cheapest_node(stack_b, stack_a, cheapest_node, target_node);       
    }
    return ;
}