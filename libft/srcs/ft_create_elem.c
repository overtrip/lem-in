/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:31:50 by jealonso          #+#    #+#             */
/*   Updated: 2016/02/25 17:31:29 by jealonso         ###   ########.fr       */
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
		return (NULL);
	new->nb_malloc = 5;
	while (i <= 5)
		new->link[i++] = NULL;
	new->i = 0;
	new->presence = 0;
	return (new);
}
