/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:51:36 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/29 10:29:11 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	ft_check_order(t_stack *stack_a, int *err_flag)
{
	t_elements	*tmp;

	tmp = stack_a->top;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			*err_flag += 1;
		tmp = tmp->next;
	}
}

void	parsing_order(t_stack *stack_a)
{
	int	err_flag;

	err_flag = 0;
	ft_check_order(stack_a, &err_flag);
	if (err_flag == 0)
	{
		ft_free(stack_a);
		exit (1);
	}
}
