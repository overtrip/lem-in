/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:58:29 by jealonso          #+#    #+#             */
/*   Updated: 2016/02/04 17:00:40 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static void	ft_get_map(t_list **map, char *buff)
{
	if (!buff)
		return ;
	ft_list_push_back(map, ft_create_elem(buff));
}

/*static void	ft_linker(t_list **map)
{
	t_list	*control;
	t_list	*begin;

	begin = find_tube(*map);
	while (map && !ft_strequ((*map)->data, begin->data))
	{
		if (ft_strequ((*map)->data, "##start"))
		{
			*map = (*map)->next;
			(*map)->i = 1;
		}
		if (ft_strequ((*map)->data, "##end"))
			(*map)->i = 2;
		control = begin;
		while (control)
		{
			if (ft_pile_face((*map)->data, control->data))
				control = control->next;
		}
		*map = (*map)->next;
	}
}*/

static void	free_all(t_list *map)
{
	free(map->data);
	/*while (map->link)
	{
		free(*map->link);
		++(map->link);
	}
	free(map->link);*/
	free(map);
}

static void	ft_del_one(t_list **map)
{
	t_list *tmp;

	if (((char *)((*map)->next->data))[1] != '#')
	{
		//	ft_putendl((*map)->next->data);
		tmp = (*map)->next;
		(*map) = (*map)->next->next;
		free_all(tmp);
	}
}

static void	ft_del_comment(t_list **map)
{
	t_list	*save;

	save = *map;
	while ((*map)->next)
	{
		//ft_putendl((*map)->data);
		if (((char *)((*map)->next->data))[0] == '#')
			ft_del_one(map);
		//ft_putendl((*map)->data);
		*map = (*map)->next;
	}
	*map = save;
}

int			main(void)
{
	t_list	*map;
	char	*buff;

	buff = NULL;
	map = NULL;
	while (get_next_line(0, &buff) > 0)
	{
		ft_get_map(&map, buff);
	}
	ft_error(map);
	ft_del_comment(&map);
	ft_putlist(map);
	//ft_linker(&(map->next));
	return (0);
}
