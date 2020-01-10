/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nnstring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:50:21 by mkivipur          #+#    #+#             */
/*   Updated: 2020/01/10 11:40:05 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*create_nnstring(char *buff)
{
	int		i;
	int		y;
	char	*nnstring;

	if (!(nnstring = ft_strnew(ft_strlen(buff))))
		return (0);
	i = 0;
	y = 0;
	while (buff[i] != '\0')
	{
		while (buff[i] == '\n')
			i++;
		nnstring[y] = buff[i];
		y++;
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
	while (nnstring[i] != '\0')
	{
		if (nnstring[i] == '#')
		{
			hcount++;
			count = neighbour_count(nnstring, count, hcount, i);
		}
		if (hcount == 4)
		{
			if (count == 6 || count == 8)
			{
				count = 0;
				hcount = 0;
			}
			else
				return (0);
			nnstring = cut_pieces2(nnstring);
			i = -1;
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
		return (0);
	if (!(valid_tetri2(i, count, hcount, nnstring)))
		return (0);
	free(nnstring);
	return (1);
}

int		neighbour_count(char *nnstring, int count, int hcount, int i)
{
	int len;

	len = ft_strlen(nnstring);
	if ((i + 1) <= len && (nnstring[i + 1] == '#'
				&& hcount != 4 && i != 3 && i != 7 && i != 11))
		count++;
	if (i != 0 && nnstring[i - 1] == '#'
			&& hcount != 0 && i != 4 && i != 8 && i != 12)
		count++;
	if ((i + 4) <= len && (nnstring[i + 4] == '#' && hcount != 4 && i < 12))
		count++;
	if (i > 3 && nnstring[i - 4] == '#')
		count++;
	return (count);
}
