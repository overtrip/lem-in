/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:58:29 by jealonso          #+#    #+#             */
/*   Updated: 2016/04/15 18:14:17 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**				TODO DELETE THIS FUNCTION
*/

void				ft_display_link(t_room *map)
{
	int		i;

	while (map)
	{
		i = -1;
		while (++i <= map->nb_malloc)
			if (map->link[i])
				printf("[%p](map)\t[%s](map->data)\t[%s](%d)(map->link)\n",
					map, map->data,
					map->link[i]->data, i);
		map = map->next;
	}
}

void			ft_push_room_back(t_room **map, t_room *new)
{
	t_room	*begin;

	begin = *map;
	if (*map)
	{
		while (*map)
			*map = (*map)->next;
		(*map)->next = new;
		*map = begin;
	}
	else
		*map = new;
}

void			ft_get_map(t_list **map, char *buff)
{
	t_list	*tmp;
	int		alert;

	alert = 0;
	if (!buff)
		return ;
	if (buff[0] == '#' && buff[1] != '#')
		return ;
	if ((tmp = ft_create_elem(buff)))
		ft_list_push_back(map, tmp);
}

t_room		*ft_val(char *str, t_room *map)
{
	while (map)
	{
		if (ft_strequ(map->data, str))
			return (map);
		map = map->next;
	}
	return (NULL);
}

void			ft_find_room(t_room *map, t_room *begin, t_list *tube)
{
	char	*room;
	t_room	*tmp;
	int		val;

	room = ft_strdup(map->data);
	while (tube)
	{
		if ((val = ft_pile_face(room, tube->data)))
		{
			if (val == 2)
				tmp = ft_val(ft_cut_str(tube->data, '-'), begin);
			else
				tmp = ft_val(ft_begin_str(tube->data, '-'), begin);
			ft_add_room(map, tmp);
		}
		tube = tube->next;
	}
	free(room);
}

void			ft_linker(t_room *map, t_room *begin, t_list	*tube)
{
	while (map)
	{
		ft_find_room(map, begin, tube);
		map = map->next;
	}
}

void			ft_transfer(t_room **room, t_list *map)
{
	t_list	*tube;
	t_room	*begin;
	int		alert;

	alert = 0;
	begin = *room;
	tube = find_tube(map);
	while (map != tube)
	{
	printf("[%s]\n", map->data);
		ft_push_room_back(room, ft_create_room(map, &alert));
		if (alert)
			ft_putendl("werhklwefjklhrwlikbgr");
		map = map->next;
	}
	ft_linker(*room, begin, tube);
}

int					main(void)
{
	t_list	*map;
	t_room	*room;
	char	*buff;
//	t_chain	*network;

	buff = NULL;
	map = NULL;
	room = NULL;
	while (get_next_line(0, &buff) > 0)
	{
		ft_get_map(&map, buff);
		free(buff);
	}
	free(buff);
	if (!ft_error(map))
	{
	ft_transfer(&room, map->next);
//	network = ft_find_way(map);
//	ft_resolver(network);
//	ft_display_link(room);
	ft_putlist(map);
	}
	ft_lstdel(&map);
	return (0);
}
