/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:31:31 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/26 10:05:09 by ybaudoui         ###   ########.fr       */
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
	ft_check_atoi(&stack_a, argv);
	parsing_order(&stack_a, argv);
	check_five(&stack_a, &stack_b);
	ft_pa(&stack_a, &stack_b);
	ft_pa(&stack_a, &stack_b);
	printf("\n%d\n%d\n%d\n%d\n%d\n", stack_a.top->content, stack_a.top->next->content, stack_a.top->next->next->content, stack_a.top->next->next->next->content, stack_a.top->next->next->next->next->content);
	ft_free(&stack_a);
}
