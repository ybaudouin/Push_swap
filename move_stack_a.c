/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:46:56 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/31 14:53:07 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	ft_op_sa(t_stack *stack_a, t_stack_move *stack_move)
{
	t_elements	*tmp;

	if (!stack_a->top || !stack_a->top->next)
		return ;
	tmp = stack_a->top;
	stack_a->top = stack_a->top->next;
	tmp->next = stack_a->top->next;
	stack_a->top->next = tmp;
	write(1, "sa\n", 3);
	ft_createback_link(stack_move, "sa\n");
}

void	ft_op_pa(t_stack *stack_a, t_stack *stack_b, t_stack_move *stack_move)
{
	t_elements	*tmp;

	if (!stack_b->top)
		return ;
	tmp = stack_b->top;
	stack_b->top = stack_b->top->next;
	tmp->next = NULL;
	if (!stack_a->top)
		stack_a->top = tmp;
	else
	{
		tmp->next = stack_a->top;
		stack_a->top = tmp;
	}
	ft_createback_link(stack_move, "pa\n");
}

void	ft_op_ra(t_stack *stack_a, t_stack_move *stack_move)
{
	t_elements	*tmp;
	t_elements	*tmp2;

	if (!stack_a->top || !stack_a->top->next)
		return ;
	tmp = stack_a->top;
	stack_a->top = stack_a->top->next;
	tmp->next = NULL;
	tmp2 = stack_a->top;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	ft_createback_link(stack_move, "ra\n");
}

void	ft_op_rra(t_stack *stack_a, t_stack_move *stack_move)
{
	t_elements	*tmp;
	t_elements	*previous_tmp;

	if (!stack_a->top || !stack_a->top->next)
		return ;
	tmp = stack_a->top;
	while (tmp->next != NULL)
	{
		previous_tmp = tmp;
		tmp = tmp->next;
	}
	tmp->next = stack_a->top;
	stack_a->top = tmp;
	previous_tmp->next = NULL;
	ft_createback_link(stack_move, "rra\n");
}
