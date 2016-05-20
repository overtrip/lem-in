/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:52:05 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 15:56:08 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_all(t_list **map, t_room **room, t_chain **network)
{
	ft_lstdel(map);
	ft_delete_room(room);
	ft_delet_network(network);
}
