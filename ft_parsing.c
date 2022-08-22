/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:34:23 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/22 17:24:38 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void ft_parsing_multiple(char **argv, t_pile *pile_a)
{
	t_elements	*new;
	char		**tab;
	char		*str;
	int			i;
	int			j;

	i = 1;
	j = 0;
	str = NULL;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			free(str);
			ft_printf("Error\n");
			exit(1);
		}
		str = ft_strjoin_push_swap(str, argv[i], " ");
		i++;
	}
	tab = ft_split(str, ' ');
	while (tab[j])
	{
		if (parsing_check(tab[j]) == 1)
		{
			ft_printf("Error\n");
			exit(1);
		}
	new = ft_create(ft_atoi(tab[j]));
	new->index = i;
	ft_addback(pile_a, new);
	i++;
	j++;
	}
}
/*
	while (argv[j])
		{
			if (parsing_check(argv[j]) == 1)
			{
				ft_printf("Error\n");
				exit(1);
			}
				j++;
		}
	while (i < argc)
	{
		new = ft_create(ft_atoi(argv[i]));
		new->index = i;
		ft_addback(pile_a, new);
		i++;
	}
*/