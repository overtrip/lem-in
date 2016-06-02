/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:20:22 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/25 17:10:07 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*find_start(t_room *map, int nb)
{
	while (map)
	{
		if (map->s_e == nb)
			return (map);
		map = map->next;
	}
	return (NULL);
}

static int		build_way(t_chain **network, t_chain *way)
{
	if (way)
		build_way(network, way->chain);
	if (*network)
	{
		if (ft_adj(way, *network) &&
				(way->data->presence == ((*network)->len - 1)))
		{
			ft_chain_push_front(network, way);
			(*network)->len = way->data->presence;
			way->data->presence = 0;
		}
	}
	else if (way && !(way->chain))
	{
		ft_chain_push_front(network, way);
		(*network)->len = way->data->presence;
		way->data->presence = 0;
	}
	return (1);
}

int				its_impossible(t_chain *way)
{
	if (way)
		if (!way->chain)
		{
			ft_putendl_fd("It's impossible, they are no way.", 2);
			return (1);
		}
	return (0);
}

static int		ft_solver_width(t_chain **network, t_chain **way,
		t_room *start, t_room *end)
{
	int		i;
	t_chain	*save;

	start->presence = 1;
	ft_chain_push_back(way, ft_create_chain(start));
	save = *way;
	while ((*way)->data != end)
	{
		i = -1;
		while (++i < start->nb_malloc)
		{
			if (start->link[i] && !(start->link[i]->presence))
			{
				start->link[i]->presence = (*way)->data->presence + 1;
				ft_chain_push_back(way, ft_create_chain(start->link[i]));
				if (start->link[i] == end && build_way(network, save))
					return (0);
			}
		}
		if (its_impossible(*way))
			return (1);
		*way = (*way)->chain;
		start = (*way)->data;
	}
	return (0);
}

t_chain			*ft_find_way(t_room *map)
{
	t_room	*start;
	t_room	*end;
	t_chain	*way;
	t_chain	*network;

	way = NULL;
	network = NULL;
	start = NULL;
	end = NULL;
	start = find_start(map, 1);
	end = find_start(map, 2);
	if (ft_solver_width(&network, &way, start, end))
		return (NULL);
	return (network);
}
