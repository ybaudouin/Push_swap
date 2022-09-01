/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:45:29 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/31 09:32:15 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	ft_free(t_stack *stack_a)
{
	t_elements	*tmp;
	t_elements	*tmp_next;

	if (!stack_a->top)
		return ;
	tmp = stack_a->top;
	tmp_next = tmp->next;
	while (tmp_next != NULL)
	{
		free(tmp);
		tmp = tmp_next;
		tmp_next = tmp_next->next;
	}
	free(tmp);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
