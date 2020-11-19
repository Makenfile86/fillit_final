/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:58:12 by anikkane          #+#    #+#             */
/*   Updated: 2020/01/14 14:38:44 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (s)
	{
		substr = ft_strnew(len);
		if (substr)
		{
			i = start;
			j = 0;
			while (j < len)
			{
				substr[j] = s[i];
				i++;
				j++;
			}
			substr[i] = '\0';
			return (substr);
		}
	}
	return (NULL);
}
