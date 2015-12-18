/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsdata_list_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 01:20:48 by                   #+#    #+#             */
/*   Updated: 2015/12/18 01:55:22 by                  ###   ########.fr       */
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
