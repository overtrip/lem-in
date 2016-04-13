/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinden <jlinden@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:23:31 by jlinden           #+#    #+#             */
/*   Updated: 2016/04/13 17:25:48 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst)
{
	t_list	*current;
	t_list	*save;

	if (alst)
	{
		current = *alst;
		while (current)
		{
			if (current->data)
				free(current->data);
			if (current->link)
				free(current->link);
			save = current;
			current = current->next;
			free(save);
		}
		*alst = NULL;
	}
}