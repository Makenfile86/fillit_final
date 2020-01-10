/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnegacpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:38:56 by mkivipur          #+#    #+#             */
/*   Updated: 2019/11/29 10:42:09 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_strsubm(char *s2, char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	while (j < len)
	{
		s2[j] = s[i];
		i++;
		j++;
	}
	s2[i] = '\0';
	return (*s2);
}
