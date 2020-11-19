/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:16:06 by anikkane          #+#    #+#             */
/*   Updated: 2019/11/05 11:31:12 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str1;
	int		i;
	int		len;

	i = 0;
	while ((char)src[i] != '\0')
		i++;
	len = i;
	if (!(str1 = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while ((char)src[i] != '\0')
	{
		str1[i] = (char)src[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
