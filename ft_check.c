/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:38:09 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/31 15:18:50 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	ft_check_min(t_stack *stack_a, t_stack_move *stack_move)
{
	int			tmp_min;
	int			index;
	int			index_min;
	t_elements	*tmp;

	if (!stack_a->top)
		return ;
	index = 0;
	index_min = 0;
	tmp = stack_a->top;
	tmp_min = 2147483647;
	while (tmp != NULL)
	{
		if (tmp->content < tmp_min)
		{
			tmp_min = tmp->content;
			index_min = index;
		}
		index++;
		tmp = tmp->next;
	}
	ft_take_min(stack_a, index_min, stack_move);
}

void	check_two(t_stack *stack_a, t_stack_move *stack_move)
{
	if (stack_a->top->content > stack_a->top->next->content)
		ft_op_sa(stack_a, stack_move);
}

void	check_three(t_stack *stack_a, t_stack_move *stack_move)
{
	if ((stack_a->top->content > stack_a->top->next->content)
		&& (stack_a->top->next->content > stack_a->top->next->next->content))
	{
		ft_op_ra(stack_a, stack_move);
		ft_op_sa(stack_a, stack_move);
	}
	if ((stack_a->top->content < stack_a->top->next->content)
		&& (stack_a->top->next->content > stack_a->top->next->next->content)
		&& (stack_a->top->content < stack_a->top->next->next->content))
	{
		ft_op_rra(stack_a, stack_move);
		ft_op_sa(stack_a, stack_move);
	}
	if ((stack_a->top->content > stack_a->top->next->content)
		&& (stack_a->top->next->content < stack_a->top->next->next->content)
		&& (stack_a->top->content > stack_a->top->next->next->content))
		ft_op_ra(stack_a, stack_move);
	if ((stack_a->top->content < stack_a->top->next->content)
		&& (stack_a->top->content > stack_a->top->next->next->content))
		ft_op_rra(stack_a, stack_move);
	if ((stack_a->top->content > stack_a->top->next->content)
		&& (stack_a->top->next->content < stack_a->top->next->next->content))
		ft_op_sa(stack_a, stack_move);
}

void	check_four(t_stack *stack_a, t_stack *stack_b, t_stack_move *stack_move)
{
	ft_check_min(stack_a, stack_move);
	ft_op_pb(stack_a, stack_b, stack_move);
	check_three(stack_a, stack_move);
	ft_op_pa(stack_a, stack_b, stack_move);
}

void	check_five(t_stack *stack_a, t_stack *stack_b, t_stack_move *stack_move)
{
	ft_check_min(stack_a, stack_move);
	ft_op_pb(stack_a, stack_b, stack_move);
	check_four(stack_a, stack_b, stack_move);
	ft_op_pa(stack_a, stack_b, stack_move);
}
