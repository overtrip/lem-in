/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:20:22 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/18 17:42:26 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 **					TODO		DELETE THIS FUNCTION
 */

void			ft_see_way(t_chain *way)
{
	t_chain	*temp;

	while (way)
	{
		temp = way;
		printf("(%d)", way->len);
		while (temp)
		{
			printf("[%s]->", temp->data->data);
			temp = temp->chain;
		}
		printf("\n");
		way = way->next;
	}
}

static t_room	*find_start(t_room *map, int nb)
{
	while (map)
	{
		if (map->s_e == nb)
			return (map);
		map = map->next;
	}
	return (NULL);
}

static void		build_way(t_chain **network, t_chain *way)
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
}

static void		ft_solver_width(t_chain **network, t_chain **way,
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
				if (start->link[i] == end)
				{
					build_way(network, save);
					return ;
				}
			}
		}
		*way = (*way)->chain;
		start = (*way)->data;
	}
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
	ft_solver_width(&network, &way, start, end);
//	ft_delete_way(&way);
//	ft_see_way(network);
	return (network);
}
