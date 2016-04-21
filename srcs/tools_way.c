/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 16:26:00 by jealonso          #+#    #+#             */
/*   Updated: 2016/04/21 17:44:12 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_sort_chain(t_chain **network, t_chain *new)
{
	t_chain	*tmp;
	t_chain	*save;

	tmp = *network;
	save = *network;
	if (!save || new->len <= save->len)
	{
		new->next = *network;
		*network = new;
	}
	else
	{
		while (save && new->len > save->len)
		{
			tmp = save;
			save = save->next;
		}
		if (!save)
			tmp->next = new;
		else
		{
			tmp->next = new;
			new->next = save;
		}
	}
}

void	ft_new_way(t_chain **network, t_chain *old)
{
	t_chain	*new;
	t_chain	*temp;

	new = NULL;
	while (old)
	{
		temp = ft_create_chain(old->data);
		temp->len = old->len;
		ft_chain_push_back(&new, temp);
		old = old->chain;
	}
	ft_sort_chain(network, new);
}

t_chain	*ft_create_chain(t_room *map)
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

void	ft_delet_network(t_chain **network)
{
	t_chain	*current;
	t_chain	*save;
//	t_chain	*save_intern;

	if (network)
	{
		current = *network;
		while (current)
		{
			if (current->chain)
			{
/*				while (current->chain)
				{
					if (current->chain->data)
						free(current->chain->data);
					save_intern = current->chain;
					current->chain = current->chain->next;
					free(save_intern);
				}*/
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
