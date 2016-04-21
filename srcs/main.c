/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:58:29 by jealonso          #+#    #+#             */
/*   Updated: 2016/04/21 17:34:17 by jealonso         ###   ########.fr       */
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

/*
**				TODO DELETE THIS FUNCTION
*/

void				ft_put_room(t_room *map)
{
	int	i;

	while (map)
	{
		i = -1;
		while (++i < map->nb_malloc)
			if (map->link[i])
			printf("[%s](room)\t[%s](son link)\n", map->data, map->link[i]->data);
//		printf("-----( %d )-----\n", i);
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
	/*if (buff[0] == '#' && buff[1] != '#')
		return ;*/
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
			{
				if ((val = ft_pile_face((*map)->data, tube->data)))
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
	{
			network = ft_find_way(room);
		//	ft_resolver(network);
//		ft_display_link(room);
//		ft_putlist(map);
//		ft_put_room(room);
	}
	ft_lstdel(&map);
	ft_delete_room(&room);
	ft_delet_network(&network);
	return (0);
}
