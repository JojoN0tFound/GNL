/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:13:23 by jquivogn          #+#    #+#             */
/*   Updated: 2018/11/08 17:37:14 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!(s))
		return (NULL);
	i = ft_strlen(s);
	if (start > i || (start + len) > i)
		return (NULL);
	if (!(str = ft_memalloc(len + 1)))
		return (NULL);
	ft_strncpy(str, s + start, len);
	return (str);
}
