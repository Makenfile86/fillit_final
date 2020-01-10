/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:16:23 by mkivipur          #+#    #+#             */
/*   Updated: 2020/01/10 12:00:51 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*reset_tmp(t_list **begin_list, t_list **tmp, int *j)
{
	*tmp = *(begin_list);
	*j = 0;
	return (*tmp);
}

int			one_tetri_check(char *buff)
{
	if (!((buff[4] == '\n' && buff[9] == '\n' && buff[14] == '\n'
				&& buff[19] == '\n')))
	{
		free(buff);
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
	char	*tmp2;

	tmp2 = ft_strnew(ft_strlen(buff));
	ft_strcpy(tmp2, buff);
	while (x > 0)
	{
		if (x > 1)
		{
			if (!((tmp2[4] == '\n' && tmp2[9] == '\n' && tmp2[14] == '\n'
							&& tmp2[19] == '\n' && tmp2[20] == '\n')))
			{
				free(tmp2);
				return (0);
			}
		}
		else
		{
			if (!(one_tetri_check(tmp2)))
				return (0);
		}
		tmp2 = cut_pieces(tmp2);
		x--;
	}
	free(tmp2);
	return (1);
}

int			validate_all(char *buff)
{
	if (!(new_line_check(buff)))
		return (0);
	if (!(check_nnstring(create_nnstring(buff))))
	{
		free(buff);
		return (0);
	}
	return (1);
}
