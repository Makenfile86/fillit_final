/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:49:59 by anikkane          #+#    #+#             */
/*   Updated: 2019/10/30 09:37:18 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*orig_src;
	unsigned char	*new_dst;
	unsigned char	chara;

	i = 0;
	new_dst = (unsigned char *)dst;
	orig_src = (unsigned char *)src;
	chara = (unsigned char)c;
	while (i < n)
	{
		*new_dst = orig_src[i];
		new_dst++;
		if (chara == orig_src[i])
		{
			return (new_dst);
		}
		i++;
	}
	return (NULL);
}
