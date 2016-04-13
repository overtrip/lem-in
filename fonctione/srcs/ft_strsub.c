/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinden <jlinden@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:42:59 by jlinden           #+#    #+#             */
/*   Updated: 2013/12/01 19:43:52 by jlinden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s)
		return (NULL);
	result = (char *)malloc(sizeof(result) * (len + 1));
	if (result)
	{
		ft_memcpy(result, s + start, len);
		result[len] = '\0';
	}
	return (result);
}
