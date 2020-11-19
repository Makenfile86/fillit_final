/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:21:48 by mkivipur          #+#    #+#             */
/*   Updated: 2020/01/14 14:23:32 by mkivipur         ###   ########.fr       */
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
	while (i < len)
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

int		find_hashtag(char *nnstring, int which)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (count < which && nnstring[i] != '\0')
	{
		if (nnstring[i] == '#')
			count++;
		i++;
	}
	return (i - 1);
}

int		end_tet2(char *nnstring, int end, int count)
{
	while (count < 4 && nnstring[end] != '\0')
	{
		if (nnstring[end] == '#')
			count++;
		end++;
	}
	return (end);
}
