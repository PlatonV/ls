/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 13:59:45 by vplaton           #+#    #+#             */
/*   Updated: 2015/10/26 14:04:22 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		index;
	size_t		index2;
	size_t		l;

	l = 0;
	while (dst[l] != '\0')
		++l;
	index2 = 0;
	index = l;
	while (src[index2] != '\0')
	{
		if (index < size - 1)
			dst[index] = src[index2];
		index++;
		index2++;
	}
	if (size < l)
		return (size + index2);
	return (l + index2);
}
