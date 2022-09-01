/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:26:53 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/31 14:54:42 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	ft_op_ss(t_stack *stack_a, t_stack *stack_b, t_stack_move *stack_move)
{
	t_elements	*tmp;
	t_elements	*tmp2;

	if (!stack_a->top || !stack_a->top->next)
		return ;
	if (!stack_b->top || !stack_b->top->next)
		return ;
	tmp = stack_a->top;
	stack_a->top = stack_a->top->next;
	tmp->next = stack_a->top->next;
	stack_a->top->next = tmp;
	tmp2 = stack_b->top;
	stack_b->top = stack_b->top->next;
	tmp2->next = stack_b->top->next;
	stack_b->top->next = tmp2;
	ft_createback_link(stack_move, "ss\n");
}

void	ft_op_rr(t_stack *stack_a, t_stack *stack_b, t_stack_move *stack_move)
{
	t_elements	*tmp;
	t_elements	*tmp2;

	if (!stack_a->top || !stack_a->top->next)
		return ;
	if (!stack_b->top || !stack_b->top->next)
		return ;
	tmp = stack_a->top;
	stack_a->top = stack_a->top->next;
	tmp->next = NULL;
	tmp2 = stack_a->top;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp = NULL;
	tmp2 = NULL;
	tmp = stack_b->top;
	stack_b->top = stack_b->top->next;
	tmp->next = NULL;
	tmp2 = stack_b->top;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	ft_createback_link(stack_move, "rr\n");
}

void	ft_op_rrr(t_stack *stack_a, t_stack *stack_b, t_stack_move *stack_move)
{
	t_elements	*tmp;
	t_elements	*previous_tmp;

	tmp = stack_a->top;
	if ((!tmp || !tmp->next) || (!stack_b->top || !stack_b->top->next))
		return ;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	previous_tmp = tmp;
	tmp = tmp->next;
	tmp->next = stack_a->top;
	stack_a->top = tmp;
	previous_tmp->next = NULL;
	tmp = NULL;
	previous_tmp = NULL;
	tmp = stack_b->top;
	while (tmp->next != NULL)
	{
		previous_tmp = tmp;
		tmp = tmp->next;
	}
	tmp->next = stack_b->top;
	stack_b->top = tmp;
	previous_tmp->next = NULL;
	ft_createback_link(stack_move, "rrr\n");
}
