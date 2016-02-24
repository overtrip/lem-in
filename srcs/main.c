/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:58:29 by jealonso          #+#    #+#             */
/*   Updated: 2016/02/24 17:46:52 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static void	ft_get_map(t_list **map, char *buff)
{
	if (!buff)
		return ;
	if (buff[0] == '#' && buff[1] != '#')
		return ;
	ft_list_push_back(map, ft_create_elem(buff));
}

t_list		*ft_match(char *str, t_list **map)
{
	t_list *save;
	t_list *begin;

	save = *map;
	begin = *map;
	while (*map)
	{
		if (ft_strequ((*map)->data, str))
		{
			save = *map;
			*map = begin;
			break ;
		}
		*map = (*map)->next;
	}
	return (save);
}

t_list		*ft_val(char *str, t_list **map)
{
	t_list	*begin;
	t_list	*tmp;

	begin = *map;
	while (map)
	{
		if (ft_strequ(ft_cut_str((*map)->data, ' '), str))
		{
			tmp = (*map);
			*map = begin;
			return (tmp);
		}
		*map = (*map)->next;
	}
	*map = begin;
	return (begin);
}

void		ft_find_room(t_list **map, t_list *tube)
{
	char	*room;
	t_list	*tmp;
	int		val;

	room = ft_begin_str((*map)->data, ' ');
	while (tube)
	{
		if ((val = ft_pile_face(room, tube->data)))
		{
			if (val == 2)
				tmp = ft_val(ft_begin_str(tube->data, '-'), map);
			else
				tmp = ft_val(ft_cut_str(tube->data, '-') , map);
			//TODO change line 81 to a function who check if link->tab  not
			//empty and if was infact so realloc
			(*map)->link = tmp;
		}
		tube = tube->next;
	}
}

void		ft_linker(t_list **map, t_list **save)
{
	t_list	*tube;

	tube = find_tube(*map);
	while ((*map) != tube)
	{
		ft_find_room(map, tube);
		(*map) = (*map)->next;
	}
	map = save;
}

void		ft_display_link(t_list *map)
{
	while (map)
	{
		printf("[%p](map)       [%s](map->data)        [%p](map->link)\n",
				map, ft_begin_str(map->data, ' '), map->link);
		map = map->next;
	}
}

int			main(void)
{
	t_list	*map;
	t_list	*save;
	char	*buff;

	buff = NULL;
	map = NULL;
	while (get_next_line(0, &buff) > 0)
	{
		ft_get_map(&map, buff);
	}
	save = map;
	ft_error(map);
	ft_putlist(map);
	ft_linker(&(map->next), &save);
//	ft_display_link(map);
	return (0);
}
