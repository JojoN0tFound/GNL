#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "gnl/get_next_line.h"

int		main(int argc, char **argv)
{
	int	fd;
	int i;
	int dis;
	char	*line;

	dis = 0;
	i = 4;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while ((dis = get_next_line(fd, &line)) == 1)
	{
		//ft_putnbr(dis);
		//ft_putchar('\n');
		ft_putendl(line);
		free(line);
		//ft_putendl("finish\n\n");
	}
	/*if ((dis = get_next_line(fd, &line)) == 1)
	{
		//ft_putnbr(dis);
		//ft_putchar('\n');
		ft_putendl(line);
		free(line);
	}*/
	if (argc == 2)
		close(fd);
	return (0);
}
