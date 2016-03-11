/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:58:29 by jealonso          #+#    #+#             */
/*   Updated: 2016/03/11 16:09:13 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**TODO DELETE THIS FUNCTION
*/
void				ft_display_link(t_list *map)
{
	int		i;
	t_list	*tube;

	tube = find_tube(map);
	while (!ft_strequ(map->data, tube->data))
	{
		i = -1;
		while (++i <= map->nb_malloc)
			if (map->link[i])
				printf("[%p](map)\t[%s](map->data)\t\t[%p](map->link)\n",
						map, ft_begin_str(map->data, ' '), map->link[i]);
		map = map->next;
	}
}

static void			ft_get_map(t_list **map, char *buff)
{
	if (!buff)
		return ;
	if (buff[0] == '#' && buff[1] != '#')
		return ;
	ft_list_push_back(map, ft_create_elem(buff));
}

static t_list		*ft_val(char *str, t_list **map)
{
	t_list	*begin;
	t_list	*tube;
	char	*tmp;

	begin = *map;
	tube = find_tube(*map);
	while (ft_strcmp((*map)->data, tube->data))
	{
		tmp = ft_begin_str((*map)->data, ' ');
		if (ft_strequ(tmp, str))
			return (*map);
		*map = (*map)->next;
	}
	*map = begin;
	return (begin);
}

static void			ft_find_room(t_list **map, t_list *tube)
{
	char	*room;
	t_list	*tmp;
	t_list	*save;
	int		val;

	room = ft_begin_str((*map)->data, ' ');
	save = *map;
	while (tube)
	{
		if ((val = ft_pile_face(room, tube->data)))
		{
			if (val == 2)
				tmp = ft_val(ft_cut_str(tube->data, '-'), map);
			else
				tmp = ft_val(ft_begin_str(tube->data, '-'), map);
			*map = save;
			ft_add_room(map, &tmp);
		}
		tube = tube->next;
	}
}

static void			ft_linker(t_list **map, t_list **save)
{
	t_list	*tube;

	tube = find_tube(*map);
	*save = *map;
	while ((*map) != tube)
	{
		ft_find_room(map, tube);
		(*map) = (*map)->next;
	}
	*map = *save;
}

int					main(void)
{
	t_list	*map;
	t_list	*begin;
	char	*buff;

	buff = NULL;
	map = NULL;
	begin = map;
	while (get_next_line(0, &buff) > 0)
		ft_get_map(&map, buff);
	ft_error(map);
	ft_linker(&(map->next), &begin);
	ft_display_link(map);
	ft_putlist(map);
	return (0);
}
