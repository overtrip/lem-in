/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:20:22 by jealonso          #+#    #+#             */
/*   Updated: 2016/04/20 17:26:21 by jealonso         ###   ########.fr       */
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

static void		ft_chain_pop_back(t_chain **way)
{
	t_chain	*temp;

	temp = *way;
	if (!*way)
		return ;
	else if (!temp->chain)
	{
		free(*way);
		*way = NULL;
	}
	else
	{
		while (temp->chain->chain)
			temp = temp->chain;
		free(temp->chain);
		temp->chain = NULL;
	}
}

static void		ft_solver(t_room *room, t_room *end,
		t_chain **way, t_chain **network)
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
				ft_solver(room->link[i], end, way, network);
		}
	}
	(*way)->len -= 1;
	room->presence = 0;
	ft_chain_pop_back(way);
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
	ft_solver(start, end, &way, &network);
//	ft_see_way(network);
	return (way);
}

void	ft_delet_network(t_chain **network)
{
	t_chain	*current;
	t_chain	*save;
	t_chain	*save_intern;

	if (network)
	{
		current = *network;
		while (current)
		{
			if (current->chain)
			{
				while (current->chain)
				{
					if (current->chain->data)
						free(current->chain->data);
					save_intern = current->chain;
					current->chain = current->chain->next;
					free(save_intern);
				}
				free(current->chain);
			}
			if (current->data)
				free(current->data);
			save = current;
			current = current->next;
			free(save);
		}
		*network = NULL;
	}
}
