/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:12:08 by mkivipur          #+#    #+#             */
/*   Updated: 2020/01/14 15:14:24 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_file(const int fd)
{
	int		ret;
	char	*buff;
	char	c;
	int		o;
	int		tetri_nbr;

	tetri_nbr = 0;
	o = 0;
	c = 'A';
	buff = ft_strnew(550 + 1);
	if (read(fd, buff, 0) == -1)
	{
		free(buff);
		return (0);
	}
	ret = read(fd, buff, 550);
	buff[ret] = '\0';
	if (!(validate_all(buff)))
		return (0);
	if (!(store_data(buff, c, o, tetri_nbr)))
		return (0);
	free(buff);
	return (1);
}

int		new_line_check(char *buff)
{
	int count;
	int bcount;
	int x;

	x = (charcount(buff, '#') / 4);
	bcount = x;
	count = 0;
	if (ft_strlen(buff) == 20 && (charcount(buff, '\n') == 4))
	{
		if (!(one_tetri_check(buff, 4)))
			return (0);
		return (1);
	}
	if (!(new_line_check2(buff, count, bcount)))
		return (0);
	if (!(new_line_check3(buff, x)))
	{
		free(buff);
		return (0);
	}
	return (1);
}

int		charcount(char *buff, char c)
{
	int i;
	int charcount;

	i = 0;
	charcount = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == c)
			charcount++;
		i++;
	}
	return (charcount);
}
