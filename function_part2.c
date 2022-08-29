/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_part2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:06:36 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/24 14:52:33 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	ft_reverse_rotate(t_stack *stack)
{
	t_elements	*tmp;
	int			nbr;
	int			nbr_tmp;

	if (!stack->top || !stack->top->next)
		return ;
	else if (!stack->top->next->next)
	{
		ft_swap(stack);
		return ;
	}
	tmp = stack->top;
	nbr = tmp->next->content;
	tmp->next->content = tmp->content;
	tmp = tmp->next;
	while (tmp->next != NULL)
	{
		nbr_tmp = nbr;
		nbr = tmp->next->content;
		tmp->next->content = nbr_tmp;
		tmp = tmp->next;
	}
	stack->top->content = nbr;
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	t_elements	*tmp;

	if (!stack_a->top)
		return ;
	tmp = stack_a->top->next;
	ft_addfront(stack_b, stack_a->top);
	stack_a->top = tmp;
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_elements	*tmp;

	if (!stack_b->top)
		return ;
	tmp = stack_b->top->next;
	ft_addfront(stack_a, stack_b->top);
	stack_b->top = tmp;
}
