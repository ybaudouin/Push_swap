/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_part1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:05:13 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/07/19 11:33:53 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

t_elements	*ft_create(int nbr)
{
	t_elements	*new;

	new = malloc(sizeof(t_elements));
	new->content = nbr;
	new->next = NULL;
	return (new);
}

void	ft_addback(t_pile *pile, t_elements *new)
{
	t_elements	*tmp;

	if (!pile->top)
		pile->top = new;
	else
	{
		tmp = pile->top;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

void	ft_addfront(t_pile *pile, t_elements *new)
{
	if (!pile->top)
		pile->top = new;
	else
	{
		new->next = pile->top;
		pile->top = new;
	}
}

void	ft_swap(t_pile *pile)
{
	int	tmp;

	tmp = pile->top->content;
	pile->top->content = pile->top->next->content;
	pile->top->next->content = tmp;
}

void	ft_rotate(t_pile *pile)
{
	t_elements	*tmp;
	int			nbr;

	if (!pile->top || !pile->top->next)
		return ;
	tmp = pile->top;
	while (tmp->next != NULL)
	{
		nbr = tmp->content;
		tmp->content = tmp->next->content;
		tmp->next->content = nbr;
		tmp = tmp->next;
	}
}
