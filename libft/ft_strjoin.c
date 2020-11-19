/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:13:15 by anikkane          #+#    #+#             */
/*   Updated: 2019/10/29 14:20:13 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*conca;
	int		i;

	conca = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (conca)
	{
		i = 0;
		while (*s1)
		{
			conca[i++] = *s1;
			s1++;
		}
		while (*s2)
		{
			conca[i++] = *s2;
			s2++;
		}
		conca[i] = '\0';
		return (conca);
	}
	return (NULL);
}
