/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:13:41 by jquivogn          #+#    #+#             */
/*   Updated: 2018/11/07 21:16:21 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int a;
	int counter;

	if (to_find[0] == '\0')
		return ((char *)str);
	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] == to_find[0])
		{
			counter = 1;
			while (to_find[counter] != '\0' &&
					str[a + counter] == to_find[counter])
				counter++;
			if (to_find[counter] == '\0')
				return ((char *)&str[a]);
		}
		++a;
	}
	return (0);
}
