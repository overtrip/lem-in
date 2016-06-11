/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:16:22 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/11 16:09:23 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		print_stats(t_chain *network)
{
	if (network->chain)
		while (network->chain)
		{
			network = network->chain;
			if (network->data->presence)
				print_ant(network);
		}
	ft_putchar('\n');
}

static void		one_step(t_chain *network)
{
	if (network->chain)
		one_step(network->chain);
	if (network->data->presence)
	{
		network->chain->data->presence = network->data->presence;
		network->data->presence = 0;
	}
}

int				complet_empty(t_chain *network)
{
	while (network)
	{
		if (network->data->presence)
			return (1);
		network = network->chain;
	}
	return (0);
}

void			ft_resolver(t_chain **network, int nb_ants, t_room *map)
{
	int		ants;
	t_room	*end;

	ants = 1;
	end = find_start(map, 2);
	while (ants <= nb_ants)
	{
		if (its_impossible(*network))
			return ;
		one_step(*network);
		if (!((*network)->data->presence))
			(*network)->data->presence = ants;
		print_stats(*network);
		if (end->presence)
			end->presence = 0;
		++ants;
	}
	while (complet_empty(*network))
	{
		if (end->presence)
			end->presence = 0;
		one_step(*network);
		print_stats(*network);
	}
}

void			null_var(t_list **map, t_room **room, t_chain **network,
		t_list **copy)
{
	*map = NULL;
	*room = NULL;
	*network = NULL;
	*copy = NULL;
}
