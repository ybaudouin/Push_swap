/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:24:40 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/30 15:18:44 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "push_swap.h"
# include "libft/libft.h"

t_elements	*ft_create(int nbr);
int			ft_len_of_pile(t_stack *stack_a);
int			ft_index(t_stack *stack);
void		check_three(t_stack *stack_a);
void		ft_init(t_stack *stack_a, t_stack *stack_b);
void		check_four(t_stack *stack_a, t_stack *stack_b);
void		check_five(t_stack *stack_a, t_stack *stack_b);
void		ft_free(t_stack *stack_a);
int			parsing_check(char *argv);
int			verif_arg(char *argv);
int			check_error(char *argv);
void		ft_free_tab(char **tab);
void		ft_parsing(char **argv, t_stack *stack_a);
char		*ft_strjoin_push_swap(char *s1, char const *s2, char *separator);
int			ft_isspace(char **argv);
void		parsing_str(char **argv);
void		ft_error(void);
void		parsing_create(t_stack *stack_a, char **tab);
void		parsing_double(t_stack *stack_a);
void		ft_atoi_check(const char *nptr, int *err_flag);
void		ft_check_atoi(t_stack *stack_a, char **argv);
void		ft_check_order(t_stack *stack_a, int *err_flag);
void		parsing_order(t_stack *stack_a);
void		ft_op_sa(t_stack *stack_a);
void		ft_op_pa(t_stack *stack_a, t_stack *stack_b);
void		ft_op_ra(t_stack *stack_a);
void		ft_op_rra(t_stack *stack_a);
void		ft_op_sb(t_stack *stack_b);
void		ft_op_pb(t_stack *stack_b, t_stack *stack_a);
void		ft_op_rb(t_stack *stack_b);
void		ft_op_rrb(t_stack *stack_b);
void		ft_op_ss(t_stack *stack_a, t_stack *stack_b);
void		ft_op_rr(t_stack *stack_a, t_stack *stack_b);
void		ft_op_rrr(t_stack *stack_a, t_stack *stack_b);
int			ft_len_of_stack(t_stack *stack_a);
void		check_two(t_stack *stack_a);
void		ft_addback(t_stack *stack, t_elements *new);
void		ft_sort_algo(t_stack *stack_a, t_stack *stack_b);
void		ft_find_index(t_stack *stack_a);
void		ft_sort_radix(t_stack *stack_a, t_stack *stack_b);
int			ft_binary_index(t_stack *stack_a);


#endif
