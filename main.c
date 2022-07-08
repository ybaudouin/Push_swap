/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:31:31 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/07/08 18:09:00 by ybaudoui         ###   ########.fr       */
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

void    ft_addback(t_pile *pile, t_elements *new)
{
    t_elements *tmp;

    if(!pile->top)
        pile->top = new;
    else
    {
        tmp = pile->top;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}

void    ft_addfront(t_pile *pile, t_elements *new)
{
    if (!pile->top)
        pile->top = new;
    else
    {
        new->next = pile->top;
        pile_a->top = new;
    }
}

void    ft_swap(t_pile *pile)
{
    int tmp;

    tmp = pile->top->content;
    pile->top->content = pile->top->next->content;
    pile->top->next->content = tmp;
}

void    ft_rotate(t_pile *pile)
{
    t_elements *tmp;
    int nbr;

    if(!pile->top || !pile->top->next)
        return ;
    tmp = pile->top;
    while (tmp->next != NULL)
    {
        nbr = tmp->content;
        tmp->content = tmp->next->content;
        tmp->next->content = nbr;
        tmp = tmp->next;
    }
}

void    ft_reverse_rotate(t_pile *pile)
{
    t_elements *tmp;
    int nbr;
    int nbr_tmp;

    if(!pile->top || !pile->top->next)
        return ;
    else if (!pile->top->next->next)
    {
        ft_swap(pile);
        return ;
    }
    tmp = pile->top;
    nbr = tmp->next->content;
    tmp->next->content = tmp->content;
    tmp = tmp->next;
    while(tmp->next != NULL)
    {
        nbr_tmp = nbr;
        nbr = tmp->next->content;
        tmp->next->content = nbr_tmp;
        tmp = tmp->next;
    }
    pile->top->content = nbr;
}

int main(int argc, char **argv)
{
    t_pile  pile_a;
    t_pile  pile_b;
    t_elements  *new;

    if (argc < 2)
        return (1);
    pile_a.top = NULL;
    new = ft_create(ft_atoi(argv[1]));
    ft_addfront(&pile_a, new);
    new = ft_create(ft_atoi(argv[2]));
    ft_addback(&pile_a, new);
  //  printf("%d\n%d\n", pile_a.top->content, pile_a.top->next->content);
 //   ft_swap(&pile_a);
 //   printf("%d\n%d\n", pile_a.top->content, pile_a.top->next->content);
    new = ft_create(ft_atoi(argv[3]));
    ft_addback(&pile_a, new);
 //   printf("%d\n%d\n%d\n\n", pile_a.top->content, pile_a.top->next->content, pile_a.top->next->next->content);
 //   ft_rotate(&pile_a);
 //   printf("%d\n%d\n%d\n\n", pile_a.top->content, pile_a.top->next->content, pile_a.top->next->next->content);
    printf("%d\n%d\n", pile_a.top->content, pile_a.top->next->content);
    ft_reverse_rotate(&pile_a);
    printf("%d\n%d\n", pile_a.top->content, pile_a.top->next->content);
}