/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinden <jlinden@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:06:04 by jlinden           #+#    #+#             */
/*   Updated: 2013/11/27 11:51:40 by jlinden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result_str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	result_str = ft_strnew(ft_strlen(s) + 1);
	if (result_str)
	{
		while (s[i])
		{
			result_str[i] = f(i, s[i]);
			i++;
		}
	}
	return (result_str);
}
