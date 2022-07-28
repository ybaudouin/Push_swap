# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 12:20:41 by ybaudoui          #+#    #+#              #
#    Updated: 2022/07/28 13:19:17 by ybaudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= main.c function_part1.c function_part2.c ft_check.c struct_init.c free_pile.c error_handling.c

OBJS	= $(SRCS:.c=.o)

LIB_FLAGS = -Llibft

CC		= gcc

.c.o:
		$(CC) -Wall -Wextra -Werror -Ilibft -Llibft -lft -g -c $< -o $@

$(NAME):	$(OBJS)
			make -sC libft
			$(CC) $(LIB_FLAGS) $(OBJS) -o $(NAME) -g -Llibft -lft

all :	$(NAME)

clean : 
		rm -f $(OBJS)
		make -sC libft clean
	
fclean : clean
		rm -f $(NAME)
		make -sC libft fclean
	
re : fclean all 

