/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:58:29 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 16:10:31 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			ft_get_map(t_list **map, char *buff)
{
	t_list	*tmp;
	int		alert;

	alert = 0;
	if (!buff)
		return ;
	if ((tmp = ft_create_elem(buff)))
		ft_list_push_back(map, tmp);
}

static t_room		*ft_val(char *str, t_room *map)
{
	while (map)
	{
		if (ft_strequ(map->data, str))
		{
			free(str);
			return (map);
		}
		map = map->next;
	}
	free(str);
	return (NULL);
}

static void			ft_linker(t_room **map, t_room *begin, t_list *tube)
{
	t_room	*tmp;
	t_list	*begin_tube;
	int		val;

	begin_tube = tube;
	while (*map)
	{
		while (tube)
		{
			if (!(((char *)(tube->data))[0] == '#'))
				if ((val = ft_pile_face((*map)->data, tube->data)))
				{
					if (val == 2)
						tmp = ft_val(ft_cut_str(tube->data, '-'), begin);
					else
						tmp = ft_val(ft_begin_str(tube->data, '-'), begin);
					ft_add_room(map, tmp);
				}
			tube = tube->next;
		}
		tube = begin_tube;
		(*map) = (*map)->next;
	}
	*map = begin;
}

static int			ft_transfer(t_room **room, t_list *map)
{
	t_list	*tube;
	t_room	*begin;
	int		alert;

	alert = 0;
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
	begin = *room;
	ft_linker(room, begin, tube);
	return (alert);
}

int					main(void)
{
	t_list	*map;
	t_room	*room;
	char	*buff;
	t_chain	*network;

	buff = NULL;
	map = NULL;
	room = NULL;
	network = NULL;
	while (get_next_line(0, &buff) > 0)
	{
		ft_get_map(&map, buff);
		free(buff);
	}
	free(buff);
	if (!ft_error(map) && !ft_transfer(&room, map->next))
		normal_execution(map, room, network);
	delete_all(&map, &room, &network);
	return (0);
}
