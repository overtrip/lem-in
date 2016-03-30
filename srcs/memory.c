/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:57:08 by jealonso          #+#    #+#             */
/*   Updated: 2016/03/30 17:38:25 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list		*ft_realloc_room(t_list **map)
{
	t_list	*tmp;
	t_list	*begin;
	int		nb;

	nb = -1;
	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(tmp->link = (t_list **)malloc(sizeof(t_list *) *
					((*map)->nb_malloc + 5))))
		return (NULL);
	(*map)->nb_malloc += 5;
	begin = *tmp->link;
	while (tmp->link[++nb])
	{
		if ((*map)->link[nb])
			tmp->link[nb] = (*map)->link[nb];
		else
			tmp->link[nb] = NULL;
	}
	*tmp->link = begin;
	return (*tmp->link);
}

static void			ft_check_malloc(t_list *map)
{
	int		nb;
	int		i;

	nb = 0;
	i = -1;
	while (++i < map->nb_malloc && map->link[i])
		++nb;
	if (nb >= map->nb_malloc)
		*map->link = ft_realloc_room(map->link);
}

void				ft_add_room(t_list *map, t_list *room)
{
	int		i;

	i = 0;
//printf("[%s](map)\t[%s](room a linker)\n", (*map)->data, room->data);
	ft_check_malloc(map);
	while (map->link[i])
		++i;
	map->link[i] = room;
}
