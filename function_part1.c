/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_part1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:05:13 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/24 14:46:37 by ybaudoui         ###   ########.fr       */
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

void	ft_addback(t_stack *stack, t_elements *new)
{
	t_elements	*tmp;

	if (!stack->top)
		stack->top = new;
	else
	{
		tmp = stack->top;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

void	ft_addfront(t_stack *stack, t_elements *new)
{
	if (!stack->top)
		stack->top = new;
	else
	{
		new->next = stack->top;
		stack->top = new;
	}
}

void	ft_swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->top->content;
	stack->top->content = stack->top->next->content;
	stack->top->next->content = tmp;
}

void	ft_rotate(t_stack *stack)
{
	t_elements	*tmp;
	int			nbr;

	if (!stack->top || !stack->top->next)
		return ;
	tmp = stack->top;
	while (tmp->next != NULL)
	{
		nbr = tmp->content;
		tmp->content = tmp->next->content;
		tmp->next->content = nbr;
		tmp = tmp->next;
	}
}
