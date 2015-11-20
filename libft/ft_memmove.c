/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 15:07:31 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/04 13:09:48 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			index;
	unsigned char	*p;
	unsigned char	*s;

	index = 0;
	p = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst > src)
		while (len--)
			p[len] = s[len];
	else if (dst < src)
		while (index++ < len)
		{
			*p = *s;
			p++;
			s++;
		}
	return (dst);
}
