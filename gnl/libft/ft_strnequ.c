/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:14:18 by jquivogn          #+#    #+#             */
/*   Updated: 2018/11/08 17:25:23 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!(s1) || !(s2))
		return (0);
	if ((!(*s1) && !(*s2)) || !(n))
		return (1);
	if (*s1 == *s2)
		return (ft_strnequ((s1 + 1), (s2 + 1), n - 1));
	return (0);
}
