/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinden <jlinden@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:40:57 by jlinden           #+#    #+#             */
/*   Updated: 2013/12/01 19:42:10 by jlinden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char			*memory;
	unsigned int	i;

	memory = (char *)malloc(size);
	if (memory)
	{
		i = 0;
		while (i < size)
		{
			memory[i] = 0;
			i++;
		}
	}
	else
		memory = NULL;
	return (memory);
}
