/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsdata_list_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 14:07:18 by vplaton           #+#    #+#             */
/*   Updated: 2016/02/17 14:07:19 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			list_size(t_lsdata *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void		put_to_list(char *data, t_lsdata **lst)
{
	if (!(*lst))
		*lst = lstnew(data);
	else
		lstadd(lstnew(data), lst);
}
