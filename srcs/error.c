/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 18:36:15 by jealonso          #+#    #+#             */
/*   Updated: 2016/04/14 18:36:21 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_limit(int *limit, char *str, char *str2)
{
	if (ft_strequ(str, str2))
		++(*limit);
	if (*limit > 1)
	{
		ft_putstr("Multiple ");
		ft_putendl(str2);
		return (1);
	}
	return (0);
}

static int		ft_check_ant(int *alert, char *ant)
{
	if (!ft_isnumber(ant))
	{
		ft_putendl("They are no ants");
		++(*alert);
		return (1);
	}
	return (0);
}

static void	ft_putmsg(int start)
{
	if (!start)
		ft_putendl("They are no ##start");
	else
		ft_putendl("They are no ##end");
}

static void	ft_name(t_list *map, int *alert)
{
	int start;
	int	end;

	start = 0;
	end = 0;
	if (!ft_check_ant(alert, map->data))
	{
		while (map)
		{
			if (ft_limit(&start, map->data, "##start") ||
					ft_limit(&end, map->data, "##end"))
			{
				++(*alert);
				break ;
			}
			if (((char *)(map->data))[0] == 'L' && (++alert))
				ft_putendl("Room name begin by a 'L'");
			map = map->next;
		}
		if (!(start && end))
			ft_putmsg(start);
	}
}

static void	ft_link(t_list *map, int *alert)
{
	t_list	*tube;
	t_list	*control;
	int		find;

	tube = find_tube(map);
	while (map != tube)
	{
		find = 0;
		control = map;
		while (control)
		{
			if (ft_pile_face(map->data, control->data) && ++find)
				break ;
			control = control->next;
		}
		if (!find)
			break ;
		map = map->next;
	}
	if (!find)
		++(*alert);
}

int		ft_error(t_list **map)
{
	int	alert;

	alert = 0;
	ft_name(*map, &alert);
	ft_link(*map, &alert);
	return (alert);
}
