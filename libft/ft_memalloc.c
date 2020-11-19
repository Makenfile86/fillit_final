/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:10:55 by anikkane          #+#    #+#             */
/*   Updated: 2019/10/28 11:47:49 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void		*ptr;

	ptr = (void *)malloc(sizeof(*ptr) * (size));
	if (ptr)
	{
		ft_memset(ptr, 0, size);
		return (ptr);
	}
	return (NULL);
}
