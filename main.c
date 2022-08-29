/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:31:31 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/29 17:40:38 by ybaudoui         ###   ########.fr       */
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
	parsing_order(&stack_a);
//	ft_sort_algo(&stack_a, &stack_b);

	ft_op_pb(&stack_a, &stack_b);
	ft_op_pb(&stack_a, &stack_b);
	ft_op_pb(&stack_a, &stack_b);
//	ft_op_rb(&stack_a);
//	ft_op_rrb(&stack_a);
	ft_op_rrr(&stack_a, &stack_b);
	t_elements *tmp2;
	t_elements *tmp3;
	if (stack_a.top)
	{
		ft_printf("Pile_a\n");
		tmp3 = stack_a.top;
		while(tmp3)
		{
			ft_printf("%d\n", tmp3->content);
			tmp3 = tmp3->next;
		}
	}
	if (stack_b.top)
	{
		ft_printf("Pile_b\n");
		tmp2 = stack_b.top;
		while(tmp2)
		{
			ft_printf("%d\n", tmp2->content);
			tmp2 = tmp2->next;
		}
	}
//*/
	ft_free(&stack_a);
	if (stack_b.top)
		ft_free(&stack_b);
}
