/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_part2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:06:36 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/07/19 12:03:22 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	ft_reverse_rotate(t_pile *pile)
{
	t_elements	*tmp;
	int			nbr;
	int			nbr_tmp;

	if (!pile->top || !pile->top->next)
		return ;
	else if (!pile->top->next->next)
	{
		ft_swap(pile);
		return ;
	}
	tmp = pile->top;
	nbr = tmp->next->content;
	tmp->next->content = tmp->content;
	tmp = tmp->next;
	while (tmp->next != NULL)
	{
		nbr_tmp = nbr;
		nbr = tmp->next->content;
		tmp->next->content = nbr_tmp;
		tmp = tmp->next;
	}
	pile->top->content = nbr;
}

void	ft_pb(t_pile *pile_a, t_pile *pile_b)
{
	t_elements	*tmp;

	if (!pile_a->top)
		return ;
	tmp = pile_a->top->next;
	ft_addfront(pile_b, pile_a->top);
	pile_a->top = tmp;
}

void	ft_pa(t_pile *pile_a, t_pile *pile_b)
{
	t_elements	*tmp;

	if (!pile_b->top)
		return ;
	tmp = pile_b->top->next;
	ft_addfront(pile_a, pile_b->top);
	pile_b->top = tmp;
}
