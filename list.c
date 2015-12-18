/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 10:33:18 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/18 02:01:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_dir_name(t_lsdata *lst, short *flags)
{
	while (lst)
	{
		if (check_flag(flags, 'a') || lst->data[0] != '.')
			ft_putendl(lst->data);
		lst = lst->next;
	}
}

void		print_all(t_lsdata *lst, short *flags)
{
	if (check_flag(flags, 'l'))
		print_long(lst, flags);
	else
		print_dir_name(lst, flags);
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
			put_to_list(dir_data->d_name, &lst);
		lstsort(&lst, lstcmp_lexic);
		print_all(lst, flags);
	}
	return (0);
}
