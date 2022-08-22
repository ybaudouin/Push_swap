/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:31:31 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/22 17:25:32 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pile	pile_a;
	t_pile	pile_b;

	if (argc < 2)
		return (1);
	ft_init(&pile_a, &pile_b);
	ft_parsing_multiple(argv, &pile_a);
	printf("%d\n%d\n%d\n%d\n%d\n", pile_a.top->content, pile_a.top->next->content, pile_a.top->next->next->content, pile_a.top->next->next->next->content,  pile_a.top->next->next->next->next->content);
	check_five(&pile_a, &pile_b);
	ft_pa(&pile_a, &pile_b);
	ft_pa(&pile_a, &pile_b);
	printf("\n%d\n%d\n%d\n%d\n%d\n", pile_a.top->content, pile_a.top->next->content, pile_a.top->next->next->content, pile_a.top->next->next->next->content, pile_a.top->next->next->next->next->content);
	ft_free(&pile_a);
}
