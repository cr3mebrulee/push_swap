#include "../include/push_swap.h"

void free_stack(t_stack **stack) 
{
    t_stack *current = *stack;
    t_stack *next_node;

    while (current != NULL) 
	{
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *stack = NULL;
    return ;
}

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
    {
        free(array[i]);
        i++;
    }
	free(array);
    return ;
}

int error_split(char **array)
{
    free_2d_array(array);
    ft_printf("Error\n");
    exit (-1);
}

int error_create_stack(char **array, t_stack **stack)
{
    free_2d_array(array);
	free_stack(stack);
    ft_printf("Error\n");
	exit (-1);
}
			
    