/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:52:06 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/07/29 09:50:36 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"
#include "push_swap.h"

void	ft_init(t_pile *pile_a, t_pile *pile_b)
{
	pile_a->top = NULL;
	pile_b->top = NULL;
}
