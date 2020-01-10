/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:21:48 by mkivipur          #+#    #+#             */
/*   Updated: 2020/01/10 11:34:06 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		hash_check(char *nnstring)
{
	int i;
	int count;
	int len;

	i = 0;
	count = 0;
	len = ft_strlen(nnstring);
	while (i <= len)
	{
		if (nnstring[i] == '#')
			count++;
		i++;
		if ((i % 16) == 0)
		{
			if ((count == 0 || count != 4))
				return (0);
			count = 0;
		}
	}
	return (1);
}

char	*cut_pieces(char *tmp2)
{
	char *tmp;

	tmp = ft_strsub(tmp2, 21, ft_strlen(tmp2));
	ft_strcpy(tmp2, tmp);
	free(tmp);
	return (tmp2);
}

char	*cut_pieces2(char *tmp2)
{
	char *tmp;

	tmp = ft_strsub(tmp2, 16, ft_strlen(tmp2));
	ft_strcpy(tmp2, tmp);
	free(tmp);
	return (tmp2);
}
