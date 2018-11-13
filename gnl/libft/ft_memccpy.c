/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:23:32 by jquivogn          #+#    #+#             */
/*   Updated: 2018/11/07 21:12:17 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;
	char	*dest;
	char	*src;

	i = 0;
	dest = (char *)s1;
	src = (char *)s2;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == (char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
