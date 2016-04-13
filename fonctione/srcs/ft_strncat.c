/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinden <jlinden@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:11:35 by jlinden           #+#    #+#             */
/*   Updated: 2013/12/01 14:15:38 by jlinden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int				s1_size;
	unsigned int	i;

	s1_size = ft_strlen(s1);
	i = 0;
	while (s2[i] && (i < n))
	{
		s1[s1_size + i] = s2[i];
		i++;
	}
	s1[s1_size + i] = '\0';
	return (s1);
}
