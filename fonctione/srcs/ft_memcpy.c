/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinden <jlinden@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:48:07 by jlinden           #+#    #+#             */
/*   Updated: 2013/12/01 19:35:32 by jlinden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*s1ptr;
	const char	*s2ptr;

	s1ptr = (char *)s1;
	s2ptr = (const char *)s2;
	while (n--)
	{
		*s1ptr = *s2ptr;
		s1ptr++;
		s2ptr++;
	}
	return (s1);
}
