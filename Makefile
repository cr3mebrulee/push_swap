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
SRCDIR  = src
OBJDIR  = build
INCDIR  = include

SRCS    = $(SRCDIR)/main.c\
          $(SRCDIR)/create_stack_a.c\
          $(SRCDIR)/if_sorted.c\
          $(SRCDIR)/choose_sort.c\
          $(SRCDIR)/list_size.c\
          $(SRCDIR)/sort_3.c\
          $(SRCDIR)/operations_stack_a.c\
          $(SRCDIR)/operations_stack_b.c\
          $(SRCDIR)/push_stack_b.c\
          $(SRCDIR)/push_back_a.c\
          $(SRCDIR)/calculate_cost.c\
          $(SRCDIR)/find_index.c\
          $(SRCDIR)/find_target_index.c\
          $(SRCDIR)/push_cheapest_node.c\
          $(SRCDIR)/final_rotation.c

OBJS    = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

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