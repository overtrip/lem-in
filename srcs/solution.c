#include "lem_in.h"



void	ft_resolver(t_chain *network, t_list *map)
{
	size_t	ants;

	ants = ft_atoi(map->data);
	while (ants)
	{
		if (is_empty(network))
		--ants;
	}
}
