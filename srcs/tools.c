/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:44:45 by jealonso          #+#    #+#             */
/*   Updated: 2016/02/26 18:13:05 by jealonso         ###   ########.fr       */
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
	char	*droite;
	char	*gauche;

	begin = ft_begin_str(str1, ' ');
	droite = ft_cut_str(str2, '-');
	gauche = ft_begin_str(str2, '-');
//	printf("[%s](begin)   [%s](gauche)   [%s](droite)\n",begin, gauche, droite);
	if (ft_strequ(begin, droite))
		return (1);
	if (ft_strequ(begin, gauche))
		return (2);
	return (0);
}

void	ft_config_room(t_list **map, int *flag)
{
	--flag;
	if (ft_strequ((*map)->data, "##start"))
	{
		*map = (*map)->next;
		(*map)->i = 1;
	}
	if (ft_strequ((*map)->data, "##end"))
		(*map)->i = 2;
}
