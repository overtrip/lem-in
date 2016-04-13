/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinden <jlinden@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:54:27 by jlinden           #+#    #+#             */
/*   Updated: 2013/12/01 19:36:37 by jlinden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1ptr;
	const unsigned char	*s2ptr;

	s1ptr = (const unsigned char *)s1;
	s2ptr = (const unsigned char *)s2;
	while (n--)
	{
		if (*s1ptr != *s2ptr)
			return (*s1ptr - *s2ptr);
		s1ptr++;
		s2ptr++;
	}
	return (0);
}
