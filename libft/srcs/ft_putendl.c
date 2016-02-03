/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:52:33 by jealonso          #+#    #+#             */
/*   Updated: 2016/02/03 17:02:54 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl(char const *s)
{
	int	cmp;

	cmp = ft_strlen(s);
	if (!s)
		return (0);
	write(1, s, cmp);
	ft_putchar('\n');
	return (++cmp);
}
