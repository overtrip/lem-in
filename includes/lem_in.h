/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 16:03:10 by jealonso          #+#    #+#             */
/*   Updated: 2016/02/10 16:24:47 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdio.h>
# define SIZE 5

/*typedef struct			s_map
{
	void				*data;
	struct s_list		*next;
	struct s_map		**link;
}						t_map;*/

void					ft_error(t_list *map);
char					*ft_begin_str(char *str, char c);
char					*ft_cut_str(char *str, char c);
t_list					*find_tube(t_list *map);
int						ft_pile_face(char *str1, char *str2);
void					ft_config_room(t_list **map, int *flag);

#endif
