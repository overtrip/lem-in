/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:44:45 by jealonso          #+#    #+#             */
/*   Updated: 2016/02/03 17:52:05 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

char	*ft_begin_str(char *str, char c)
{
	char	*begin;
	int		size;

	begin = str;
	if (!str)
		return (begin);
	str = ft_strchr(str, c);
	size = (str) ? str - begin : ft_strlen(begin);
	return (ft_strndup(begin, size));
}

char	*ft_cut_str(char *str, char c)
{
	char	*ptr;

	ptr = NULL;
	if (str)
		ptr = ft_strchr(str, c);
	if (ptr)
		return (++ptr);
	else
		return (ptr);
}

t_list	*find_tube(t_list *map)
{
	t_list	*begin_tube;

	begin_tube = NULL;
	while (map)
	{
//TODO creer une nouvelle liste sans commentaires
		if (ft_strchr(map->data, '-'))
		{
			begin_tube = map;
			break ;
		}
		map = map->next;
	}
	return (begin_tube);
}

int		ft_pile_face(char *str1, char *str2)
{
	char	*begin;
	char	*pile;
	char	*face;

	begin = ft_begin_str(str1, ' ');
	pile = ft_cut_str(str2, '-');
	face = ft_begin_str(str2, '-');
	if (ft_strequ(begin, pile) || ft_strequ(begin, face))
		return (1);
	return (0);
}
