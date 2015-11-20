/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 14:24:39 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/09 14:34:22 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	*s;

	p = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
	{
		*p = *s;
		if ((*p == (unsigned char)c) && (*s == (unsigned char)c))
			return ((unsigned char*)p + 1);
		p++;
		s++;
	}
	return (0);
}
