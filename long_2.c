/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 00:42:12 by                   #+#    #+#             */
/*   Updated: 2015/12/19 13:18:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned int 		get_maxlink(t_lsdata *lst)
{
	t_stat	s;
	unsigned int		max;

	max = 0;
	while (lst)
	{
		lstat(ft_strcat(ft_strcat(ft_strdup(g_currentpath), "/"),
						lst->data), &s);
		if (ft_numsize(s.st_nlink) > max)
			max = ft_numsize(s.st_nlink);
		lst = lst->next;
	}
	return (max);
}

unsigned int		get_maxsize(t_lsdata *lst)
{
	t_stat				s;
	unsigned int		max;

	max = 0;
	while(lst)
	{
		lstat(ft_strcat(ft_strcat(ft_strdup(g_currentpath), "/"),
						lst->data), &s);
		if (ft_numsize(s.st_size) > max)
			max = ft_numsize(s.st_size);
		lst = lst->next;
	}
	return (max);
}

unsigned int		get_maxowner(t_lsdata *lst)
{
	t_stat				s;
	unsigned int		max;

	max = 0;
	while(lst)
	{
		lstat(ft_strcat(ft_strcat(ft_strdup(g_currentpath), "/"),
						lst->data), &s);
		if (ft_strlen(getpwuid(s.st_uid)->pw_name) > max)
			max = ft_strlen(getpwuid(s.st_uid)->pw_name);
		lst = lst->next;
	}
	return (max);
}

unsigned int		get_maxgroup(t_lsdata *lst)
{
	t_stat				s;
	unsigned int		max;

	max = 0;
	while(lst)
	{
		lstat(ft_strcat(ft_strcat(ft_strdup(g_currentpath), "/"),
						lst->data), &s);
		if (ft_strlen(getgrgid(s.st_gid)->gr_name) > max)
			max = ft_strlen(getgrgid(s.st_gid)->gr_name);
		lst = lst->next;
	}
	return (max);
}

int					get_blocks(t_lsdata *lst)
{
	t_stat				s;
	unsigned int		c;

	c = 0;
	while(lst)
	{
		lstat(ft_strcat(ft_strcat(ft_strdup(g_currentpath), "/"),
						lst->data), &s);
		c += s.st_blocks;
		lst = lst->next;
	}
	return (c);
}
