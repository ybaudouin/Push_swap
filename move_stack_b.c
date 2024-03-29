/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:24:15 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/31 15:03:56 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	ft_op_sb(t_stack *stack_b, t_stack_move *stack_move)
{
	t_elements	*tmp;

	if (!stack_b->top || !stack_b->top->next)
		return ;
	tmp = stack_b->top;
	stack_b->top = stack_b->top->next;
	tmp->next = stack_b->top->next;
	stack_b->top->next = tmp;
	ft_createback_link(stack_move, "sb\n");
}

void	ft_op_pb(t_stack *stack_a, t_stack *stack_b, t_stack_move *stack_move)
{
	t_elements	*tmp;

	if (!stack_a->top)
		return ;
	tmp = stack_a->top;
	stack_a->top = stack_a->top->next;
	tmp->next = NULL;
	if (!stack_b->top)
		stack_b->top = tmp;
	else
	{
		tmp->next = stack_b->top;
		stack_b->top = tmp;
	}
	ft_createback_link(stack_move, "pb\n");
}

void	ft_op_rb(t_stack *stack_b, t_stack_move *stack_move)
{
	t_elements	*tmp;
	t_elements	*tmp2;

	if (!stack_b->top || !stack_b->top->next)
		return ;
	tmp = stack_b->top;
	stack_b->top = stack_b->top->next;
	tmp->next = NULL;
	tmp2 = stack_b->top;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	ft_createback_link(stack_move, "rb\n");
}

void	ft_op_rrb(t_stack *stack_b, t_stack_move *stack_move)
{
	t_elements	*tmp;
	t_elements	*previous_tmp;

	if (!stack_b->top || !stack_b->top->next)
		return ;
	tmp = stack_b->top;
	while (tmp->next != NULL)
	{
		previous_tmp = tmp;
		tmp = tmp->next;
	}
	tmp->next = stack_b->top;
	stack_b->top = tmp;
	previous_tmp->next = NULL;
	ft_createback_link(stack_move, "rrb\n");
}
