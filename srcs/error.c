/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:04:41 by jealonso          #+#    #+#             */
/*   Updated: 2016/02/05 14:22:37 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_prerequis(t_list *map)
{
	int	flag;
	int	secu;
	int	l_name;

	flag = 0;
	secu = 0;
	l_name = 0;
	while (map)
	{
		if (ft_strstr(map->data, "##start") && ++secu && flag == 0)
			++flag;
		if (ft_strstr(map->data, "##end") && ++secu && flag == 1)
			++flag;
		if (((char *)(map->data))[0] == 'L')
			l_name = 1;
		map = map->next;
	}
	if (flag == 0)
		ft_putendl("Pas de start et/ou end");
	else if (flag == 1)
		ft_putendl("Pas de end");
	else if (secu > 2)
		ft_putendl("multiples start et/ou end");
	if (l_name == 1)
		ft_putendl("Name room beagin to \'L\'");
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
