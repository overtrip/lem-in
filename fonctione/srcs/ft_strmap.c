/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinden <jlinden@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:06:04 by jlinden           #+#    #+#             */
/*   Updated: 2013/11/27 11:50:42 by jlinden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result_str;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	result_str = ft_strnew(ft_strlen(s) + 1);
	if (result_str)
	{
		while (s[i])
		{
			result_str[i] = f(s[i]);
			i++;
		}
	}
	return (result_str);
}
