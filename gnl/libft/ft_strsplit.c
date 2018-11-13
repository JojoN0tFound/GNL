/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:16:47 by jquivogn          #+#    #+#             */
/*   Updated: 2018/11/09 07:01:34 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static int		word_size(const char *str, char c)
{
	int count;

	count = 0;
	while (*str == c)
		str++;
	while (str[count] != c && str[count])
		count++;
	return (count);
}

char			**ft_strsplit(char const *str, char c)
{
	int		n;
	int		i;
	int		j;
	char	**tab;

	i = -1;
	if (!(str))
		return (0);
	n = count_words(str, c);
	if (!(tab = (char **)malloc(sizeof(*tab) * (n + 1))))
		return (0);
	while (++i < n)
	{
		j = -1;
		if (!(tab[i] = (char *)malloc(word_size(str, c) + 1)))
			return (0);
		while (*str == c && *str)
			str++;
		while (*str && *str != c)
			tab[i][++j] = *str++;
		tab[i][j + 1] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
