/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 16:03:10 by jealonso          #+#    #+#             */
/*   Updated: 2016/04/10 18:06:31 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdio.h>
# define SIZE 5

typedef struct			s_chain
{
	size_t				len;
	struct s_chain		*chain;
	struct s_chain		*next;
	t_list				*data;
}						t_chain;

void					ft_error(t_list *map);
char					*ft_begin_str(char *str, char c);
char					*ft_cut_str(char *str, char c);
t_list					*find_tube(t_list *map);
int						ft_pile_face(char *str1, char *str2);
void					ft_config_room(t_list **map, int *flag);
void					ft_add_room(t_list *map, t_list *room);
void					ft_new_way(t_chain **network, t_chain *old);
t_chain					*ft_create_chain(t_list *tmp);
void					ft_chain_push_back(t_chain **begin, t_chain *new);
void					ft_find_way(t_list *map);
void					ft_clear_null(t_list *map);

void					ft_display_link(t_list *map);

#endif
