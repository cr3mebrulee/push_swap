/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:36:28 by taretiuk          #+#    #+#             */
/*   Updated: 2024/05/18 17:56:18 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#	define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include "../libft/libft.h"

#define NO_ERROR 0
#define NULL_POINTER_ERROR -1

typedef struct node {
	int	data;
	struct node	*next;
	int rotations;
	int	direction;
	int index;
	int cost;
	int	target_index;
}	t_stack;


void	print_stack(t_stack *stack);
void	push(t_stack **stack, int value);
int		pop(t_stack **stack, int *value);
void    calculate_cost(t_stack *stack_a, t_stack *stack_b);
void	find_target_index(t_stack *stack, int number, int *index);
int		find_index(t_stack *stack, int  number, int *index);
void    push_back_a(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack, int value);
void	push_stack_b(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack);
void	rra(t_stack **stack);
void	sa(t_stack **stack);
void	sort_3(t_stack **stack_a);
int		list_size(t_stack *stack, int *out_size);
void	choose_sort(t_stack *stack_a, t_stack *stack_b);
bool	if_sorted(t_stack *stack);
void	create_stack_a(t_stack **stack, char **argv);


#endif
