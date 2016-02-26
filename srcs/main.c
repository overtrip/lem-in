/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:58:29 by jealonso          #+#    #+#             */
/*   Updated: 2016/02/26 18:13:03 by jealonso         ###   ########.fr       */
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

void		ft_display_link(t_list *map)
{
	while (map)
	{
		printf("[%p](map)       [%s](map->data)        [%p](map->link)\n",
				map, ft_begin_str(map->data, ' '), map->link);
		map = map->next;
	}
}

t_list		*ft_val(char *str, t_list **map)
{
	t_list	*begin;
	t_list	*tube;

	begin = *map;
	tube  = find_tube(*map);
	while (map)
	{
		if (ft_strequ(ft_begin_str((*map)->data, ' '), str))
		{
			*map = begin;
			return (*map);
		}
		*map = (*map)->next;
	}
	*map = begin;
	return (begin);
}

t_list		*ft_realloc_room(t_list **map)
{
	t_list	*tmp;
	t_list	*begin;
	int		nb;

	nb = -1;
	if(!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(tmp->link = (t_list **)malloc(sizeof(t_list *) *
					((*map)->nb_malloc + 5))))
		return (NULL);
	(*map)->nb_malloc = ((*map)->nb_malloc) + 5;
	begin = *tmp->link;
	while (tmp->link)
	{
		if ((*map)->link)
		{
			tmp->link = (*map)->link;
			++(*map)->link;
		}
		else
			tmp->link = NULL;
		++tmp->link;
	}
	*tmp->link = begin;
	return (*tmp->link);
}

void		ft_check_malloc(t_list ** map)
{
	int		nb;
	int		i;
	t_list	*save;

	nb = -1;
	i = -1;
	save = *map;
	while (++i < (*map)->nb_malloc && (*map)->link[i])
		++nb;
	if (nb >= (*map)->nb_malloc)
		*(*map)->link = ft_realloc_room(save->link);
}

void		ft_add_room(t_list **map, t_list **room)
{
	t_list	*save;
	int		i;

	i = 0;
	save = *(*map)->link;
	ft_check_malloc(map);
	while (i < (*map)->nb_malloc && (*map)->link[i])
		++i;
	(*map)->link = room;

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
			ft_add_room(map, &tmp);
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
	ft_display_link(*map);
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
//	ft_putlist(map);
	ft_linker(&(map->next), &save);
//	ft_display_link(map);
	return (0);
}
