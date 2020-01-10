/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:23:13 by anikkane          #+#    #+#             */
/*   Updated: 2020/01/06 14:32:07 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		map_size(int size, int hashcount)
{
	size = 2;
	while (hashcount > (size * size))
		size++;
	return (size);
}

char	*ft_map(int size)
{
	int		y;
	int		x;
	int		j;
	int		i;
	char	*map;

	if (!(map = (char *)malloc(sizeof(char) * 240 + 1)))
		return (0);
	x = 0;
	i = 0;
	j = size;
	while (size > 0)
	{
		y = 0;
		while (x++ < j)
			map[i++] = '.';
		x = 0;
		while (y++ < 15 - j)
			map[i++] = '0';
		map[i++] = '\n';
		size--;
	}
	map = ft_map2(map, j, i);
	return (map);
}

char	*ft_map2(char *map, int j, int i)
{
	int	x;
	int g;

	g = i;
	x = 0;
	while ((15 - j) > 0)
	{
		while (x < 15)
		{
			map[g] = '0';
			x++;
			g++;
		}
		if (x == 15)
		{
			map[g] = '\n';
			g++;
			j++;
			x = 0;
		}
	}
	return (map);
}

int		final_print(char *map, int size)
{
	int		i;

	i = 0;
	while (i < (size * 15))
	{
		if (map[i] == '0')
			i++;
		else
		{
			ft_putchar(map[i]);
			i++;
		}
	}
	ft_putchar('\n');
	free(map);
	return (1);
}
