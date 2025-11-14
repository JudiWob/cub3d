
#ifndef HEADER_H
# define HEADER_H

#include "../minilibx_opengl/mlx.h"
#include "../libft/libft.h"

// Linux:
// #define TILESIZE 32
// #define KEY_W 119
// #define KEY_S 115
// #define KEY_A 97
// #define KEY_D 100
// #define KEY_ESC 65307


//MAC:
#define TILESIZE 32
#define KEY_W 13
#define KEY_S 1
#define KEY_A 0
#define KEY_D 2
#define KEY_ESC 53


typedef struct s_game
{
    int     fd;
    char    **map;
    char    **map_cpy;
    void    *mlx;
    void    *win;
    void    *tex;
    void    *wall;
    void    *floor;
    void    *buff_img;  // the off-screen image
    char    *buff_addr;
    int     bpp;
    int     line_len;
    int     endian;
    int     lines;
	int     columns;

} t_struct;


//input
void	take_input(int argc, char **argv, t_struct **game);
void	init_struct(t_struct **game);
void	check_argv(int argc, char **argv, t_struct *game);
int		count_lines(char *argv1, t_struct *game);
void	read_map(char *argv1, t_struct *game);


//check map
void	check_map(t_struct *game);
void	trim_newlines(t_struct *game);
void	is_rectangle(t_struct *game);
void	is_size(t_struct *game);
void	is_walls(t_struct *game);

//map utils
void	is_valid_characters(t_struct *game);
void	copy_map(t_struct *game);


//open_window
void	open_window(t_struct *game);
void	init_mlx(t_struct *game);

//render
int	render_map(t_struct *game);
void	choose_color(int x, int y, t_struct *game);

//free
void	exit_printf(t_struct *game, char *message, int fd);

#endif