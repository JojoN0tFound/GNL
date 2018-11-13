/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:22:13 by jquivogn          #+#    #+#             */
/*   Updated: 2018/11/08 00:27:08 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_min(char *tab)
{
	tab[0] = '-';
	tab[1] = '2';
	tab[2] = '1';
	tab[3] = '4';
	tab[4] = '7';
	tab[5] = '4';
	tab[6] = '8';
	tab[7] = '3';
	tab[8] = '6';
	tab[9] = '4';
	tab[10] = '8';
	tab[11] = '\0';
	return (tab);
}

static int		ft_size_nbr(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		i;
	int		od;
	int		neg;
	char	*tab;

	i = 0;
	neg = 1;
	od = ft_size_nbr(n);
	if (!(tab = ft_memalloc((size_t)od + 2)))
		return (NULL);
	if (n == -2147483648)
		return (ft_min(tab));
	n < 0 ? n *= -1 : neg--;
	while (i <= od)
	{
		tab[od - i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	neg ? tab[0] = '-' : 0;
	tab[od + 1] = '\0';
	return (tab);
}
