/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:41:09 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/29 17:45:38 by ybaudoui         ###   ########.fr       */
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

void	ft_sort_algo(t_stack *stack_a, t_stack *stack_b, char **argv)
{
	if (argv < 2)
		return ;
	else if (argv < 3)
}
