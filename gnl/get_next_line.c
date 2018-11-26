/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 00:06:32 by jquivogn          #+#    #+#             */
/*   Updated: 2018/11/22 08:50:12 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

char	*ft_decalage(char ***str)
{
	char	*ptr;

	if (***str == '\0')
		return (NULL);
	ptr = **str;
	while (*ptr != '\0' && *ptr != '\n')
		ptr++;
	if (*ptr == '\n')
		ptr++;
	return (ptr);
}

char	*ft_strdup_ret(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!(dest = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_append(char **line, char **file)
{
	if (!file)
		return (0);
	if (!(*line = ft_strdup_ret(*file)))
		return (-1);
	if (**file == EOF || !(*file) || !(*file = ft_decalage(&file)))
	{
		free(*file);
		return (0);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*file[1024];
	char		*tmp;
	int			ret;

	ret = 0;
	if (fd < 0 || BUFF_SIZE < 0 || !line)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (file[fd])
		{
			tmp = ft_strjoin(file[fd], buff);
			free(file[fd]);
			file[fd] = tmp;
		}
		else
			file[fd] = ft_strdup(buff);
	}
	return (file[fd] ? ft_append(line, &file[fd]) : 0);
}
