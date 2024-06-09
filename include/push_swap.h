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
	int	target_index;
	int index;
	int	cost;
	int sum_cost;
	int	direction;
	
}	t_stack;


void	print_stack(t_stack *stack);
void	find_min(t_stack *stack, int *num);
void    final_rotation(t_stack **stack);
void    push_back_a(t_stack **stack_a, t_stack **stack_b);
bool	push(t_stack **stack, int value);
bool	pop(t_stack **stack, int *value);
void    push_cheapest_node(t_stack **stack_b, t_stack **stack_a, t_stack *node_b, t_stack *node_a);
void	calculate_cost(t_stack *stack_a, t_stack *stack_b);
void	find_target_index(t_stack *stack, int number, t_stack **target);
int		find_index(t_stack *stack, int  number);
void	push_back_a(t_stack **stack_a, t_stack **stack_b);
void	push_stack_b(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack);
void	rrb(t_stack **stack);
void	ra(t_stack **stack);
void	rra(t_stack **stack);
void	sa(t_stack **stack);
void	sort_3(t_stack **stack_a);
int		list_size(t_stack *stack, int *out_size);
void	choose_sort(t_stack *stack_a, t_stack *stack_b);
bool	if_sorted(t_stack *stack);
void	create_stack_a(t_stack **stack, char **argv);


#endif
