/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinden <jlinden@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 17:01:20 by jlinden           #+#    #+#             */
/*   Updated: 2014/02/15 17:10:38 by jlinden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*cursor;

	cursor = *alst;
	if (alst)
	{
		if (*alst && new)
		{
			while (cursor->next)
				cursor = cursor->next;
			cursor->next = new;
		}
		else
			*alst = new;
	}
}
