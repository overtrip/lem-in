/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 16:03:10 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 16:31:20 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# define SIZE 5

typedef struct			s_room
{
	char				*data;
	struct s_room		**link;
	struct s_room		*next;
	int					s_e;
	int					x;
	int					y;
	int					nb_malloc;
	int					presence;
}						t_room;

typedef struct			s_chain
{
	int					len;
	size_t				weight;
	struct s_chain		*chain;
	struct s_chain		*next;
	t_room				*data;
}						t_chain;

int						ft_error(t_list *map);
char					*ft_begin_str(char *str, char c);
char					*ft_cut_str(char *str, char c);
t_list					*find_tube(t_list *map);
int						ft_pile_face(char *str1, char *str2);
void					ft_config_room(t_list **map, int *flag);
void					ft_add_room(t_room **map, t_room *room);
void					ft_new_way(t_chain **network, t_chain *old);
t_chain					*ft_create_chain(t_room *tmp);
void					ft_chain_push_back(t_chain **begin, t_chain *new);
t_chain					*ft_find_way(t_room *map);
void					ft_clear_null(t_list *map);
t_room					*ft_create_room(t_list **data, int *alert);
void					ft_delete_room(t_room **room);
void					ft_delet_network(t_chain **network);
int						ft_adj(t_chain *way, t_chain *network);
void					ft_chain_push_front(t_chain **begin, t_chain *new);
void					ft_print_error(int find, int *alert);
void					ft_putmsg(int start, int *alert);
int						ft_limit(int *limit, char *str, char *str2);
void					clear_presence(t_chain *way);
void					ft_resolver(t_chain **network, int nb_ants,
		t_room *map);
t_room					*find_start(t_room *map, int nb);
void					print_ant(t_chain *network);
t_room					*find_start(t_room *map, int nb);
int						its_impossible(t_chain *way);
void					ft_msg_coo(int *alert, char c);
void					ft_clean(char *begin, char *droite, char *gauche);
void					ft_push_room_back(t_room **map, t_room *new);
void					delete_all(t_list **map, t_room **room,
		t_chain **network);
void					normal_execution(t_list *map, t_room *room,
		t_chain *network);

#endif
