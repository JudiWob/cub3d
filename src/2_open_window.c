#include "../includes/header.h"


void	open_window(t_struct *game);
void	init_game(t_struct *game);
// void	load_images(t_struct *game);
// int		render_map(t_struct *game);
// void	choose_image(int x, int y, t_struct *game);

void	open_window(t_struct *game)
{
	init_game(game);
	//load_images(game);
	//render_map(game);
}

void	init_game(t_struct *game)
{
	int	window_width;
	int	window_height;
	//int	screen_width;
	//int	screen_height;

/* initializes the connection between your program 
and the graphical system (like the X11 server on Linux). */
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_printf(game, "Failed to initialize MLX", 2);
	//mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	window_width = game->columns * TILESIZE;
	window_height = game->lines * TILESIZE;
	// if (window_width > screen_width || window_height > screen_height)
	// 	exit_printf(game, "Error: Map is too big for the screen", 2);
	game->win = mlx_new_window(game->mlx, window_width, window_height,
			"cub3d");
	if (!game->win)
		exit_printf(game, "Window creation failed", 2);
	mlx_clear_window(game->mlx, game->win);
	return ;
}