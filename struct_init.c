/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:52:06 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/31 12:18:30 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	ft_init(t_stack *stack_a, t_stack *stack_b, t_stack_move *stack_move)
{
	stack_a->top = NULL;
	stack_b->top = NULL;
	stack_move->top = NULL;
}
