/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:58:29 by jealonso          #+#    #+#             */
/*   Updated: 2016/04/18 18:19:47 by jealonso         ###   ########.fr       */
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

static void			ft_push_room_back(t_room **map, t_room *new)
{
	t_room	*begin;

	begin = *map;
	if (*map)
	{
		while (begin->next)
			begin = begin->next;
		begin->next = new;
	}
	else
		*map = new;
}

static void			ft_get_map(t_list **map, char *buff)
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

static t_room		*ft_val(char *str, t_room *map)
{
	while (map)
	{
		if (ft_strequ(map->data, str))
			return (map);
		map = map->next;
	}
	return (NULL);
}

static void			ft_linker(t_room **map, t_room *begin, t_list *tube)
{
	char	*room;
	t_room	*tmp;
	int		val;

	room = ft_strdup((*map)->data);
	while (*map)
	{
		while (tube)
		{
			if (!(((char *)(tube->data))[0] == '#'))
			{
				if ((val = ft_pile_face(room, tube->data)))
				{
					if (val == 2)
						tmp = ft_val(ft_cut_str(tube->data, '-'), begin);
					else
						tmp = ft_val(ft_begin_str(tube->data, '-'), begin);
					ft_add_room(map, tmp);
				}
			}
			tube = tube->next;
		}
		(*map) = (*map)->next;
	}
	free(room);
}

static int			ft_transfer(t_room **room, t_list *map)
{
	t_list	*tube;
	t_room	*begin;
	int		alert;

	alert = 0;
	begin = *room;
	tube = find_tube(map);
	while (map != tube)
	{
		if (!(((char *)(map->data))[0] == '#' &&
					((char *)(map->data))[1] != '#'))
			ft_push_room_back(room, ft_create_room(&map, &alert));
		if (alert)
		{
			ft_putendl("Problem detected");
			return (alert);
		}
		map = map->next;
	}
	ft_linker(room, begin, tube);
	return (alert);
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
		ft_display_link(room);
		//		ft_putlist(map);
	}
	ft_lstdel(&map);
	return (0);
}
