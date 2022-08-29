/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:51:36 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/26 10:56:10 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	ft_check_order(char **tab, int *err_flag)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_atoi(tab[i]) > ft_atoi(tab[j]))
				err_flag += 1;
			j++;
		}
		i++;
	}
}

void	parsing_order(t_stack *stack_a, char **tab)
{
	int	i;
	int	err_flag;

	i = 0;
	err_flag = 0;
	while (tab[i])
	{
		ft_check_order(tab, &err_flag);
		if (err_flag == 0)
		{
			ft_free(stack_a);
			ft_error();
		}
		i++;
	}
}
