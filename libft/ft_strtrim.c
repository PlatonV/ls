/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 14:44:15 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/09 16:00:11 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		starti;
	int		startl;

	if (!s)
		return (NULL);
	starti = 0;
	while ((s[starti] == ' ' || s[starti] == '\n' || s[starti] == '\t') &&
			s[starti] != '\0')
		starti++;
	if (s[starti] == '\0')
		return (ft_strdup(""));
	startl = ft_strlen(s);
	while (s[startl - 1] == ' ' || s[startl - 1] == '\n' ||
			s[startl - 1] == '\t')
		startl--;
	return (ft_strsub(s, starti, startl - starti));
}
