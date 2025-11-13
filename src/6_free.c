#include "../includes/header.h"

void	exit_printf(t_struct *game, char *message, int fd)
{
	ft_printf(fd,"%s\n", message);
	if (game)
		exit(EXIT_FAILURE); //free_exit(game);
	exit(EXIT_FAILURE);
}