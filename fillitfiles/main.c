/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:00:33 by mkivipur          #+#    #+#             */
/*   Updated: 2020/01/10 12:05:09 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
int		main(int argc, char **argv)
{
	int		fd;

	fd = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (!(read_file(fd)))
		ft_putendl("error");
	close(fd);
	return (0);
}
*/ 

int		main()
{
	int		fd;
	int i;

	fd = 0;
 	i = 0;
	while (i < 1000)
	{
		read_file(fd);
			i++;
			ft_putnbr(i);
			ft_putchar('\n');
	}
	close(fd);

	return (0);
}
