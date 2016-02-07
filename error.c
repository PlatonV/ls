/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 15:01:10 by vplaton           #+#    #+#             */
/*   Updated: 2016/01/20 15:55:49 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_error(const char *str)
{
	char		*name;

	name = ft_strnew(ft_strlen(str));
	if (errno && errno != ENOTDIR)
	{
		if (name[ft_strlen(name) - 1] == '/')
			name = ft_strncpy(name, str, ft_strlen(str) - 1);
		else
			name = ft_strncpy(name, str, ft_strlen(str));
		write(2, "ft_ls: ", 7);
		perror(get_filename(name));
		errno = 0;
	}
}
