/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:31:31 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/30 18:20:54 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (1);
	ft_init(&stack_a, &stack_b);
	parsing_str(argv);
	ft_parsing(argv, &stack_a);
	parsing_double(&stack_a);
	parsing_order(&stack_a);
	ft_find_index(&stack_a);
	ft_sort_algo(&stack_a, &stack_b);
	ft_free(&stack_a);
	if (stack_b.top)
		ft_free(&stack_b);
}
