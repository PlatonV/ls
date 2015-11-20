/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 13:53:23 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/09 13:26:02 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	int		index;
	int		index2;

	index = 0;
	index2 = 0;
	while (s1[index] != '\0')
		++index;
	while (s2[index2] != '\0')
	{
		s1[index] = s2[index2];
		index++;
		index2++;
	}
	s1[index] = '\0';
	return (s1);
}
