/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 15:01:27 by vplaton           #+#    #+#             */
/*   Updated: 2016/02/07 13:55:56 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*get_filename(char *s)
{
	char		*result;
	char		*it;

	it = s;
	result = NULL;
	while (*it)
	{
		if (*it == '/' && *(it + 1))
			result = it + 1;
		it++;
	}
	if (s[ft_strlen(s) - 1] == '/')
		s[ft_strlen(s) - 1] = '\0';
	if (!result)
		return (s);
	else
		return (result);
}

unsigned int	ft_numsize(unsigned long n)
{
	unsigned int	result;

	result = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		result++;
	}
	return (result);
}

void			print_file2(char *file)
{
	char		*str;
	t_stat		s;

	lstat(file, &s);
	str = ft_strnew(100);
	if (!g_ptargets)
		ft_putstr(get_filename(file));
	else
		ft_putstr(file);
	if (S_ISLNK(s.st_mode))
	{
		readlink(file, str, 100);
		ft_putstr(" -> ");
		ft_putstr(str);
	}
}
