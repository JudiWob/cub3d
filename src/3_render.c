#include "../includes/header.h"

int	render_map(t_struct *game);
void draw_image(t_struct *game, void *texture, int draw_start_h, int draw_start_w );
void draw_to_buffer(t_struct *game, void *texture, int draw_start_h, int draw_start_w );
void load_images(t_struct *game);

int	render_map(t_struct *game)
{
	int y;
    int x;

    y = 0;
    x = 0;
    printf("MAP SIZE: lines=%d, columns=%d\n", game->lines, game->columns);
    while(y < game->lines)
    {
        x = 0;

        while(x < game->columns)
        {
            if(game->map[y][x] == '1')
                draw_to_buffer(game, game->wall, y * TILESIZE, x * TILESIZE);
            if(game->map[y][x] == '0')
                draw_to_buffer(game, game->floor, y * TILESIZE, x * TILESIZE);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->buff_img, 0, 0);
	return (0);
}

void draw_to_buffer(t_struct *game, void *texture, int draw_start_h, int draw_start_w )
{
    int tex_bpp;
    int line_len;
    int endian;
    char *tex_addr;
    int pix_y;//y-coordinaete of pixel in texture that will be drawn to window
    int pix_x; //x-coordinate of the pixel in texture that will be drawn to window
    int h;
    int w;
    int color;
    
    tex_addr = mlx_get_data_addr(texture, &tex_bpp, &line_len, &endian);
    h = draw_start_h;
    while (h < draw_start_h + TILESIZE)
    {
        w = draw_start_w;
        while (w < draw_start_w + TILESIZE)
        {
            pix_y = (int)((float)(h - draw_start_h) / TILESIZE * 128);
            pix_x = (int)((float)(w - draw_start_w) / TILESIZE * 128);
            color = *(int *)(tex_addr + (pix_y * line_len + pix_x * (tex_bpp / 8)));
            *(int *)(game->buff_addr + (h * game->line_len + w * (game->bpp / 8))) = color;
            w++;
        }
        h++;
    }
}
