/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:52:06 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/25 17:38:40 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"
#include "push_swap.h"

void	ft_init(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->top = NULL;
	stack_b->top = NULL;
}
