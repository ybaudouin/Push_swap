/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:34:23 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/31 14:11:48 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	parsing_create(t_stack *stack_a, char **tab)
{
	t_elements	*new;
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (tab[j])
	{
		if (parsing_check(tab[j]) == 1)
		{
			ft_free_tab(tab);
			ft_free(stack_a);
			ft_error();
		}
		new = ft_create_elements(ft_atoi(tab[j]));
		new->index = i;
		ft_addback_elements(stack_a, new);
		i++;
		j++;
	}
}

void	ft_parsing(char **argv, t_stack *stack_a)
{
	char		**tab;
	char		*str;
	int			i;

	i = 1;
	str = NULL;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			if (str)
				free(str);
			ft_error();
		}
		str = ft_strjoin_push_swap(str, argv[i], " ");
		i++;
	}
	tab = ft_split(str, ' ');
	free(str);
	ft_check_atoi(stack_a, tab);
	parsing_create(stack_a, tab);
	ft_free_tab(tab);
}

void	parsing_str(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isspace(&argv[i]) == 0)
			ft_error();
		i++;
	}
}

void	parsing_double(t_stack *stack_a)
{
	t_elements	*tmp;
	t_elements	*tmp2;

	tmp = stack_a->top;
	tmp2 = stack_a->top->next;
	while (tmp->next != NULL)
	{
		while (tmp2 != NULL)
		{
			if (tmp->content == tmp2->content)
			{
				ft_free(stack_a);
				ft_error();
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		tmp2 = tmp->next;
	}
}
