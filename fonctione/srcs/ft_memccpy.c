/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinden <jlinden@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:48:07 by jlinden           #+#    #+#             */
/*   Updated: 2013/12/01 19:35:49 by jlinden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		*s1ptr;
	const unsigned char	*s2ptr;

	s1ptr = (unsigned char *)s1;
	s2ptr = (const unsigned char *)s2;
	while (n--)
	{
		*s1ptr = *s2ptr;
		s1ptr++;
		if (*s2ptr == (unsigned char)c)
			return (s1ptr);
		s2ptr++;
	}
	return (NULL);
}
