/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:19:55 by jquivogn          #+#    #+#             */
/*   Updated: 2018/11/08 17:39:02 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		c;
	char	*str;

	c = -1;
	if (!(s1) || !(s2))
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = ft_memalloc(i)))
		return (NULL);
	while (s1[++c])
		str[c] = s1[c];
	i = 0;
	while (s2[i])
	{
		str[c] = s2[i];
		c++;
		i++;
	}
	str[c] = '\0';
	return (str);
}
