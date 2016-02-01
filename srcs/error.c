/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:04:41 by jealonso          #+#    #+#             */
/*   Updated: 2016/02/01 16:08:22 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void		ft_prerequis(t_list *map)
{
	int	flag;
	int	secu;

	flag = 0;
	secu = 0;
	while (map)
	{
		if (ft_strstr(map->data, "##start") && ++secu && flag == 0)
			++flag;
		if (ft_strstr(map->data, "##end") && ++secu && flag == 1)
			++flag;
		map = map->next;
	}
	if (flag == 0)
		ft_putendl("Pas de start et/ou end");
	else if (flag == 1)
		ft_putendl("Pas de end");
	else if (secu > 2)
		ft_putendl("multiples start et/ou end");
}

void	ft_error(t_list *map)
{
	if (!ft_isnumber(map->data))
		ft_putendl("pas de fourmis");
	ft_prerequis(map);
}
