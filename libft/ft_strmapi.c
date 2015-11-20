/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 16:11:57 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/03 14:53:41 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	size_t	len;
	char	*result;

	len = 0;
	while (s[len] != '\0')
		len++;
	index = 0;
	result = (char*)malloc(len + 1);
	while (index < len)
	{
		result[index] = f(index, s[index]);
		index++;
	}
	return (result);
}
