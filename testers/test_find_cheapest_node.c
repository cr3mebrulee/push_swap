#include <assert.h>

void    test_100(void)
{
    t_stack	*stack;
    t_stack *cheapest_node;
    t_stack *tmp;
    int i;
    stack = NULL;
    cheapest_node = NULL;
    for (int i = 0; i < 100; i++)
    {
       push(&stack, i);
    }
    printf("Stack is: \n");
    print_stack(stack);
    i = 5;
    tmp = stack;
    while (tmp != NULL)
    {
        tmp->cost = i;
        tmp = tmp->next;
        i++;
    }
    find_cheapest_node(stack, &cheapest_node);
    assert(cheapest_node->cost == 5);
    if (cheapest_node->cost == 5)
    {
        printf("The ceapest node has cost: %i\n", cheapest_node->cost);
    }
    else
        printf("Cheapest cost wrong\n");
}

int main()
{
    test_100();
}