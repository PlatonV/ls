/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 15:01:34 by vplaton           #+#    #+#             */
/*   Updated: 2016/02/07 13:54:00 by vplaton          ###   ########.fr       */
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
		lstat(lst->data, &s);
		if (check_flag('a') || !(get_filename(lst->data)[0] == '.'))
		{
			if (ft_numsize(s.st_nlink) > max)
				max = ft_numsize(s.st_nlink);
		}
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
		lstat(lst->data, &s);
		if (check_flag('a') || !(get_filename(lst->data)[0] == '.'))
		{
			if (ft_numsize(s.st_size) > max)
				max = ft_numsize(s.st_size);
		}
		lst = lst->next;
	}
	return (max);
}

unsigned int		get_maxowner(t_lsdata *lst)
{
	t_stat				s;
	char				*str;
	unsigned int		max;

	max = 0;
	while(lst)
	{
		lstat(lst->data, &s);
		if (check_flag('a') || !(get_filename(lst->data)[0] == '.'))
		{
			if (!getpwuid(s.st_uid))
				str = ft_itoa(s.st_uid);
			else
				str = getpwuid(s.st_uid)->pw_name;
			if (ft_strlen(str) > max)
					max = ft_strlen(str);
		}
		lst = lst->next;
	}
	return (max);
}

unsigned int		get_maxgroup(t_lsdata *lst)
{
	t_stat				s;
	char				*str;
	unsigned int		max;

	max = 0;
	while(lst)
	{
		lstat(lst->data, &s);
		if (!getgrgid(s.st_gid))
			str = ft_itoa(s.st_gid);
		else
			str = getgrgid(s.st_gid)->gr_name;
		if (ft_strlen(str) > max)
			max = ft_strlen(getgrgid(s.st_gid)->gr_name);
		lst = lst->next;
	}
	return (max);
}

unsigned int		get_maxmin(t_lsdata *lst)
{
	t_stat				s;
	int		max;

	max = 0;
	while(lst)
	{
		lstat(lst->data, &s);
		if (S_ISCHR(s.st_mode) || S_ISBLK(s.st_mode))
			if (minor(s.st_rdev) > max)
				max = minor(ft_strlen(ft_itoa(s.st_rdev)));
		lst = lst->next;
	}
	return (max);
}

unsigned int		get_maxmax(t_lsdata *lst)
{
	t_stat				s;
	int		max;

	max = 0;
	while(lst)
	{
		lstat(lst->data, &s);
		if (S_ISCHR(s.st_mode) || S_ISBLK(s.st_mode))
			if (major(s.st_rdev) > max)
				max = major(ft_strlen(ft_itoa(s.st_rdev)));
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
		if (check_flag('a') || !(get_filename(lst->data)[0] == '.'))
		{
			lstat(lst->data, &s);
			c += s.st_blocks;
		}
		lst = lst->next;
	}
	return (c);
}
