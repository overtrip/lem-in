/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinden <jlinden@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:26:11 by jlinden           #+#    #+#             */
/*   Updated: 2013/12/01 19:36:03 by jlinden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*saveptr1;
	const char	*saveptr2;

	saveptr1 = (char *)s1;
	saveptr2 = (const char *)s2;
	if (saveptr1 <= saveptr2)
		ft_memcpy(s1, s2, n);
	else
	{
		saveptr1 += n - 1;
		saveptr2 += n - 1;
		while (n--)
		{
			*saveptr1 = *saveptr2;
			saveptr1--;
			saveptr2--;
		}
	}
	return (s1);
}
