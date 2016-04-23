/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:20:22 by jealonso          #+#    #+#             */
/*   Updated: 2016/04/23 18:05:02 by jealonso         ###   ########.fr       */
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
		printf("(%ld)", way->len);
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

static void		ft_solver_deap(t_chain **network, t_chain **way,
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

/*void		ft_cmp_tube_n_map(t_room *map, int *nb_tube, int *nb_map)
{
	t_room *tube;

	tube = find_tube(map);
	while (map != tube)
	{
		if (((char *)(map->data))[0] != '#')
			++nb_map;
		map = map->next;
	}
	while (tube)
	{
		if (((char *)(map->data))[0] != '#')
			++nb_tube;
		tube = tube->next;
	}
}

void		ft_solver_width(t_chain **network, t_chain *way,
		t_room *start, t_room *end)
{
	return ;
}*/

t_chain			*ft_find_way(t_room *map)
{
	t_room	*start;
	t_room	*end;
	t_chain	*way;
	t_chain	*network;
//	int		nb_tube;
//	int		nb_map;

	way = NULL;
	network = NULL;
	start = NULL;
	end = NULL;
//	ft_cmp_tube_n_map(map, &nb_tube, &nb_map);
	start = find_start(map, 1);
	end = find_start(map, 2);
/*	if (nb_tube < (2 * nb_sommet))
		ft_solver_width(&network, &way, start, end);
	else*/
		ft_solver_deap(&network, &way, start, end);
	//ft_delete_way(&way);
	ft_see_way(network);
	return (network);
}
