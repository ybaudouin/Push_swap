/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:31:26 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/07/19 16:37:43 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_elements
{
	int					content;
	int					index;
	struct s_elements	*next;
}	t_elements;

typedef struct s_pile
{
	t_elements	*top;
}	t_pile;

#endif