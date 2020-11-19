/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nnstring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:50:21 by mkivipur          #+#    #+#             */
/*   Updated: 2020/01/14 14:22:09 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*create_nnstring(char *buff)
{
	int		i;
	int		y;
	char	*nnstring;
	int		len;

	if (!(nnstring = ft_strnew(ft_strlen(buff))))
		return (0);
	i = 0;
	y = 0;
	len = ft_strlen(buff);
	while (i < len)
	{
		if (buff[i] != '\n')
		{
			nnstring[y] = buff[i];
			y++;
			i++;
		}
		else
			i++;
	}
	nnstring[y] = '\0';
	return (nnstring);
}

int		check_nnstring(char *nnstring)
{
	int	dotcount;
	int	hashcount;
	int	len;

	hashcount = charcount(nnstring, '#');
	dotcount = charcount(nnstring, '.');
	len = ft_strlen(nnstring);
	if (((len % 16) != 0) || len < 15 || len > 417 || (hashcount % 4) != 0
			|| hashcount < 3)
	{
		free(nnstring);
		return (0);
	}
	if ((len - dotcount) != hashcount)
	{
		free(nnstring);
		return (0);
	}
	if (!(valid_tetri(nnstring)))
	{
		free(nnstring);
		return (0);
	}
	return (1);
}

int		valid_tetri2(int i, int count, int hcount, char *nnstring)
{
	int tetri_count;
	int scale;

	scale = 0;
	tetri_count = 0;
	while (nnstring[i] != '\0')
	{
		if (nnstring[i] == '#')
		{
			hcount++;
			scale = (i - (tetri_count * 16));
			count = neighbour_count(nnstring, count, hcount, scale);
			if (hcount % 4 == 0)
			{
				tetri_count++;
				if (count == 6 || count == 8)
					count = 0;
				else
					return (0);
			}
		}
		i++;
	}
	return (1);
}

int		valid_tetri(char *nnstring)
{
	int i;
	int count;
	int hcount;

	hcount = 0;
	i = 0;
	count = 0;
	if (!(hash_check(nnstring)))
	{
		return (0);
	}
	if (!(valid_tetri2(i, count, hcount, nnstring)))
	{
		return (0);
	}
	free(nnstring);
	return (1);
}

int		neighbour_count(char *nnstring, int count, int hcount, int y)
{
	int i;

	i = find_hashtag(nnstring, hcount);
	if ((y + 1) < 16 && (nnstring[i + 1] == '#'
				&& hcount != 4 && y != 3 && y != 7 && y != 11))
		count++;
	if (y != 0 && nnstring[i - 1] == '#'
			&& hcount != 0 && y != 4 && y != 8 && y != 12)
		count++;
	if ((y + 4) < 16 && (nnstring[i + 4] == '#' && hcount != 4 && y < 12))
		count++;
	if (y > 3 && nnstring[i - 4] == '#')
		count++;
	return (count);
}
