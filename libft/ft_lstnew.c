/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 19:17:02 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/04 13:11:22 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;

	if (!(res = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		res->content_size = content_size;
		if (!(res->content = (void*)malloc(content_size)))
			return (NULL);
		ft_memcpy(res->content, content, content_size);
		res->next = NULL;
	}
	else
	{
		res->content_size = 0;
		res->content = NULL;
		res->next = NULL;
	}
	return (res);
}
