#include "../include/push_swap.h"

void    calculate_cost(t_stack *stack_a, t_stack *stack_b);

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

/*continue till stack b is empty*/
/*pop and push cheapest*/
/*compare the costs of each node and find cheapest*/
/*calculate cost of each node in b*/
void    push_back_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheapest_node;
    t_stack *tmp_b;
    //t_stack *tmp_a;

    tmp_b = *stack_b;
    //tmp_a = *stack_a;
    while(tmp_b != NULL)
    {
        calculate_cost(*stack_a, *stack_b);    
        find_cheapest_node(*stack_b, &cheapest_node);
        printf("Cheapest's node data is: %d\n", cheapest_node->data);
       //push_a(stack_a, stack_b, cheapest_node);
       tmp_b = tmp_b->next;
    }
}