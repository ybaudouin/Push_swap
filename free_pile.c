/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:45:29 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/07/28 12:12:22 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	ft_free(t_pile *pile_a)
{
	t_elements	*tmp;
	t_elements	*tmp_next;

	if (!pile_a->top)
		return ;
	tmp = pile_a->top;
	tmp_next = tmp->next;
	while (tmp_next != NULL)
	{
		free(tmp);
		tmp = tmp_next;
		tmp_next = tmp_next->next;
	}
	free(tmp);
}