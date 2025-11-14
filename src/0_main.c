#include "../includes/header.h"

int main(int argc, char **argv)
{
    t_struct *game;

    take_input(argc, argv, &game);
    printf("columns=%i, lines=%i, TILESIZE=%d\n", game->columns, game->lines, TILESIZE);

    open_window(game);

    mlx_loop_hook(game->mlx, render_map, game);
    mlx_loop(game->mlx);
    
}
//keep window open
    //mlx_clear_window(game->mlx, game->win);
    //mlx_string_put(game->mlx, game->win, 50, 50, 0xFF0000, "Hello MLX!");
