/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:15:42 by jquivogn          #+#    #+#             */
/*   Updated: 2018/11/07 23:49:09 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	counter;

	if (*to_find == '\0')
		return ((char *)str);
	counter = ft_strlen(to_find);
	while (*str != '\0' && n-- >= counter)
	{
		if (*str == *to_find && ft_strncmp(str, to_find, counter) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
