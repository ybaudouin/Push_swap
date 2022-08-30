/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:41:09 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/30 16:59:01 by ybaudoui         ###   ########.fr       */
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

void	ft_sort_algo(t_stack *stack_a, t_stack *stack_b)
{
//	int	len;

//	len = ft_len_of_stack(stack_a);
/*	if (len < 2)
		return ;
	else if (len < 3)
		check_two(stack_a);
	else if (len < 4)
		check_three(stack_a);
	else if (len < 5)
		check_four(stack_a, stack_b);
	else if (len < 6)
		check_five(stack_a, stack_b);
	else*/
		ft_sort_radix(stack_a, stack_b);
}
