/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:33:01 by anikkane          #+#    #+#             */
/*   Updated: 2019/10/29 16:00:18 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(unsigned int nb)
{
	size_t size;

	size = 1;
	while (nb >= 10)
	{
		nb = (nb / 10);
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char			*str1;
	unsigned int	size;
	unsigned int	i;
	unsigned int	nb;

	if (n < 0)
		nb = (unsigned int)(n * -1);
	else
		nb = (unsigned int)n;
	size = (unsigned int)ft_intlen(nb);
	if (!(str1 = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	if (n < 0 && (str1[i] = '-'))
		size++;
	i = size - 1;
	while (nb >= 10)
	{
		str1[i--] = (char)(nb % 10 + '0');
		nb /= 10;
	}
	str1[i] = (char)(nb % 10 + '0');
	str1[size] = '\0';
	return (str1);
}
