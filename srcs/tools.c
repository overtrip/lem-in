/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:44:45 by jealonso          #+#    #+#             */
/*   Updated: 2016/04/14 18:26:39 by jealonso         ###   ########.fr       */
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

void	ft_clean(char *begin,char *droite, char *gauche)
{
	free(begin);
	free(droite);
	free(gauche);
}

int		ft_pile_face(char *str1, char *str2)
{
	int		ret;
	char	*begin;
	char	*droite;
	char	*gauche;

	ret = 0;
	begin = ft_begin_str(str1, ' ');
	droite = ft_cut_str(str2, '-');
	gauche = ft_begin_str(str2, '-');
	if (ft_strequ(begin, droite))
		ret = 1;
	if (ft_strequ(begin, gauche))
		ret = 2;
	ft_clean(droite, gauche, begin);
	return (ret);
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
