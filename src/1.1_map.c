#include "../includes/header.h"

void	check_map(t_struct *game);
void	trim_newlines(t_struct *game);
void	is_rectangle(t_struct *game);
void	is_size(t_struct *game);
void	is_walls(t_struct *game);


void	check_map(t_struct *game)
{
	trim_newlines(game);
	is_rectangle(game); //nope
	is_size(game);
	is_walls(game); //yes
	is_valid_characters(game);
}

void	is_rectangle(t_struct *game)
{
	int	width;
	int	temp;
	int	i;

	width = -1;
	i = 0;
	while (game->map[i] && i < game->lines)
	{
		temp = ft_strlen(game->map[i]);
		if (width == -1)
			width = temp;
		if (temp != width)
			exit_printf(game, "Error: Map is not a rectangle", 2);
		i++;
	}
	game->columns = width;
    //printf("columns=%d, l", game->columns);
}

void	trim_newlines(t_struct *game)
{
	int		i;
	int		count;
	char	*nl;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		nl = ft_strchr(game->map[i], '\n');
		if (nl)
			*nl = '\0';
		if (game->map[i][0] != '\0')
			count++;
		i++;
	}
	game->lines = count;
	return ;
}

void	is_size(t_struct *game)
{
	if (game->lines < 5 || game->columns < 3)
		exit_printf(game, "Error: Map is too small: minimum 3*5 (x*y)", 2);
}

void	is_walls(t_struct *game)
{
	int	j;

	j = 0;
	while (j < game->columns)
	{
		if (game->map[0][j] != '1' || game->map[game->lines - 1][j] != '1')
			exit_printf(game, "Error: Map not fully enclosed by walls", 2);
		j++;
	}
	j = 0;
	while (j < game->lines)
	{
		if (game->map[j][0] != '1' || game->map[j][game->columns - 1] != '1')
			exit_printf(game, "Error: Map not fully enclosed by walls", 2);
		j++;
	}
	return ;
}