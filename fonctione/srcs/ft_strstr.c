/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinden <jlinden@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:50:25 by jlinden           #+#    #+#             */
/*   Updated: 2013/12/01 19:39:33 by jlinden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	length;
	char	*ptr;

	length = ft_strlen(s2);
	ptr = (char *)s1;
	while (*ptr)
	{
		if (ft_memcmp(ptr, s2, length) == 0)
			return (ptr);
		ptr++;
	}
	if (!*s1 && !*s2)
		return (ptr);
	return (0);
}
