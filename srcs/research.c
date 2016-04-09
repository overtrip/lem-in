/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:20:22 by jealonso          #+#    #+#             */
/*   Updated: 2016/04/09 18:27:58 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**					TODO		DELETE THIS FUNCTION
*/

void	ft_see_way(t_chain *way)
{
	t_chain		*temp;

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

t_list	*find_start(t_list *map, char *str)
{
	while (map)
	{
		if (ft_strequ(map->data, str))
			return (map->next);
		map = map->next;
	}
	return (NULL);
}

t_list		*ft_see_link(t_list *map)
{
	int	i;

	i = -1;
	while (++i <= map->nb_malloc)
	{
		if (map->i == 0 && (map->i = 1))
			return (map->link[i]);
	}
	return (NULL);
}

void	ft_chain_pop_back(t_chain **way)
{
	t_chain		*temp;

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

void	ft_solver(t_list *room, t_list *end, t_chain **way, t_chain **network)
{
	int	i;

	i = -1;
	ft_chain_push_back(way, ft_create_chain(room));
	room->i = 1;
	(*way)->len += 1;
	if (room == end)
		ft_new_way(network, *way);
	else
	{
		while (++i < room->nb_malloc)
		{
			if (room->link[i] && !room->link[i]->i)
				ft_solver(room->link[i], end, way, network);
		}
	}
	(*way)->len -= 1;
	room->i = 0;
	ft_chain_pop_back(way);
}

void	ft_find_way(t_list *map)
{
	t_list	*start;
	t_list	*end;
	t_chain	*way;
	t_chain	*network;

	way = NULL;
	network = NULL;
	start = find_start(map, "##start");
	end = find_start(map, "##end");
	ft_solver(start, end, &way, &network);
	//printf("[%p]\n",network);
	ft_see_way(network);
}
