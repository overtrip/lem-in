/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:57:08 by jealonso          #+#    #+#             */
/*   Updated: 2016/04/18 15:27:07 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room		*ft_realloc_room(t_room **map)
{
	t_room	*tmp;
	t_room	*begin;
	int		nb;

	nb = -1;
	if (!(tmp = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	if (!(tmp->link = (t_room **)malloc(sizeof(t_room *) *
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

static void			ft_check_malloc(t_room *map)
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

void				ft_add_room(t_room **map, t_room *room)
{
	int		i;

	i = 0;
	ft_check_malloc(*map);
	while ((*map)->link[i])
		++i;
	(*map)->link[i] = room;
}
