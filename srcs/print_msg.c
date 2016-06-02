/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:58:47 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/26 18:09:34 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_error(int find, int *alert, char *str, t_list *begin)
{
	while (!ft_strequ(begin->next->data, str))
		begin = begin->next;
	if (!find)
	{
		ft_putendl_fd("map not linked", 2);
		++(*alert);
	}
}

void	ft_putmsg(int start, int *alert)
{
	if (!start)
		ft_putendl_fd("They are no ##start", 2);
	else
		ft_putendl_fd("They are no ##end", 2);
	++(*alert);
}

int		ft_limit(int *limit, char *str, char *str2)
{
	if (ft_strequ(str, str2))
		++(*limit);
	if (*limit > 1)
	{
		ft_putstr_fd("Multiple ", 2);
		ft_putendl_fd(str2, 2);
		return (1);
	}
	return (0);
}

void	print_ant(t_chain *network)
{
	ft_putchar_fd('L', 2);
	ft_putnbr_fd(network->data->presence, 2);
	ft_putchar_fd('-', 2);
	ft_putstr_fd(network->data->data, 2);
	ft_putchar_fd(' ', 2);
}

void	ft_msg_coo(int *alert, char c)
{
	ft_putstr_fd("They are no ", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd(" coordonne", 2);
	++(*alert);
}
