/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:57:08 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/18 16:58:01 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			ft_realloc_room(t_room *map)
{
	t_room	**link;
	int		nb;

	nb = 0;
	if (!(link = (t_room **)malloc(sizeof(t_room *) *
					(map->nb_malloc + 5))))
		return ;
	ft_bzero(link, sizeof(t_room *) * (map->nb_malloc + 5));
	while (nb < map->nb_malloc)
	{
		link[nb] = map->link[nb];
		++nb;
	}
	map->nb_malloc += 5;
	free(map->link);
	map->link = link;
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
		ft_realloc_room(map);
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

void				ft_delete_room(t_room **room)
{
	t_room	*tmp;
	t_room	*current;

	if (room)
	{
		current = *room;
		while (current)
		{
			if (current->link)
				free(current->link);
			if (current->data)
				free(current->data);
			tmp = current;
			current = current->next;
			free(tmp);
		}
		*room = NULL;
	}
}
