#include "../includes/header.h"



int	render_map(t_struct *game)
{
	
    // int y;
    // int x;

    // y = -1;
    // while (++y < game->lines  * TILESIZE)
    // {
    //     x = -1;
    //     while (++x < game->columns * TILESIZE)
    //     {
    //         mlx_pixel_put(game->mlx, game->win, x, y, 0xFFFFFF);

    //     }
    // }

    
    
    // int	y;
	// int	x;

	// y = -1;
	// while (++y < game->lines  * TILESIZE)
	// {
	// 	x = -1;
	// 	while (++x < game->columns * TILESIZE)
	// 	{
	// 		choose_color(x, y, game);
	// 	}
	// }
  int tex_width;
    int tex_height = 0;
    int bpp;
    int line_len;
    int endian;

    void *tex = mlx_xpm_file_to_image(game->mlx, "texture/player.xpm", &tex_width, &tex_height);
    if (!tex)
        exit_printf(game, "Failed to load floor image", 2);
    char *addr = mlx_get_data_addr(tex, &bpp, &line_len, &endian); //addr[0 ... tex_height * line_len - 1]
    //printf("BPP: %i, LineLen: %i\n", bpp, line_len);
    int pix_y = 0; //row of the pixel in texture
    int pix_x = 5; //column of the pixel in texture
    int h = -1; //row in window
    int w = 63; //column in window
    while (++h < game->lines * TILESIZE )
    {
        w = 63;
        while (++w < 63 + 64)
        {
            pix_y = (int)((float)h / (game->lines * TILESIZE) * tex_height);
            pix_x = (int)((float)(w - 63) / 64 * tex_width);
            mlx_pixel_put(game->mlx, game->win, w, h, *(int *)(addr + (pix_y * line_len + pix_x * (bpp / 8))));
        }
    }
	return (0);
}

void	choose_color(int x, int y, t_struct *game)
{
	mlx_pixel_put(game->mlx, game->win, x, y, 0xFFFFFF);
}

	// if (game->map[y][x] == '1')
	// 	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
	// 		* TILESIZE, y * TILESIZE);
	// else if (game->map[y][x] == 'C')
	// 	mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, x
	// 		* TILESIZE, y * TILESIZE);
	// else if (game->map[y][x] == 'P')
	// 	mlx_put_image_to_window(game->mlx, game->win, game->img_player, x
	// 		* TILESIZE, y * TILESIZE);
	// else if (game->map[y][x] == 'E')
	// 	mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x
	// 		* TILESIZE, y * TILESIZE);
	// else if (game->map[y][x] == 'S')
	// 	mlx_put_image_to_window(game->mlx, game->win, game->img_exit_player, x
	// 		* TILESIZE, y * TILESIZE);