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

typedef enum 
{
  eFORWARD, 
  eBACKWARD, 
} t_direction;

typedef struct node {
	int	data;
	struct node	*next;
	int	target_index;
	int index;
	int	cost;
	int sum_cost;
	t_direction  direction;
}	t_stack;


void	print_stack(t_stack *stack);
int		empty_stack_error(t_stack **stack_a, t_stack **stack_b);
bool	find_min(t_stack *stack, int *num);
void    final_rotation(t_stack **stack);
bool	push(t_stack **stack, int value);
bool	pop(t_stack **stack, int *value);
void    push_cheapest_node(t_stack **stack_b, t_stack **stack_a, t_stack *node_b, t_stack *node_a);
bool	calculate_cost(t_stack *stack_a, t_stack *stack_b);
bool    find_max(t_stack *stack, int *num);
bool	find_min(t_stack *stack, int *num);
bool	find_target_index(t_stack *stack, int number, t_stack **target);
int		find_index(t_stack *stack, int  number);
bool    push_stack_a(t_stack **stack_a, t_stack **stack_b);
int		push_stack_b(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack);
void	rrb(t_stack **stack);
void	ra(t_stack **stack);
void	rra(t_stack **stack);
void	sa(t_stack **stack);
void	sort_3(t_stack **stack_a);
int		list_size(t_stack *stack, int *out_size);
int		choose_sort(t_stack **stack_a, t_stack **stack_b);
bool	if_sorted(t_stack *stack);
int		create_stack_a(t_stack **stack, char **argv);
int		parse_second_argument(char *str, t_stack **stack);
int		error_create_stack(char **split_argv, t_stack **stack);
int		error_split(char **array);
void	free_2d_array(char **array);
void	free_stack(t_stack **stack);
int		check_number_arguments(int argc, char **array);

#endif
