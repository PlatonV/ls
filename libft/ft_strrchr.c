/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 13:17:06 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/02 19:42:25 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = 0;
	while (*s)
	{
		if (*s == c)
			result = (char*)s;
		s++;
	}
	if (*s == c)
		result = (char*)s;
	return ((char*)result);
}
