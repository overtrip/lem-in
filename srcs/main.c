/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:58:29 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/05 18:07:36 by jealonso         ###   ########.fr       */
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
		if (exclude_comment(((char *)(map->data))))
			ft_push_room_back(room, ft_create_room(&map, &alert));
		if (alert)
		{
			ft_putendl_fd("Problem detected", 2);
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
	t_list	*copy_map;
	t_room	*room;
	t_degeu	degeu;
	t_chain	*network;

	null_var(&map, &room, &network, &copy_map);
	ft_bzero(&degeu, sizeof(t_degeu));
	while (get_next_line(0, &degeu.buff) > 0)
	{
		if (!test_possible(degeu.buff, &degeu.ants, &degeu.piece))
			ft_get_map(&map, degeu.buff);
		else
			break ;
		free(degeu.buff);
	}
	if (degeu.buff)
		free(degeu.buff);
	if (!ft_error(map, &copy_map) && !ft_transfer(&room, copy_map))
		normal_execution(map, room, network);
	delete_all(&map, &room, &network, &copy_map);
	return (0);
}
