/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:58:29 by jealonso          #+#    #+#             */
/*   Updated: 2016/02/10 18:38:52 by jealonso         ###   ########.fr       */
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

t_list	*ft_match(char *str, t_list **map)
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

int		ft_verif_size(t_list *room, int *nb)
{
	t_list	*save;
	int	i;
	int		flag;

	i = -1;
	flag = 0;
	save = room;
	if (!room->link)
		return (0);
	while (room->link[++i])
		if (i >= *nb)
			++flag;
	if (flag)
	{
		*nb = i;
		return (1);
	}
	room = save;
	return (0);
}

void	ft_resize(t_list **room, int nb)
{
	t_list	*save;
	t_list	*tmp;
	int		i;

	tmp = NULL;
	save = tmp;
	i = -1;
	if (!(tmp->link = (t_list **)malloc(sizeof(t_list *) * (nb + SIZE))))
		return ;
	while ((*room)->link[++i])
		tmp->link[i] = (*room)->link[i];
	(*room)->link = tmp->link;
}

void	ft_complete(t_list **room, char *control, t_list **save)
{
	int	i;

	i = -1;
	if (!(*room)->link)
		if(ft_pile_face((*map)->data, control->data) == 1)
			(*room)->link[0] = ft_match(ft_cut_str(control->data, '-'), save);
}

void	ft_linker(t_list **map, t_list **save)
{
	t_list	*control;
	t_list	*begin;
	int		flag;
	int		i;

	i = SIZE;
	flag = 2;
	begin = find_tube(*map);
	while (map && !ft_strequ((*map)->data, begin->data))
	{
		if (flag > 0 && ((char *)((*map)->data))[0] == '#')
			ft_config_room(map, &flag);
				control = begin;
		while (control)
		{
			if (ft_pile_face((*map)->data, control->data) > 0)
			{
				if (ft_verif_size(*map, &i))
					ft_resize((*map)->link, i);
				ft_complete((*map)->link, control->data, save);
				(*map)->link[i++] =
						(ft_pile_face((*map)->data, control->data) == 1)
						? ft_match(ft_cut_str(control->data, '-'), save)
						: ft_match(ft_begin_str(control->data ,'-'), save);
			}
				control = control->next;
		}
		i = 0;
		*map = (*map)->next;
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
//	ft_putlist(map);
	ft_display_link(map);
	ft_linker(&(map->next), &save);
	return (0);
}
