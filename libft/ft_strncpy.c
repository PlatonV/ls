/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 14:32:44 by vplaton           #+#    #+#             */
/*   Updated: 2015/10/26 14:04:12 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		index;

	index = 0;
	while (*src && index < n)
	{
		dst[index] = *src;
		src++;
		index++;
	}
	while (index < n)
		dst[index++] = '\0';
	return (dst);
}
