/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelmatch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinden <jlinden@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 19:15:09 by jlinden           #+#    #+#             */
/*   Updated: 2014/02/16 13:00:20 by jlinden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstdelmatch(t_list **alst, void *data, int (*cmp)(void*, void*))
{
	t_list	*ret;

	if (!*alst)
		return (NULL);
	ret = ft_lstdelmatch(&((*alst)->next), data, cmp);
	if (cmp((*alst)->content, data))
	{
		free((*alst)->content);
		free(*alst);
		*alst = ret;
		return (ret);
	}
	else
	{
		(*alst)->next = ret;
		return (*alst);
	}
}
