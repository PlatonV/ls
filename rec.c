/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 13:21:58 by                   #+#    #+#             */
/*   Updated: 2016/01/08 17:39:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			list_rec(t_lsdata *lst)
{
	while (lst)
	{
		if (ft_strcmp(get_filename(lst->data), "..") &&
				ft_strcmp(get_filename(lst->data), ".") &&
				opendir(lst->data))
		{
			if (check_flag('a') || !(get_filename(lst->data)[0] == '.'))
			{
				ft_putendl(ft_strjoin(ft_strjoin("\n", lst->data), ":"));
				list(lst->data);
			}
		}
		lst = lst->next;
	}
}
