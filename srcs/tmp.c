/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:11:50 by jealonso          #+#    #+#             */
/*   Updated: 2016/02/24 16:12:16 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int			ft_verif_size(t_list *room, int *nb)
{
	t_list	*save;
	int		i;
	int		flag;

	i = -1;
	flag = 0;
	save = room;
	if (!room->link)
		return (0);
	while (room->link[++i])
		if (i >= *nb)
			++flag;
	if (flag)
	{
		*nb = i;
		return (1);
	}
	room = save;
	return (0);
}

void		ft_resize(t_list **room, int nb)
{
	t_list	*save;
	t_list	*tmp;
	int		i;

	tmp = NULL;
	save = tmp;
	i = -1;
	if (!(tmp->link = (t_list **)malloc(sizeof(t_list *) * (nb + SIZE))))
		return ;
	while ((*room)->link[++i])
		tmp->link[i] = (*room)->link[i];
	(*room)->link = tmp->link;
}

void		ft_complete(t_list **room, char *control, t_list **save)
{
	int	i;

	i = -1;
	if (!(*room)->link)
		if (ft_pile_face((*map)->data, control->data) == 1)
			(*room)->link[0] = ft_match(ft_cut_str(control->data, '-'), save);
}

void		ft_linker(t_list **map, t_list **save)
{
	t_list	*control;
	t_list	*begin;
	int		flag;
	int		i;

	i = SIZE;
	flag = 2;
	begin = find_tube(*map);
	while (map && !ft_strequ((*map)->data, begin->data))
	{
		if (flag > 0 && ((char *)((*map)->data))[0] == '#')
			ft_config_room(map, &flag);
		control = begin;
		while (control)
		{
			if (ft_pile_face((*map)->data, control->data) > 0)
			{
				if (ft_verif_size(*map, &i))
					ft_resize((*map)->link, i);
				ft_complete((*map)->link, control->data, save);
				(*map)->link[i++] =
						(ft_pile_face((*map)->data, control->data) == 1)
						? ft_match(ft_cut_str(control->data, '-'), save)
						: ft_match(ft_begin_str(control->data, '-'), save);
			}
			control = control->next;
		}
		i = 0;
		*map = (*map)->next;
	}
	map = save;
}
