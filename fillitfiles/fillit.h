/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:05:03 by mkivipur          #+#    #+#             */
/*   Updated: 2020/01/14 15:14:05 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct		s_list
{
	int				*co;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					find_hashtag(char *nnstring, int which);
int					end_tet2(char *nnstring, int end, int count);
int					hash_check(char *nnstring);
int					validate_all(char *buff);
void				free_begin(t_list **begin_list);
int					new_line_check3(char *buff, int x);
int					new_line_check2(char *buff, int count, int bcount);
int					one_tetri_check(char *buff, int i);
t_list				*reset_tmp(t_list **begin_list, t_list **tmp, int *j);
int					map_size(int size, int hashcount);
int					valid_tetri2(int i, int count, int hcount, char *nnstring);
int					final_print(char *map, int size);
char				*remove_tetris(t_list *tmp, char *map, int *j,
		int *tetri_nbr);
t_list				*set_tmp(t_list **begin_list, t_list *tmp, int *size,
		char **map);
int					ft_freespot(t_list *tmp, char *map, int j, int *tetri_nbr);
int					scale_coordinates(int i);
char				*ft_map(int size);
char				*ft_map2(char *map, int j, int i);
int					ft_solver(t_list **begin_list, int tetri_nbr, int size);
int					read_file(const int fd);
int					charcount(char *buff, char c);
char				*create_nnstring(char *buff);
int					check_nnstring(char *nnstring);
int					valid_tetri(char *nnstring);
char				*check_tetriminos(char *tetriminos2, int len);
char				*make_tetriminos(char *tetriminos, char *buff, int i);
int					new_line_check(char *buff);
char				*change_dots(char *tetriminos);
int					*get_coordinates(char *tetriminos);
void				ft_list_push_back(t_list **begin_list, int *array, char c);
t_list				*ft_create_elem(int *array, char c, size_t content_size);
int					store_data(char *buff, char c, int o, int tetri_nbr);
int					neighbour_count(char *nnstring, int ncount, int hcount,
		int i);
#endif
