/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:32:00 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/24 09:58:21 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "proto.h"

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

int	ft_isspace(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] != ' ' || argv[i] != '\t' || argv[i] != '\r')
			return (1);
		i++;
	}
	return (0);
}
