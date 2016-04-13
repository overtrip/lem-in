/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinden <jlinden@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:53:12 by jlinden           #+#    #+#             */
/*   Updated: 2016/04/13 16:10:25 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	str = (char *)malloc(sizeof(s1) * (s1_len + 1));
	if (str)
	{
		str = ft_strcpy(str, s1);
		str[s1_len] = '\0';
	}
	else
		str = NULL;
	return (str);
}
