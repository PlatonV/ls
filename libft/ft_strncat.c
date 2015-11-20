/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 19:44:02 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/03 14:47:22 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		index;
	int		index2;

	index = 0;
	index2 = 0;
	while (s1[index] != '\0')
		++index;
	while (s2[index2] != '\0' && n > 0)
	{
		s1[index] = s2[index2];
		index++;
		index2++;
		n--;
	}
	s1[index] = '\0';
	return (s1);
}
