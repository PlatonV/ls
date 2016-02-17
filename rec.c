/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 14:07:26 by vplaton           #+#    #+#             */
/*   Updated: 2016/02/17 14:07:27 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			list_rec(t_lsdata *lst)
{
	DIR		*dir;

	while (lst)
	{
		if (ft_strcmp(get_filename(lst->data), "..") &&
				ft_strcmp(get_filename(lst->data), ".") &&
				(dir = opendir(lst->data)))
		{
			closedir(dir);
			if (check_flag('a') || !(get_filename(lst->data)[0] == '.'))
			{
				ft_putendl(ft_strjoin(ft_strjoin("\n", lst->data), ":"));
				list(lst->data);
			}
		}
		if (!dir && errno != ENOTDIR)
		{
			ft_putendl(ft_strjoin(ft_strjoin("\n", lst->data), ":"));
			list(lst->data);
			ft_error(lst->data);
		}
		lst = lst->next;
	}
}
