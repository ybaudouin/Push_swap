/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:38:09 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/24 14:59:07 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	ft_len_of_stack(t_stack *stack_a)
{
	int			i;
	t_elements	*tmp;

	i = 0;
	tmp = stack_a->top;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return(i);
}

void	ft_check_min(t_stack *stack_a)
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
	while(tmp != NULL)
	{
		if (tmp->content < tmp_min)
		{
			tmp_min = tmp->content;
			index_min = index;
		}
		index++;
		tmp = tmp->next;
	}
	if (index_min < (ft_len_of_stack(stack_a) / 2))
	{
		while (index_min--)
			ft_rotate(stack_a);
	}
	else
	{
		index_min = ft_len_of_stack(stack_a) - index_min;
		while (index_min--)
			ft_reverse_rotate(stack_a);
	}
}

void	check_three(t_stack *stack_a)
{
	if ((stack_a->top->content > stack_a->top->next->content) &&
		(stack_a->top->next->content > stack_a->top->next->next->content))
	{
		ft_rotate(stack_a);
		ft_swap(stack_a);
	}
	if ((stack_a->top->content < stack_a->top->next->content) &&
		(stack_a->top->next->content > stack_a->top->next->next->content) &&
		(stack_a->top->content < stack_a->top->next->next->content))
	{
		ft_reverse_rotate(stack_a);
		ft_swap(stack_a);
	}
	if ((stack_a->top->content > stack_a->top->next->content) &&
		(stack_a->top->next->content < stack_a->top->next->next->content) &&
		(stack_a->top->content > stack_a->top->next->next->content))
		ft_rotate(stack_a);
	if ((stack_a->top->content < stack_a->top->next->content) &&
		(stack_a->top->content > stack_a->top->next->next->content))
		ft_reverse_rotate(stack_a);
	if ((stack_a->top->content > stack_a->top->next->content) &&
		(stack_a->top->next->content < stack_a->top->next->next->content))
		ft_swap(stack_a);
}

void check_four(t_stack *stack_a, t_stack *stack_b)
{
	ft_check_min(stack_a);
	ft_pb(stack_a, stack_b);
	check_three(stack_a);
}

void	check_five(t_stack *stack_a, t_stack *stack_b)
{
	ft_check_min(stack_a);
	ft_pb(stack_a, stack_b);
	check_four(stack_a, stack_b);
}
