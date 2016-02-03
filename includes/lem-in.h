/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 16:03:10 by jealonso          #+#    #+#             */
/*   Updated: 2016/02/03 16:02:07 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H

#include "libft.h"
#include <stdio.h>

/*typedef struct			s_map
{
	void				*data;
	struct s_list		*next;
}						t_map;*/

void	ft_error(t_list *map);
char	*ft_begin_str(char *str, char c);
char	*ft_cut_str(char *str, char c);

#endif
