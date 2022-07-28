/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:38:09 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/07/28 13:19:15 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	ft_len_of_pile(t_pile *pile_a)
{
	int			i;
	t_elements	*tmp;

	i = 0;
	tmp = pile_a->top;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return(i);
}
/*
int	ft_index(t_pile *pile)
{
	int			*tab;
	int			i;
	t_elements	*tmp;

	tab = malloc(sizeof(int) * ft_len_of_pile(pile));
	tmp = pile_a->top;
	i = 0;
	while (tmp != NULL)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
}*/

void	ft_check_min(t_pile *pile_a)
{
	int			tmp_min;
	int			index;
	int			index_min;
	t_elements	*tmp;

	if (!pile_a->top)
		return ;
	index = 0;
	index_min = 0;
	tmp = pile_a->top;
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
	if (index_min < (ft_len_of_pile(pile_a) / 2))
	{
		while (index_min--)
			ft_rotate(pile_a);
	}
	else
	{
		index_min = ft_len_of_pile(pile_a) - index_min;
		while (index_min--)
			ft_reverse_rotate(pile_a);
	}
}

void	check_three(t_pile *pile_a)
{
	if ((pile_a->top->content > pile_a->top->next->content) &&
		(pile_a->top->next->content > pile_a->top->next->next->content))
	{
		ft_rotate(pile_a);
		ft_swap(pile_a);
	}
	if ((pile_a->top->content < pile_a->top->next->content) &&
		(pile_a->top->next->content > pile_a->top->next->next->content) &&
		(pile_a->top->content < pile_a->top->next->next->content))
	{
		ft_reverse_rotate(pile_a);
		ft_swap(pile_a);
	}
	if ((pile_a->top->content > pile_a->top->next->content) &&
		(pile_a->top->next->content < pile_a->top->next->next->content) &&
		(pile_a->top->content > pile_a->top->next->next->content))
		ft_rotate(pile_a);
	if ((pile_a->top->content < pile_a->top->next->content) &&
		(pile_a->top->content > pile_a->top->next->next->content))
		ft_reverse_rotate(pile_a);
	if ((pile_a->top->content > pile_a->top->next->content) &&
		(pile_a->top->next->content < pile_a->top->next->next->content))
		ft_swap(pile_a);
}

void check_four(t_pile *pile_a, t_pile *pile_b)
{
	ft_check_min(pile_a);
	ft_pb(pile_a, pile_b);
	check_three(pile_a);
}

void	check_five(t_pile *pile_a, t_pile *pile_b)
{
	ft_check_min(pile_a);
	ft_pb(pile_a, pile_b);
	check_four(pile_a, pile_b);
}
