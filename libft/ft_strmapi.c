/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:46:32 by anikkane          #+#    #+#             */
/*   Updated: 2019/10/29 12:17:31 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(*new) * (ft_strlen((char*)s) + 1));
	if (new)
	{
		i = 0;
		while (s[i] != '\0')
		{
			new[i] = ((*f)(i, s[i]));
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
