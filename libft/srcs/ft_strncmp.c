/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinden <jlinden@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:27:40 by jlinden           #+#    #+#             */
/*   Updated: 2013/12/01 19:40:11 by jlinden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*s1ptr;
	const unsigned char	*s2ptr;

	s1ptr = (const unsigned char *)s1;
	s2ptr = (const unsigned char *)s2;
	while (n--)
	{
		if (!*s1ptr || (*s1ptr != *s2ptr))
			return (*s1ptr - *s2ptr);
		s1ptr++;
		s2ptr++;
	}
	return (0);
}
