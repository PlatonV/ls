/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 10:33:18 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/20 15:14:47 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_dir_name(t_lsdata *lst)
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

int				list_dir(char *name)
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
	print_dir_name(lst);
	return (0);
}
