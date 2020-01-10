/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nnstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:21:40 by anikkane          #+#    #+#             */
/*   Updated: 2020/01/07 08:54:55 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*set_nnstring(char *nnstring, int start, int len)
{
	char *tmp;

	tmp = ft_strsub(nnstring, start, len);
	free(nnstring);
	return (tmp);
}
