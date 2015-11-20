/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 11:36:54 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/09 14:40:24 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*p;
	unsigned char	*v;

	p = (unsigned char*)s1;
	v = (unsigned char*)s2;
	while (*p && *v && *p == *v)
	{
		p++;
		v++;
	}
	return (*p - *v);
}
