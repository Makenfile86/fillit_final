/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:16:23 by mkivipur          #+#    #+#             */
/*   Updated: 2020/01/14 14:18:52 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*reset_tmp(t_list **begin_list, t_list **tmp, int *j)
{
	*tmp = *(begin_list);
	*j = 0;
	return (*tmp);
}

int			one_tetri_check(char *buff, int i)
{
	if (!((buff[i] == '\n' && buff[i + 5] == '\n' && buff[i + 10] == '\n'
				&& buff[i + 15] == '\n')))
	{
		return (0);
	}
	return (1);
}

int			new_line_check2(char *buff, int count, int bcount)
{
	count = charcount(buff, '\n');
	if (!(((bcount * 5) - 1) == count))
	{
		free(buff);
		return (0);
	}
	return (1);
}

int			new_line_check3(char *buff, int x)
{
	int i;

	i = 4;
	while (x > 0)
	{
		if (x > 1)
		{
			if (!((buff[i] == '\n' && buff[i + 5] == '\n'
							&& buff[i + 10] == '\n'
							&& buff[i + 15] == '\n' && buff[i + 16] == '\n')))
				return (0);
		}
		else
		{
			if (!(one_tetri_check(buff, i)))
				return (0);
		}
		i = (i + 21);
		x--;
	}
	return (1);
}

int			validate_all(char *buff)
{
	if (!(new_line_check(buff)))
	{
		return (0);
	}
	if (!(check_nnstring(create_nnstring(buff))))
	{
		free(buff);
		return (0);
	}
	return (1);
}
