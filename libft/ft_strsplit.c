/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 14:00:16 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/04 12:35:25 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_split_number(char const *s, char c)
{
	int		index;
	size_t	result;

	index = 0;
	result = 0;
	while (s[index] != '\0')
	{
		while (s[index] == c)
			index++;
		if (s[index] == '\0')
			return (result);
		result++;
		while (s[index] != c && s[index] != '\0')
			index++;
	}
	return (result);
}

void	split(const char *s, char **tab, char c)
{
	int		index;
	int		index2;
	int		splitindex;

	index = 0;
	splitindex = 0;
	while (s[index] != '\0')
	{
		while (s[index] == c)
			index++;
		if (s[index] == '\0')
			return ;
		index2 = index;
		while (s[index] != c && s[index] != '\0')
			index++;
		tab[splitindex] = ft_strsub(s, index2, index - index2);
		splitindex++;
	}
	tab[splitindex] = NULL;
}

char	**ft_strsplit(char const *s, char c)
{
	char	**res;

	if (!(res = (char**)malloc(sizeof(char*) * get_split_number(s, c) + 1)))
		return (NULL);
	if (s == NULL)
		return (NULL);
	split(s, res, c);
	return (res);
}
