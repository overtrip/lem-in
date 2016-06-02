/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_normaly.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:05:11 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/31 16:54:58 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	normal_execution(t_list *map, t_room *room, t_chain *network)
{
	t_list *begin;

	begin = map;
	network = ft_find_way(room);
	if (network)
	{
		while (!ft_isnumber(begin->data))
			begin = begin->next;
		ft_putlist(map);
		ft_putchar('\n');
		ft_resolver(&network, ft_atoi(begin->data), room);
	}
}
