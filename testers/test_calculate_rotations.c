#include <assert.h>

void    check_expected_cost(t_stack *stack, int number, int cost)
{
    int size;
    int middle;
    int index;
    int expected_cost;

    list_size(stack, &size);
    middle = size / 2;
    find_index(stack, number, &index);
    expected_cost = (index <= middle) ? index : size - index;
    assert(cost == expected_cost);
    if(cost == expected_cost)
    {
        printf("You got expected cost\n");
    }
    else
        ("You got not expected cost\n");
}

void	test_calculate(void)
{
    /*full stuck with numbers*/
	t_stack	*stack;
    t_stack *tmp;
    
    int arr[] = {1, 20, -5, 6, 3, 56, 101, 4};
    int size;
    int cost;
    int index;
    
    size = 7;
	stack = NULL;
    while (size >= 0)
    {
        push(&stack, arr[size]);
        size--;
    }
    tmp = stack;
    while (tmp != NULL)
    {
        find_index(stack, tmp->data, &index);
        calculate_rotations(stack, index, &cost);
        check_expected_cost(stack, tmp->data, cost);
        tmp = tmp->next;
    }
}

int main()
{
   test_calculate();
}