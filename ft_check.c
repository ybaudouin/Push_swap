/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:38:09 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/07/22 10:06:12 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "proto.h"

int	ft_len_of_pile(t_pile *pile)
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
	i = 0;
	while (tab[i] != '/0')
	{
		while ()
		{
		}
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
}
