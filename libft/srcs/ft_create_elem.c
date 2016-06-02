/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:31:50 by jealonso          #+#    #+#             */
/*   Updated: 2016/04/13 17:18:11 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_elem(char *data)
{
	t_list	*new;
	int		i;

	i = 0;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->data = ft_strdup(data);
	new->next = NULL;
	if (!(new->link = (t_list **)malloc(sizeof(t_list *) * 5)))
	{
		free(new);
		return (NULL);
	}
	new->nb_malloc = 5;
	while (i < new->nb_malloc)
		new->link[i++] = NULL;
	new->i = 0;
	new->presence = 0;
	return (new);
}
