/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:55:55 by mkivipur          #+#    #+#             */
/*   Updated: 2020/01/06 14:35:38 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_create_elem(int *array, char c, size_t content_size)
{
	t_list *ret;

	if (!(ret = malloc(sizeof(t_list))))
		return (NULL);
	if (!(ret->co = malloc(sizeof(int) * content_size)))
		return (NULL);
	ret->co[0] = array[1];
	ret->co[1] = array[2];
	ret->co[2] = array[3];
	ret->co[3] = array[4];
	ret->co[4] = c;
	ret->co[5] = 0;
	ret->co[6] = 0;
	ret->next = NULL;
	free(array);
	return (ret);
}

void	ft_list_push_back(t_list **begin_list, int *array, char c)
{
	t_list	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(array, c, 40);
	}
	else
		*begin_list = ft_create_elem(array, c, 40);
}

int		*get_coordinates(char *tetriminos)
{
	int		i;
	int		d;
	int		y;
	int		hcount;
	int		*array;

	if (!(array = (int *)malloc(sizeof(int) * 25)))
		return (0);
	i = 0;
	hcount = 0;
	y = 1;
	while (hcount < 4)
	{
		if (tetriminos[i] == '#')
		{
			d = scale_coordinates(i, d);
			array[y] = d;
			y++;
			hcount++;
		}
		i++;
	}
	return (array);
}

int		scale_coordinates(int i, int d)
{
	d = i;
	if (i > 3 && i < 7)
		d = d + 12;
	if (i > 7 && i < 11)
		d = d + 24;
	if (i > 11)
		d = d + 36;
	return (d);
}

int		store_data(char *buff, char c, int o, int tetri_nbr)
{
	t_list		*begin_list;
	char		*nnstring;
	char		*tetriminos;
	int			size;

	size = 0;
	begin_list = NULL;
	tetri_nbr = (charcount(buff, '#') / 4);
	nnstring = (create_nnstring(buff));
	o = tetri_nbr;
	while (tetri_nbr > 0)
	{
		tetriminos = (make_tetriminos(tetriminos, nnstring,
					(start_tet(nnstring)), (end_tet(nnstring))));
		ft_list_push_back(&begin_list, (get_coordinates(tetriminos)), c);
		tetri_nbr--;
		c++;
		nnstring = set_nnstring(nnstring, (end_tet(nnstring) + 1),
				ft_strlen(nnstring));
	}
	size = map_size(size, (o * 4));
	ft_solver(&begin_list, o, size);
	free(nnstring);
	return (1);
}
