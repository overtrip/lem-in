/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinden <jlinden@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 16:23:53 by jlinden           #+#    #+#             */
/*   Updated: 2013/12/01 19:00:56 by jlinden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*temp;
	t_list	*save;
	t_list	*save_current;

	save = NULL;
	current = lst;
	while (current)
	{
		if (!(temp = ft_lstnew(current->content, current->content_size)))
			return (NULL);
		temp = f(temp);
		if (!save)
		{
			save = temp;
			save_current = save;
		}
		else
		{
			save_current->next = temp;
			save_current = save_current->next;
		}
		current = current->next;
	}
	return (save);
}
