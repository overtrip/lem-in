/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:44:45 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 15:30:45 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
		return (ft_strdup(++ptr));
	else
		return (ptr);
}

t_list	*find_tube(t_list *map)
{
	t_list	*begin_tube;

	begin_tube = NULL;
	while (map)
	{
		if ((ft_strchr(map->data, '-')))
		{
			begin_tube = map;
			break ;
		}
		map = map->next;
	}
	return (begin_tube);
}

void	ft_clean(char *begin, char *droite, char *gauche)
{
	free(begin);
	free(droite);
	free(gauche);
}

void	ft_push_room_back(t_room **map, t_room *new)
{
	t_room	*begin;

	begin = *map;
	if (*map)
	{
		while (begin->next)
			begin = begin->next;
		begin->next = new;
	}
	else
		*map = new;
}
