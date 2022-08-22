/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:15:38 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/22 11:57:00 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	parsing_check(char *argv)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(argv, ' ');
	while (tab[i])
	{
		if (check_error(tab[i]) == 1)
		{
			ft_free_tab(tab);
			return (1);
		}
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

int	verif_arg(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

//int	verif_int(char *argv)
//{
//	
//}

int	check_error(char *argv)
{
	if (verif_arg(argv) == 1)
		return (1);
//	if (verif_int(argv) == 1)
//		return (1);
	return (0);
}
