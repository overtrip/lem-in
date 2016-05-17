/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:20:22 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/17 18:29:21 by jealonso         ###   ########.fr       */
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

static void			ft_delete_way(t_chain **way)
{
	t_chain	*tmp;

	while (*way)
	{
		tmp = (*way);
		free((*way)->chain);
		(*way) = (*way)->next;
		free(tmp);
	}
	*way = NULL;
}

static void		ft_chain_pop_back(t_chain **way)
{
	t_chain	*temp;

	temp = *way;
	if (!*way)
		return ;
	else if (!temp->chain)
		ft_delete_way(way);
	else
	{
		while (temp->chain->chain)
			temp = temp->chain;
		free(temp->chain);
		temp->chain = NULL;
	}
}

void		ft_solver_deap(t_chain **network, t_chain **way,
		t_room *room, t_room *end)
{
	int	i;

	i = -1;
	ft_chain_push_back(way, ft_create_chain(room));
	room->presence = 1;
	(*way)->len += 1;
	if (room == end)
		ft_new_way(network, *way);
	else
	{
		while (++i < room->nb_malloc)
		{
			if (room->link[i] && !room->link[i]->presence)
				ft_solver_deap(network, way, room->link[i], end);
		}
	}
	(*way)->len -= 1;
	room->presence = 0;
	ft_chain_pop_back(way);
}

t_room		*find_lightweight(t_room *room)
{
	int		i;
	int		j;

	i = -1;
	while (room->link[++i] && room->link [i + 1] && i < room->nb_malloc)
	{
		j = (i + 1);
		while (room->link[j] && j < room->nb_malloc)
		{
			printf("--[%s]--\n", room->data);
			//			printf("[%d]\t[%d]\n", link[i]->presence, link[j]->presence);
			if (room->link[j]->presence <= room->link[i]->presence)
				return (room->link[j]);
			++j;
		}
	}
	return (room->link[i]);
}

int			ft_adj(t_chain *way, t_chain *network)
{
	int	i;

	i = -1;
	while (++i < way->data->nb_malloc)
		if (way->data == network->data)
			return (1);
	return (0);
}

void		ft_chain_push_front(t_chain	**begin, t_chain *new)
{
	if (!(*begin))
		*begin = new;
	else
	{
		new->next = *begin;
		*begin = new;
	}
}
void		build_way(t_chain **network, t_chain *way)
{
	ft_see_way(way);
	if (way)
	{
		printf("--%s--%d\n", way->chain->data->data, way->data->presence);
		build_way(network, way->chain);
	}
	if (*network)
	{
		if ((way->data->presence == ((*network)->len - 1)) && ft_adj(way, *network))
		{
			ft_chain_push_front(network, way);
			(*network)->len -= 1;
		}
	}
	else if (way && !(way->chain))
	{
		ft_chain_push_front(network, way);
		printf("[%s]\t[%d]\n", (*network)->data->data, way->data->presence);
		(*network)->len = way->data->presence;
	}
}

void		ft_solver_width(t_chain **network, t_chain **way,
		t_room *start, t_room *end)
{
	int	i;
	int	distance;
	t_chain	*save;

	distance = 1;
	ft_chain_push_back(way, ft_create_chain(start));
	save = *way;
	start->presence = 1;
	(*way)->len = distance;
	while ((*way)->data != end)
	{
		i = -1;
		++distance;
		while (++i < start->nb_malloc)
		{
			if (start->link[i] && !(start->link[i]->presence))
			{
				start->link[i]->presence = distance;
				//(*way)->len = distance;
				ft_chain_push_back(way, ft_create_chain(start->link[i]));
				if (start->link[i] == end)
				{
					build_way(network, save);
					return ;
				}
			}
		}
		start = (*way)->data;
		*way = (*way)->chain;
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
	//	ft_solver_deap(&network, &way, start, end);
	//ft_delete_way(&way);
	ft_see_way(network);
	return (network);
}
