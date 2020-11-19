/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:34:32 by anikkane          #+#    #+#             */
/*   Updated: 2019/11/05 11:26:16 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*orig_src;
	unsigned char	*new_dst;

	i = 0;
	orig_src = (unsigned char*)src;
	new_dst = (unsigned char*)dst;
	if (!orig_src && !new_dst)
		return (0);
	while (i < n)
	{
		new_dst[i] = orig_src[i];
		i++;
	}
	return (dst);
}
