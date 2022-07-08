/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:31:31 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/07/08 16:41:08 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elements  *ft_create(int nbr)
{
    t_elements  *new;
    
    new = malloc(sizeof(t_elements));
    new->content = nbr;
    new->next = NULL;
    return (new);
}

void    ft_addback(t_pile *pile_a, t_elements *new)
{
    t_elements *tmp;

    if(!pile_a->top)
        pile_a->top = new;
    else
    {
        tmp = pile_a->top;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}

void    ft_addfront(t_pile *pile_a, t_elements *new)
{
    if (!pile_a->top)
        pile_a->top = new;
    else
    {
        new->next = pile_a->top;
        pile_a->top = new;
    }
}

void    ft_swap(t_pile *pile_a)
{
    int tmp;

    tmp = pile_a->top->content;
    pile_a->top->content = pile_a->top->next->content;
    pile_a->top->next->content = tmp;
}

void    ft_reverse(t_pile *pile_a)
{
    
}

int main(int argc, char **argv)
{
    t_pile  pile_a;
    t_elements  *new;

    if (argc < 2)
        return (1);
    pile_a.top = NULL;
    new = ft_create(ft_atoi(argv[1]));
    ft_addfront(&pile_a, new);
    new = ft_create(ft_atoi(argv[2]));
    ft_addback(&pile_a, new);
    printf("%d\n%d\n", pile_a.top->content, pile_a.top->next->content);
    ft_swap(&pile_a);
    printf("%d\n%d\n", pile_a.top->content, pile_a.top->next->content);
}