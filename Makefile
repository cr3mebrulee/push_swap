# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 14:14:04 by taretiuk          #+#    #+#              #
#    Updated: 2024/05/18 09:54:16 by taretiuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
LIBFT	= ./libft/libft.a

SRCS 	= src/main.c\
					src/create_stack_a.c\
					src/if_sorted.c\
					src/choose_sort.c\
					src/list_size.c\
					src/sort_3.c\
					src/operations_stack_a.c\
					src/operations_stack_b.c\
					src/push_stack_b.c\
					src/push_stack_a.c\
					src/calculate_cost.c\
					src/find_index.c\
					src/find_min_max.c\
					src/find_target_index.c\
					src/push_cheapest_node.c\
					src/final_rotation.c\
					src/free_memory_functions.c
					
OBJS 	= ${SRCS:.c=.o}

HEADER	= -I include

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror -g

all: 	libft	${NAME}

%.o: %.c
	@echo "\033[33m----Compiling ${@}----"
	@$(CC) ${CFLAGS} ${HEADER} -c $< -o $@

${NAME}:	${OBJS} ${LIBFT}
					@echo "\033[33m----Compiling push_swap binary----"
					@$(CC) ${OBJS} -Llibft -lft -o ${NAME}

libft:
	@make -C ./libft

clean:
					@make clean -C ./libft
					@rm -f ${OBJS}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re    libft