/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:20:22 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/11 18:02:45 by jealonso         ###   ########.fr       */
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

void		build_way(t_chain **network, t_chain *way, size_t len)
{
	size_t	nb;

	if (way)
		build_way(network, way->next, len);
	nb = len;
	if ()
	ft_chain_push_back(network, ft_create_chain(way));
}

void		ft_solver_width(t_chain **network, t_chain **way,
		t_room *start, t_room *end)
{
	int	i;
	int	distance;
	t_chain	*save;

	save = *way;
	distance = 1;
	ft_chain_push_back(way, ft_create_chain(start));
	start->presence = 1;
	way->len = distance;

	while (way && !network)
	{
		i = -1;
		++distance;
		while (++i < start->nb_malloc)
		{
			if (!start->link[i]->presence)
			{
				start->link[i]->presence = 1;
				way->len = distance;
				ft_chain_push_back(way, ft_create_chain(start->link[i]));
				if (start->link[i] == end)
				{
					build_way(network, way, way->len);
					break ;
				}
			}
		}
		*way = (*way)->chain;
	}
}

/*var room = room[0];
while (way != room[1])
{
	if (is_room_adjacent_to(room.adj, war->data) && cur_length == way->len + 1)
	{
		ajouter way to path;
		room = way->data;
		cur_length--;
	}
}
*/
//Voici l'algorithme :
//
//1) Je prend le premier nœud de la file d'attente des nœuds à traiter.
//2) Pour visiter ce nœud je le marque comme visité.
//3) Je prend chacun de ses voisins non visités et je les ajoute à la fin de la file d'attente des nœuds à visiter
//4) Je reprends le 1) tant qu'il reste des nœuds à traiter dans la file d'attente
//
//Procedure BFS(Graphe G, Noeud Origine)
//{
//	File aTraiter
//	Marquer N comme visite
//	aTraiter.enfiler(Origine)
//
//	Tant que aTraiter.nonVide()
//	{
//		Noeud N = aTraiter.defiler()
//
//		Pour chaque voisin V de N
//			Si V non visite
//				Marquer V comme visite
//				aTraiter.enfiler(V)
//	}
//}
//
//Procedure BFS(Graphe G, Noeud Origine)
//{
//	File aTraiter
//		profondeur[Origine] = 0
//		Marquer Origine comme visite
//		aTraiter.enfiler(Origine)
//
//		Tant que aTraiter.nonVide()
//		{
//			Noeud N = aTraiter.defiler()
//				Pour chaque voisin V de N
//				Si V non visite
//				profondeur[V] = profondeur[N] + 1
//				Marquer V comme visite
//				aTraiter.enfiler(V)
//		}
//}

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
