#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	int nb;
	char *line;

	if (fd < 0)
		return 1;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
	close(fd);
	return 0;
}
