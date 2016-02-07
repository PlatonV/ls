/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:43:19 by vplaton           #+#    #+#             */
/*   Updated: 2016/02/07 13:06:05 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_file(char *file)
{
	if (check_flag('a') || !(get_filename(file)[0] == '.'))
	{
		if (!g_ptargets)
			ft_putendl(get_filename(file));
		else
			ft_putendl(file);
	}
}

void			print_files(t_lsdata *lst)
{
	t_maxes		maxes;

	maxes.size = get_maxsize(lst);
	maxes.link = get_maxlink(lst);
	maxes.owner = get_maxowner(lst);
	maxes.group = get_maxgroup(lst);
	maxes.min = get_maxmin(lst);
	maxes.max = get_maxmax(lst);
	while (lst)
	{
		if (!check_flag('l'))
			print_file(lst->data);
		else
			print_long_file(lst->data, maxes);
		lst = lst->next;
	}
}

void		print_lst(t_lsdata *lst)
{
	if (check_flag('l'))
	{
		ft_putstr("total ");
		ft_putnbr(get_blocks(lst));
		ft_putendl("");
		print_files(lst);
	}
	else
		print_files(lst);
}

void			list(char *name)
{
	DIR			*dir;
	t_dirstruct	*dir_data;
	t_lsdata	*lst;

	lst = NULL;
	ft_strcat(name, "/");
	if ((dir = opendir(name)))
	{
		while ((dir_data = readdir(dir)))
			put_to_list(ft_strjoin(name, dir_data->d_name), &lst);
		closedir(dir);
		lstsort(&lst, lstcmp_lexic);
		if (check_flag('t'))
			lstsort(&lst, lstcmp_time);
		print_lst(lst);
	}
	if (check_flag('R'))
		list_rec(lst);
	else if (errno == ENOTDIR)
	{
		name[ft_strlen(name) - 1] = '\0';
		put_to_list(ft_strdup(name), &lst);
		print_lst(lst);
	}
	ft_error(name);
}
