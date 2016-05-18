/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:58:47 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/18 17:02:31 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_error(int find, int *alert)
{
	if (!find)
	{
		ft_putendl("map not linked");
		++(*alert);
	}
}

void	ft_putmsg(int start)
{
	if (!start)
		ft_putendl("They are no ##start");
	else
		ft_putendl("They are no ##end");
}

int		ft_limit(int *limit, char *str, char *str2)
{
	if (ft_strequ(str, str2))
		++(*limit);
	if (*limit > 1)
	{
		ft_putstr("Multiple ");
		ft_putendl(str2);
		return (1);
	}
	return (0);
}
