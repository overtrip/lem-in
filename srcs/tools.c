/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:44:45 by jealonso          #+#    #+#             */
/*   Updated: 2016/04/21 15:42:19 by jealonso         ###   ########.fr       */
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
	//printf("[%s](str1)\t[%s](str2)\t[%s](begin)\t[%s](droite)\t[%s](gauche)\n", str1,str2, begin, droite, gauche);
	if (ft_strequ(begin, droite))
		ret = 1;
	if (ft_strequ(begin, gauche))
		ret = 2;
	ft_clean(droite, gauche, begin);
	return (ret);
}

void	ft_initlink(t_room *new)
{
	int	i;

	i = 0;
	new->nb_malloc = 5;
	while (i < new->nb_malloc)
		new->link[i++] = NULL;
}

void	ft_msg_coo(int *alert, char c)
{
	ft_putstr("They are no ");
	ft_putchar(c);
	ft_putendl(" coordonne");
	++(*alert);
}

void	ft_getint(t_room *new, char *data, int *alert)
{
	char	*begin;
	char	*end;
	char	*new_begin;

	begin = ft_cut_str(data, ' ');
	if (!begin)
		ft_msg_coo(alert, 0);
	end = ft_cut_str(begin, ' ');
	if (!end)
		ft_msg_coo(alert, 'Y');
	new_begin = ft_begin_str(begin, ' ');
	if (ft_isnumber(new_begin))
		new->x = ft_atoi(new_begin);
	if (ft_isnumber(end))
		new->y = ft_atoi(end);
	free(begin);
	free(new_begin);
	free(end);
}

void	specail_case(t_room *new, t_list **tmp, int *alert)
{
	if (ft_strequ((*tmp)->data, "##start"))
		new->s_e = 1;
	else
		new->s_e = 2;
	(*tmp) = (*tmp)->next;
	ft_getint(new, (*tmp)->data, alert);
	ft_initlink(new);
	new->next = NULL;
	new->presence = 0;
	new->data = ft_begin_str((*tmp)->data, ' ');
}

t_room	*ft_create_room(t_list **tmp, int *alert)
{
	t_room	*new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	if (!(new->link = (t_room **)malloc(sizeof(t_room *) * 5)))
	{
		free(new);
		return (NULL);
	}
	if ((ft_strequ((*tmp)->data, "##end") ||
				ft_strequ((*tmp)->data, "##start")))
		specail_case(new, tmp, alert);
	else
	{
		ft_getint(new, (*tmp)->data, alert);
		ft_initlink(new);
		new->s_e = 0;
		new->next = NULL;
		new->presence = 0;
		new->data = ft_begin_str((*tmp)->data, ' ');
	}
	return (new);
}
