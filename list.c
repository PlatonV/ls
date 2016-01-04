/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 10:33:18 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/28 20:53:27 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_file(char *file)
{
	t_maxes	maxes;

	if (!check_flag('l'))
	{
		ft_putendl(get_filename(file));
		return;
	}
	maxes.size = 0;
	maxes.link = 0;
	maxes.owner = 0;
	maxes.group = 0;
	print_long_file(file, maxes);
}

static void		print_files(t_lsdata *lst)
{
	while (lst)
	{
		print_file(lst->data);
		lst = lst->next;
	}
}

static void		skip_hidden(t_lsdata **lst)
{
	while ((*lst) && get_filename((*lst)->data)[0] == '.')
		(*lst) = (*lst)->next;
}

void		print_lst(t_lsdata *lst)
{
	if (!check_flag('a'))
		skip_hidden(&lst);
	if (check_flag('l'))
		print_long_lst(lst);
	else
		print_files(lst);
}

int				list_dir(char *name)
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
		lstsort(&lst, lstcmp_lexic);
		print_lst(lst);
	}
	if (errno == ENOTDIR)
		print_file(name);
	ft_error(name);
	return (1);
}
