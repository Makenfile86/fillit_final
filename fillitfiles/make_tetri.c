/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:47:45 by mkivipur          #+#    #+#             */
/*   Updated: 2020/01/14 14:13:27 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*make_tetriminos(char *tetriminos, char *nnstring2, int i)
{
	int count;
	int y;

	y = 0;
	count = 0;
	while (nnstring2[i] != '\0')
	{
		if (nnstring2[i] == '#')
		{
			while (count < 4)
			{
				tetriminos[y] = nnstring2[i];
				if (nnstring2[i] == '#')
					count++;
				y++;
				i++;
			}
		}
		i++;
	}
	tetriminos[y] = '\0';
	tetriminos = check_tetriminos(tetriminos, ft_strlen(tetriminos));
	return (tetriminos);
}

char	*check_tetriminos(char *tetriminos2, int len)
{
	int		i;
	char	*compares;

	if (!(compares =
				ft_strdup("#..###C#..##...#C##.##C#..##..#C#.###C#...#..##C")))
		return (0);
	i = 0;
	while (!(ft_strnequ(tetriminos2, compares, len)) && i < 6)
	{
		ft_strcpy(compares, ft_strchr(compares, 'C') + 1);
		i++;
	}
	if (ft_strnequ(tetriminos2, compares, len) == 1)
	{
		tetriminos2 = change_dots(tetriminos2);
		free(compares);
		return (tetriminos2);
	}
	free(compares);
	return (tetriminos2);
}

char	*change_dots(char *tetriminos2)
{
	int		i;
	int		count;
	char	*temp;
	char	*temp2;
	char	*tet;

	if (!(temp = ft_strdup(".")))
		return (0);
	if (!(temp2 = ft_strdup("..")))
		return (0);
	count = 0;
	i = 0;
	if (tetriminos2[0] == '#' && tetriminos2[2] == '#' && tetriminos2[3] == '#')
	{
		if (!(tet = ft_strjoin(temp2, tetriminos2)))
			return (0);
	}
	else if (!(tet = ft_strjoin(temp, tetriminos2)))
		return (0);
	free(temp);
	free(temp2);
	ft_strcpy(tetriminos2, tet);
	free(tet);
	return (tetriminos2);
}
