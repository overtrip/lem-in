/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:58:29 by jealonso          #+#    #+#             */
/*   Updated: 2016/01/30 17:18:09 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdio.h>

char	**ft_tab(char **tab, char *str, int nb_line)
{
	char	**tab_new;
	int		i;

	i = -1;
	tab_new = NULL;
	tab_new = (char **)malloc(sizeof(char *) * ++nb_line);
	while (*tab)
	{
		tab_new[++i] = ft_strdup(*tab);
		ft_putendl(tab[i]);
		++*tab;
	}
	tab_new[++i] = ft_strdup(str);
	return (tab_new);
}

int	main()
{
	char	*buff;
	char	**tab;
	int		nb_line;

	buff = NULL;
	nb_line = 0;
	tab = NULL;
	while ((get_next_line(0, &buff) > 0) && ++nb_line)
	{
		if (buff)
			tab = ft_tab(tab, buff, nb_line);
	ft_putendl("-----------");
	ft_putendl(tab[0]);
	}
	return (0);
}
