/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 15:04:01 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/02 16:08:11 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	index;
	char	*result;

	len1 = 0;
	while (s1[len1] != '\0')
		len1++;
	len2 = 0;
	while (s2[len2] != '\0')
		len2++;
	result = (char*)malloc(len1 + len2 + 1);
	index = 0;
	while (index < len1)
	{
		result[index] = s1[index];
		index++;
	}
	while (index < len1 + len2)
	{
		result[index] = s2[index - len1];
		index++;
	}
	result[index] = '\0';
	return (result);
}
