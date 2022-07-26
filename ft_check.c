/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:38:09 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/07/26 16:45:58 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "proto.h"

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
	i = 0;
	
}*/
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

void ft_find_n_min(t_pile *pile_a, t_pile *pile_b)
{
	int			tmp_min;
	t_elements	*tmp;

	if (!pile_a->top)
		return ;
	tmp = pile_a->top;
	tmp_min = 2147483647;
	while(tmp != NULL)
	{
		if (tmp->content < tmp_min)
			tmp_min = tmp->index;
		tmp = tmp->next;
	}
	if (tmp_min == 1)
		ft_pb(pile_a, pile_b);
	if (tmp_min == 2)
	{
		ft_swap(pile_a);
		ft_pb(pile_a, pile_b);
	}
	if (tmp_min == 3)
	{
		ft_reverse_rotate(pile_a);
		ft_reverse_rotate(pile_a);
		ft_pb(pile_a, pile_b);
	}
	if (tmp_min == 4)
	{
		ft_reverse_rotate(pile_a);
		ft_pb(pile_a, pile_b);
	}
}

//void	check_four(t_pile *pile_a)
//{
//
//}
