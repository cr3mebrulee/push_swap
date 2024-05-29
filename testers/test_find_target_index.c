#include <assert.h>

void    test_above_and_under_middle(void)
{
    t_stack	*stack;
    t_stack *tmp;

    int size;
    int cost;
    int index;
    int arr[] = {0, 4, 9};

    size = 2;
    stack = NULL;
    index = 0;
    while (size >= 0)
    {
        push(&stack, arr[size]);
        size--;
    }
    print_stack(stack);
    find_target_index(stack, 6, &index);
    assert(index == 2);
    find_target_index(stack, -1, &index);
    assert(index == 0);
    find_target_index(stack, 1, &index);
    assert(index == 1);
    find_target_index(stack, 7, &index);
    assert(index == 2);
    find_target_index(stack, 2, &index);
    assert(index == 1);
    find_target_index(stack, 5, &index);
    assert(index == 2);
}

int main()
{
    test_above_and_under_middle();
}