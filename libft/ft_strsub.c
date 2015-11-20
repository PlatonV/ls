/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 15:04:57 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/04 13:10:00 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	index;

	if (!(result = (char*)malloc(len + 1)))
		return (NULL);
	index = 0;
	while (index < len)
	{
		result[index] = s[index + start];
		index++;
	}
	result[index] = '\0';
	return (result);
}
