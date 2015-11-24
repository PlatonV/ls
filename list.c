/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 10:33:18 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/24 16:19:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_dir_name(t_lsdata *lst)
{
	while (lst)
	{
		if (lst->filename[0] != '.')
			ft_putendl(lst->filename);
		lst = lst->next;
	}
}

static void		print_dir_name_hidden(t_lsdata *lst)
{
	while (lst)
	{
		ft_putendl(lst->filename);
		lst = lst->next;
	}
}

static void		put_to_list(t_dirstruct *data, t_lsdata **lst)
{
	if (!(*lst))
		*lst = lstnew(data);
	else
		lstadd(lstnew(data), lst);
}

int				list_dir(char *name, short *flags)
{
	DIR			*dir;
	t_dirstruct	*dir_data;
	t_lsdata	*lst;

	lst = NULL;
	if ((dir = opendir(name)))
	{
		while ((dir_data = readdir(dir)))
			put_to_list(dir_data, &lst);
	}
	lstsort(&lst, lstcmp);
	if (check_flag(flags, 'a'))
		print_dir_name_hidden(lst);
	else
		print_dir_name(lst);
	return (0);
}
