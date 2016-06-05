/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 16:00:13 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/05 17:09:05 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	cmp_char(char *str, char c, int nb)
{
	int i;
	int	cmp;

	i = -1;
	cmp = 0;
	while (str[++i])
		if (str[i] == c)
			++cmp;
	if (cmp != nb)
		return (0);
	return (1);
}

int	cunter_ant_declaration(int *ants)
{
	if (*ants >= 1)
	{
		ft_putendl_fd("ERROR: Multiple declaration of ants", 2);
		return (1);
	}
	return (0);
}

int	map_or_link(char *map, int *piece)
{
	if (cmp_char(map, ' ', 2) && *piece == 0)
		return (0);
	if (cmp_char(map, '-', 1) && ++(*piece))
		return (0);
	else
		ft_putendl_fd("ERROR: String not valide.", 2);
	return (1);
}

int	nb_of_ant(char *map, int *ants)
{
	if (ft_isnumber(map))
	{
		if (cunter_ant_declaration(ants))
			return (1);
		if (ft_atoi(map) >= 1)
		{
			if ((*ants) == 0)
			{
				++(*ants);
				return (0);
			}
		}
	}
	ft_putendl_fd("ERROR: They are no ants", 2);
	return (1);
}
