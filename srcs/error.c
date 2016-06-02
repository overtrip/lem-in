/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 18:36:15 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/31 17:03:50 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_name(t_list *map, int *alert)
{
	int start;
	int	end;

	start = 0;
	end = 0;
	while (map)
	{
		if (ft_limit(&start, map->data, "##start") ||
				ft_limit(&end, map->data, "##end"))
		{
			++(*alert);
			return ;
		}
		else if (((char *)(map->data))[0] == 'L' && ++(*alert))
		{
			ft_putendl_fd("Room name begin by a 'L'", 2);
			return ;
		}
		map = map->next;
	}
	if (!(start && end))
		ft_putmsg(start, alert);
}

static int	ft_check_link(t_list *control, t_list *map, int *find)
{
	char	*tmp;

	tmp = ft_begin_str(map->data, ' ');
	if (!(((char *)(control->data))[0] == '#'))
	{
		if (ft_pile_face(tmp, control->data) && (++(*find)))
		{
			free(tmp);
			return (1);
		}
	}
	free(tmp);
	return (0);
}

static void	ft_link(t_list *map, int *alert)
{
	t_list	*tube;
	t_list	*control;
	t_list	*begin;
	int		find;

	tube = find_tube(map);
	begin = map;
	while (map != tube)
	{
		find = 0;
		control = tube;
		if (!(((char *)(map->data))[0] == '#') && !ft_isnumber(map->data))
		{
			while (control)
			{
				if (ft_check_link(control, map, &find))
					break ;
				control = control->next;
			}
			if (!find)
				break ;
		}
		map = map->next;
	}
	ft_print_error(find, alert, map->data, begin);
}

int			ft_error(t_list *map, t_list **copy)
{
	int		alert;
	t_list	*begin;

	alert = 0;
	begin = map;
	if (!map)
	{
		ft_putendl_fd("They are not map", 2);
		return (++alert);
	}
	else
	{
		while (begin)
		{
			if (exclude_comment(begin->data))
				ft_list_push_back(copy, ft_create_elem(begin->data));
			begin = begin->next;
		}
		ft_name(map, &alert);
	}
	if (!alert)
		ft_link(*copy, &alert);
	return (alert);
}
