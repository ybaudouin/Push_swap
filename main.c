/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:31:31 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/07/19 11:39:55 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pile		pile_a;
	t_pile		pile_b;
	t_elements	*new;

	if (argc < 2)
		return (1);
	pile_a.top = NULL;
	pile_b.top = NULL;
	new = ft_create(ft_atoi(argv[1]));
	ft_addfront(&pile_a, new);
//  free(new);
	new = ft_create(ft_atoi(argv[2]));
	ft_addback(&pile_a, new);
	new = ft_create(ft_atoi(argv[3]));
	ft_addback(&pile_a, new);
	printf("%d\n%d\n%d\n\n", pile_a.top->content, pile_a.top->next->content, pile_a.top->next->next->content);
	ft_pb(&pile_a, &pile_b);
	ft_pb(&pile_a, &pile_b);
//	printf("%d\n%d\n", pile_a.top->content, pile_a.top->next->content);
//	ft_swap(&pile_a);
//	printf("%d\n%d\n", pile_a.top->content, pile_a.top->next->content);
//	new = ft_create(ft_atoi(argv[3]));
//	ft_addback(&pile_a, new);
//	printf("%d\n%d\n%d\n\n", pile_a.top->content, pile_a.top->next->content, pile_a.top->next->next->content);
//	ft_rotate(&pile_a);
//	printf("%d\n%d\n%d\n\n", pile_a.top->content, pile_a.top->next->content, pile_a.top->next->next->content);
	printf("%d\n\n", pile_a.top->content);
	printf("%d\n%d\n\n", pile_b.top->content, pile_b.top->next->content);
	ft_pa(&pile_a, &pile_b);
	printf("%d\n%d\n\n", pile_a.top->content, pile_a.top->next->content);
	printf("%d\n", pile_b.top->content);
//	ft_reverse_rotate(&pile_a);
//	printf("%d\n%d\n", pile_a.top->content, pile_a.top->next->content);
	free(new);
}
