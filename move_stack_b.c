/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:24:15 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/30 17:46:48 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	ft_op_sb(t_stack *stack_b)
{
	t_elements	*tmp;

	if(!stack_b->top || !stack_b->top->next)
		return ;
	tmp = stack_b->top;
	stack_b->top = stack_b->top->next;
	tmp->next = stack_b->top->next;
	stack_b->top->next = tmp;
	write(1, "sb\n", 3);
}

void	ft_op_pb(t_stack *stack_a, t_stack *stack_b)
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
	write(1, "pb\n", 3);
}

void	ft_op_rb(t_stack *stack_b)
{
	t_elements *tmp;
	t_elements *tmp2;

	if (!stack_b->top || !stack_b->top->next)
		return ;
	tmp = stack_b->top;
	stack_b->top = stack_b->top->next;
	tmp->next = NULL;
	tmp2 = stack_b->top;
	while (tmp2->next !=NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	write(1, "rb\n", 3);
}

void	ft_op_rrb(t_stack *stack_b)
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
	write(1, "rrb\n", 4);
}
