#include "../include/push_swap.h"

void find_target_node(t_stack *stack_a, int target_index, t_stack **target_node)
{
    *target_node = stack_a;
    while (*target_node != NULL)
    {
        if ((*target_node)->index == target_index)
        {
            return ;
        }
        *target_node = (*target_node)->next;
    }
    // If not found, set target_node to NULL
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
        if (current->cost == 0) 
        {
            *cheapest_node = current;
            break;
        }
        if (current->cost < (*cheapest_node)->cost) 
        { 
            *cheapest_node = current;
        }
        current = current->next;
    } 
    return (0);
}

void    push_back_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_b;
    t_stack *cheapest_node;
    t_stack *target_node;

    tmp_b = *stack_b;
    cheapest_node = NULL;
    target_node = NULL;
    while(tmp_b != NULL)
    {
        /*calculate cost of each node in b*/
        calculate_cost(*stack_a, *stack_b);
        /*compare the costs of each node and find cheapest*/  
        find_cheapest_node(*stack_b, &cheapest_node);
        /*get the pointer to target node in stack a*/
        find_target_node(*stack_a, cheapest_node->target_index, &target_node);
        /*push b node to a node, not ready*/
        //push_a(&cheapest_node, &target_node);
        tmp_b = tmp_b->next;
    }
    printf("Cheapest's node data is: %i\n", cheapest_node->data);
    printf("Target's node index is: %i\n", cheapest_node->target_index);
}