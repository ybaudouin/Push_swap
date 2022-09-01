/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:02:16 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/09/01 10:32:07 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	ft_print_stack_move(t_stack_move *stack_move)
{
	t_link	*tmp;

	if (!stack_move->top)
		return ;
	tmp = stack_move->top;
	while (tmp)
	{
		ft_printf("%s", tmp->print);
		tmp = tmp->next;
	}
}

void	ft_free_stack_move(t_stack_move *stack_move)
{
	t_link	*tmp;

	if (!stack_move->top)
		return ;
	while (stack_move->top)
	{
		tmp = stack_move->top;
		stack_move->top = stack_move->top->next;
		free(tmp);
		tmp = NULL;
	}
	free(stack_move->top);
	stack_move->top = NULL;
}

void	ft_remove_op(t_link *previous_tmp)
{
	t_link	*tmp;
	t_link	*tmp2;

	tmp = previous_tmp;
	tmp = tmp->next;
	tmp2 = tmp->next;
	previous_tmp->next = previous_tmp->next->next->next;
	free(tmp);
	free(tmp2);
}

void	ft_remove_double(t_stack_move *stack_move)
{
	t_link	*tmp;
	t_link	*tmp2;
	t_link	*previous_tmp;

	tmp = stack_move->top;
	tmp2 = stack_move->top->next;
	while (tmp->next)
	{
		previous_tmp = tmp;
		if ((!ft_strcmp(tmp->next->print, "pb\n"))
			&& (!ft_strcmp(tmp2->next->print, "pa\n")))
		{
			ft_remove_op(previous_tmp);
			tmp = stack_move->top;
			tmp2 = tmp->next;
		}
		else
		{
			tmp = tmp->next;
			tmp2 = tmp->next;
		}
	}
}
