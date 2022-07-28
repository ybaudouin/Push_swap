/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:24:40 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/07/28 17:33:27 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "push_swap.h"
# include "libft/libft.h"

t_elements	*ft_create(int nbr);
void		ft_addback(t_pile *pile, t_elements *new);
void		ft_addfront(t_pile *pile, t_elements *new);
void		ft_swap(t_pile *pile);
void		ft_rotate(t_pile *pile);
void		ft_reverse_rotate(t_pile *pile);
void		ft_pb(t_pile *pile_a, t_pile *pile_b);
void		ft_pa(t_pile *pile_a, t_pile *pile_b);
int			ft_len_of_pile(t_pile *pile_a);
int			ft_index(t_pile *pile);
void		check_three(t_pile *pile_a);
void		ft_init(t_pile *pile_a, t_pile *pile_b);
void 		check_four(t_pile *pile_a, t_pile *pile_b);
void 		check_five(t_pile *pile_a, t_pile *pile_b);
void		ft_free(t_pile *pile_a);
int		parsing_check(char *argv);
int			verif_arg(char *argv);
int			check_error(char *argv);

#endif