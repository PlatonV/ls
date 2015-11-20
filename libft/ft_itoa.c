/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 12:46:15 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/09 15:39:54 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_str(int n, int index, int len, char *s)
{
	if (n < 10)
	{
		s[len] = '\0';
		s[len - index] = n + '0';
	}
	else if (index < len && n > 0)
	{
		s[len - index] = n % 10 + '0';
		ft_putnbr_str(n / 10, index + 1, len, s);
	}
}

int		get_size(int n)
{
	int	s;

	s = 0;
	while (n)
	{
		n /= 10;
		s++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		neg;
	size_t	len;
	char	*s;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = 0;
	if (n < 0)
		neg = 1;
	len = get_size(n);
	s = (char*)malloc(neg ? len + 2 : len + 1);
	if (neg)
	{
		s[0] = '-';
		ft_putnbr_str(-n, 1, len + 1, s);
	}
	else
		ft_putnbr_str(n, 1, len, s);
	return (n == 0 ? ft_strdup("0") : s);
}
