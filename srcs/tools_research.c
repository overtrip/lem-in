/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_research.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:53:25 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/18 17:41:41 by jealonso         ###   ########.fr       */
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
