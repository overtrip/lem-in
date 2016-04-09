/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 16:26:00 by jealonso          #+#    #+#             */
/*   Updated: 2016/04/09 18:12:18 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_new_way(t_chain **network, t_chain *old)
{
	t_chain	*new;

	new = NULL;
	while (old->chain)
	{
		ft_chain_push_back(&new, ft_create_chain(old->data));
		old = old->chain;
	}
	new->next = *network;
	*network = new;
}

t_chain	*ft_create_chain(t_list *map)
{
	t_chain	*new;

	if (!(new = (t_chain *)malloc(sizeof(t_chain))))
		return (NULL);
	else
	{
		new->len = 0;
		new->chain = NULL;
		new->next = NULL;
		new->data = map;
	}
	return (new);
}

void	ft_chain_push_back(t_chain **begin, t_chain *new)
{
	t_chain	*save;

	save = *begin;
	if (!save)
		*begin = new;
	else
	{
		while (save->chain)
			save = save->chain;
		save->chain = new;
	}
}