/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 09:22:44 by mkivipur          #+#    #+#             */
/*   Updated: 2020/01/14 14:21:30 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_solver(t_list **begin_list, int tetri_nbr, int size)
{
	t_list		*tmp;
	char		*map;
	int			j;

	tmp = *begin_list;
	map = ft_map(size);
	while (tetri_nbr > 0)
	{
		j = 0;
		while (ft_freespot(tmp, map, j, &tetri_nbr) == 0)
		{
			ft_freespot(tmp, map, j++, &tetri_nbr);
			if (j > size * 15)
			{
				if (!(tmp = set_tmp(begin_list, tmp, &size, &map)))
					reset_tmp(begin_list, &tmp, &j);
				else
					map = remove_tetris(tmp, map, &j, &tetri_nbr);
			}
		}
		tmp = tmp->next;
	}
	final_print(map, size);
	free_begin(begin_list);
	return (1);
}

void	free_begin(t_list **begin_list)
{
	t_list *list1;
	t_list *tmp;

	list1 = *begin_list;
	while (list1)
	{
		tmp = list1->next;
		free(list1->co);
		free(list1);
		list1 = tmp;
	}
}

char	*remove_tetris(t_list *tmp, char *map, int *j, int *tetri_nbr)
{
	int		i;
	int		size;

	i = 0;
	while (map[i] != '0')
		i++;
	size = i;
	i = 0;
	while (i < (size * 16))
	{
		if (map[i] == ((tmp)->co[4]))
			map[i] = '.';
		i++;
	}
	*tetri_nbr = *tetri_nbr + 1;
	*j = 1;
	return (map);
}

t_list	*set_tmp(t_list **begin_list, t_list *tmp, int *size, char **map)
{
	t_list *tmp2;

	if (tmp->co[4] == 'A')
	{
		tmp->co[5] = 0;
		*size = *size + 1;
		free(*map);
		*map = ft_map(*size);
		return (0);
	}
	if (tmp->co[6] == 1)
		tmp->co[5] = 0;
	tmp2 = *begin_list;
	while ((tmp2->co[4]) != (((tmp)->co[4]) - 1))
		tmp2 = tmp2->next;
	tmp = tmp2;
	return (tmp);
}

int		ft_freespot(t_list *tmp, char *map, int j, int *tetri_nbr)
{
	if ((map[((tmp)->co[0] + j + ((tmp)->co[5]))] == '.')
			&& (map[((tmp)->co[1] + j + ((tmp)->co[5]))] == '.')
			&& (map[((tmp)->co[2] + j + ((tmp)->co[5]))] == '.')
			&& (map[((tmp)->co[3] + j + ((tmp)->co[5]))] == '.'))
	{
		map[((tmp)->co[0] + j + ((tmp)->co[5]))] = ((tmp)->co[4]);
		map[((tmp)->co[1] + j + ((tmp)->co[5]))] = ((tmp)->co[4]);
		map[((tmp)->co[2] + j + ((tmp)->co[5]))] = ((tmp)->co[4]);
		map[((tmp)->co[3] + j + ((tmp)->co[5]))] = ((tmp)->co[4]);
		tmp->co[6] = 1;
		tmp->co[5] = j + tmp->co[5];
		*tetri_nbr = *tetri_nbr - 1;
		return (1);
	}
	return (0);
}
