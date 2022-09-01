/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_radix.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:58:08 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/08/31 13:33:06 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTI_RADIX_H
# define OPTI_RADIX_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_link
{
	char				*print;
	struct s_link		*next;
}	t_link;

typedef struct s_stack_move
{
	t_link	*top;
}	t_stack_move;

#endif
