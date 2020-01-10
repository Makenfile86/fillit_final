/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:47:45 by mkivipur          #+#    #+#             */
/*   Updated: 2020/01/06 11:07:36 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*make_tetriminos(char *tetriminos, char *nnstring2, int start, int end)
{
	int		len;
	char	*tetriminos2;

	len = (end - start);
	if (!(tetriminos2 = ft_strsub(nnstring2, start, len + 1)))
		return (0);
	tetriminos = check_tetriminos(tetriminos2, len);
	free(tetriminos2);
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
