/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 11:38:48 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/09 14:41:37 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*v;

	p = (unsigned char*)s1;
	v = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (*p == *v && *p && *v && n)
	{
		p++;
		v++;
		n--;
		if (n == 0)
			return (0);
	}
	return (*p - *v);
}
