/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:04:41 by jealonso          #+#    #+#             */
/*   Updated: 2016/04/12 16:47:54 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_check_name(char *str)
{
	if (*str == 'L')
	{
		ft_putendl("Name room begin by a \'L\'");
		exit(0);
	}
}

static void		ft_prerequis(t_list *map)
{
	int	flag;
	int	secu;

	flag = 0;
	secu = 0;
	while (map)
	{
		if (ft_strequ(map->data, "##start") && ++secu && flag == 0)
			++flag;
		if (ft_strequ(map->data, "##end") && ++secu && flag == 1)
			++flag;
		ft_check_name(map->data);
		map = map->next;
	}
	if (flag == 0)
		ft_putendl("Pas de start et/ou end");
	else if (flag == 1)
		ft_putendl("Pas de end");
	else if (secu > 2)
		ft_putendl("multiples start et/ou end");
}

static void		ft_tube(t_list *map)
{
	t_list	*control;
	t_list	*begin;
	int		find;

	begin = find_tube(map);
	while (map && !ft_strequ(map->data, begin->data))
	{
		find = 0;
		if (((char *)(map->data))[0] == '#' && map->next)
			map = map->next;
		control = begin;
		while (control)
		{
			if (ft_pile_face(map->data, control->data) && ++find)
				break ;
			control = control->next;
		}
		if (find == 0 && ft_putendl("room not linked"))
			break ;
		map = map->next;
	}
}

void			ft_error(t_list *map)
{
	if (!ft_isnumber(map->data))
		ft_putendl("pas de fourmis");
	ft_prerequis(map);
	ft_tube(map->next);
}
