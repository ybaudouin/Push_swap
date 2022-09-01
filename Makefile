# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 12:20:41 by ybaudoui          #+#    #+#              #
#    Updated: 2022/08/31 16:22:40 by ybaudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= main.c ft_create.c ft_check.c struct_init.c free_stack.c error_handling.c ft_parsing.c utils.c \
		  utils2.c move_stack_a.c move_stack_b.c move_stack_ab.c sort_algo.c ft_radix.c utils_stack_move.c

OBJS	= $(SRCS:.c=.o)

LIB_FLAGS = -Llibft

CC		= gcc

.c.o:
		$(CC) -Wall -Wextra -Werror -Ilibft -Llibft -lft -g -c $< -o $@

$(NAME):	$(OBJS)
			make -sC libft
			$(CC) $(LIB_FLAGS) $(OBJS) -o $(NAME) -g3 -Llibft -lft

all :	$(NAME)

clean : 
		rm -f $(OBJS)
		make -sC libft clean
	
fclean : clean
		rm -f $(NAME)
		make -sC libft fclean
	
re : fclean all 

