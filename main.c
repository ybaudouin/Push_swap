/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:31:31 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/31 16:56:29 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"
#include "push_swap.h"
#include "opti_radix.h"

int	main(int argc, char **argv)
{
	t_stack			stack_a;
	t_stack			stack_b;
	t_stack_move	stack_move;

	if (argc < 2)
		return (1);
	ft_init(&stack_a, &stack_b, &stack_move);
	parsing_str(argv);
	ft_parsing(argv, &stack_a);
	parsing_double(&stack_a);
	parsing_order(&stack_a);
	ft_find_index(&stack_a);
	ft_sort_algo(&stack_a, &stack_b, &stack_move);
	ft_free(&stack_a);
	ft_remove_double(&stack_move);
	ft_print_stack_move(&stack_move);
	ft_free_stack_move(&stack_move);
}
