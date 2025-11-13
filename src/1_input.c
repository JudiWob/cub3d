#include "../includes/header.h"

void	take_input(int argc, char **argv, t_struct **game)
{
	init_struct(game);
	check_argv(argc, argv, *game);
	read_map(argv[1], *game);
	check_map(*game);
}

void	init_struct(t_struct **game)
{
    *game = malloc(sizeof(t_struct));
	if (!game)
		exit(EXIT_FAILURE);
    (*game)->mlx = NULL;
	(*game)->win = NULL;
    (*game)->fd = -1;
	(*game)->lines = 0;
	(*game)->columns= 0;
	printf("hi\n");
}

void	check_argv(int argc, char **argv, t_struct *game)
{
	int	len;

	if (argc != 2)
		exit_printf(game, "Error: Usage: \"./cub3d\" \"<<scenename>>.cub\"", 2);
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strcmp(argv[1] + len - 4, ".cub") != 0)
		exit_printf(game, "Error: Wrong Fileformat, expected .cub for scene", 2);
	return ;
}

void	read_map(char *argv1, t_struct *game)
{
	char	*line;
	int		i;

	count_lines(argv1, game);
	game->fd = open(argv1, O_RDONLY);
	if (game->fd < 0)
		exit_printf(game, "Error opening map file", 2);
	game->map = malloc(sizeof(char *) * (game->lines + 1));
	if (!game->map)
		exit(EXIT_FAILURE);
	i = 0;
	line = get_next_line(game->fd);
	while (line)
	{
		game->map[i++] = line;
		line = get_next_line(game->fd);
	}
	game->map[i] = NULL;
	close(game->fd);
	game->fd = -1; //flag that file has been closed correctly
	return;
}


int	count_lines(char *argv1, t_struct *game)
{
	int		count;
	char	*line;

	game->fd = open(argv1, O_RDONLY);
	if (game->fd < 0)
		exit_printf(game, "Error opening map file", 2);
	count = 0;
	line = get_next_line(game->fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(game->fd);
	}
	free(line);
	game->lines = count;
	close(game->fd); 
	game->fd = -1; //flag that file has been closed correctly
	return (count);
}