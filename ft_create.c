/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:05:13 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/09/01 10:35:34 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

t_elements	*ft_create_elements(int nbr)
{
	t_elements	*new;

	new = malloc(sizeof(t_elements));
	new->content = nbr;
	new->next = NULL;
	return (new);
}

void	ft_addback_elements(t_stack *stack, t_elements *new)
{
	t_elements	*tmp;

	if (!stack->top)
		stack->top = new;
	else
	{
		tmp = stack->top;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_createback_link(t_stack_move *stack_move, char *str)
{
	t_link	*tmp;
	t_link	*new;

	new = malloc(sizeof(t_link));
	new->print = str;
	new->next = NULL;
	if (!stack_move->top)
		stack_move->top = new;
	else
	{
		tmp = stack_move->top;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
