/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:52:05 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/24 18:42:27 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_all(t_list **map, t_room **room, t_chain **network, t_list **cp)
{
	if (map)
		ft_lstdel(map);
	if (room)
		ft_delete_room(room);
	if (network)
		ft_delet_network(network);
	if (cp)
		ft_lstdel(cp);
}
