#include <assert.h>

void test_find_index(void)
{
    t_stack *stack;
    int	    index;
    int     result;
    stack = NULL;
    index = 0;
    push(&stack, 15);
    push(&stack, 18);
    push(&stack, 20);
    find_index(stack, 15, &index);
    assert(index == 2);
    printf("Index of 15: %d\n", index);
    find_index(stack, 18, &index);
    assert(index == 1);
    printf("Index of 18: %d\n", index);
    find_index(stack, 20, &index);
    printf("Index of 20: %d\n", index);
    assert(index == 0);
    result = find_index(stack, 23, &index);
    assert(result == -1);
    if (result = -1)
    {
        printf("Element has not found as expected\n");
    }
    else
    {
        ("Error\n");
    }
    print_stack(stack);
}

int	main()
{
    test_find_index();
}
