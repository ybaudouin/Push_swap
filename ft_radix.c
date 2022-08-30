/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:20:17 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/30 18:16:26 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	ft_find_index(t_stack *stack_a)
{
	int			index;
	t_elements	*tmp;
	t_elements	*tmp2;

	tmp = stack_a->top;
	tmp2 = tmp->next;
	while (tmp)
	{
		index = 0;
		while (tmp2)
		{
			if (tmp->content > tmp2->content)
				index++;
			tmp2 = tmp2->next;
		}
		tmp->index = index;
		tmp = tmp->next;
		tmp2 = stack_a->top;
	}
}

void	ft_check_pb(t_stack *stack_a, t_stack *stack_b, int i)
{
	int	j;
	int	len;
	
	j = 0;
	len = ft_len_of_stack(stack_b);
	while (j < len)
	{
		if ((stack_b->top->index >> i) & 1)
			ft_op_pa(stack_a, stack_b);
		else
			ft_op_rb(stack_b);
		j++;
	}
}
void	ft_sort_radix(t_stack *stack_a, t_stack *stack_b)
{
	int	len;
	int	j;
	int	i;
	int	bits;
	
	i = 0;
	bits = ft_binary_index(stack_a);
	while (i < bits)
	{
		j = 0;
		len = ft_len_of_stack(stack_a);
		while (j < len)
		{
			if ((stack_a->top->index >> i) & 1)
				ft_op_ra(stack_a);
			else
				ft_op_pb(stack_a, stack_b);
			j++;
		}
		if (i < bits - 1)
			ft_check_pb(stack_a, stack_b, i + 1);
		i++;
	}
	while (stack_b->top)
		ft_op_pa(stack_a, stack_b);
}

int	ft_binary_index(t_stack *stack_a)
{
	int	index;
	int	i;

	i = 0;
	index = (ft_len_of_stack(stack_a) - 1);
	while (index)
	{
		index = index / 2;
		i++;
	}
	return (i);
}


