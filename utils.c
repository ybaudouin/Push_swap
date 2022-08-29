/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:32:00 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/26 09:57:44 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

char	*ft_strjoin_push_swap(char *s1, char const *s2, char *separator)
{
	size_t	i;
	char	*str;

	if (s2 == 0)
		return (NULL);
	if (s1 == 0)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	i = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(separator);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[0] = '\0';
	ft_strlcpy(str, s1, i + 1);
	ft_strlcpy(str + ft_strlen(s1), separator, i + 1);
	ft_strlcpy(str + ft_strlen(s1) + ft_strlen(separator), s2, i + 1);
	free(s1);
	return (str);
}

int	ft_isspace(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_atoi_check(const char *nptr, int *err_flag)
{
	char	*tab;
	int		i;
	long	nbr;
	long	minus;

	minus = 0;
	i = 0;
	nbr = 0;
	tab = (char *) nptr;
	while ((tab[i] == ' ') || (tab[i] >= '\t' && tab[i] <= '\r'))
		i++;
	if (tab[i] == '-' || tab[i] == '+')
	{
		if (tab[i] == '-')
			minus = 1;
		i++;
	}
	while ((tab[i] != '\0') && (tab[i] >= '0') && (tab[i] <= '9'))
	{
		nbr = nbr * 10 + (tab[i] - '0');
		if (nbr > (2147483647 + minus))
			*err_flag += 1;
		i++;
	}
}

void	ft_check_atoi(t_stack *stack_a, char **argv)
{
	int	err_flag;
	int	i;

	err_flag = 0;
	i = 0;
	while (argv[i])
	{
		ft_atoi_check(argv[i], &err_flag);
		if (err_flag != 0)
		{
			ft_free(stack_a);
			ft_error();
		}
		i++;
	}
}
