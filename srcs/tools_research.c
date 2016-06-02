/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_research.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:53:25 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/26 16:52:08 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_adj(t_chain *way, t_chain *network)
{
	int	i;

	i = -1;
	while (++i < way->data->nb_malloc)
		if (way->data->link[i] == network->data)
			return (1);
	return (0);
}

void			ft_chain_push_front(t_chain **begin, t_chain *new)
{
	if (!(*begin))
		*begin = new;
	else
	{
		new->chain = *begin;
		*begin = new;
	}
}

int				exclude_comment(char *str)
{
	if (ft_isnumber(str))
		return (0);
	if (str[0] == '#')
	{
		if ((ft_strequ(str, "##start") || ft_strequ(str, "##end")))
			return (1);
		else
			return (0);
	}
	else
		return (1);
}

int				test_possible(char *map, int *ants, int *piece)
{
	if (!*map)
		return (1);
	else if (map[0] == '#')
		return (0);
	else if (map[0] == 'L')
		return (1);
	else if (*ants == 1)
	{
		if (map_or_link(map, piece))
			return (1);
	}
	else if (nb_of_ant(map, ants))
		return (1);
	return (0);
}

void			null_var(t_list **map, t_room **room, t_chain **network,
		t_list **copy)
{
	*map = NULL;
	*room = NULL;
	*network = NULL;
	*copy = NULL;
}
