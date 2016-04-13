#include "lem_in.h"

int		ft_limit(int *limit, char *str, char *str2)
{
	if (ft_strequ(str, str2))
		++limit;
	if (*limit > 1)
	{
		ft_putstr("Multiple ");
		ft_putendl(str2);
		return (1);
	}
	return (0);
}

int		ft_check_ant(int *alert, char *ant)
{
	if (!ft_isnumber(ant))
	{
		ft_putendl("They are no ants");
		++(*alert);
		return (1);
	}
	return (0);
}

void	ft_name(t_list *map, int *alert)
{
	int start;
	int	end;

	start = 0;
	end = 0;
	if (!ft_check_ant(alert, map->data))
	{
		while (map)
		{
			if (ft_limit(&start, map->data, "##start") ||
					ft_limit(&end, map->data, "##end"))
				++(*alert);
			if (((char *)(map->data))[0] == 'L' && (++alert))
				ft_putendl("Room name begin by a 'L'");
			map = map->next;
		}
		//TODO checke si cest bien start OU end
		if (!(start || end))
		{
			if (!start)
				ft_putendl("They are no ##start");
			else
				ft_putendl("They are no ##end");
		}
	}
}

//pas de link
int		ft_error(t_list **map)
{
	int	alert;

	alert = 0;
	ft_name(*map, &alert);
	return (alert);
}
