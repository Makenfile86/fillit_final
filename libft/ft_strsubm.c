/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:58:12 by anikkane          #+#    #+#             */
/*   Updated: 2019/11/20 10:35:40 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubm(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (s)
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
	return (NULL);
}
