#include "../includes/header.h"

void	is_valid_characters(t_struct *game);
void	copy_map(t_struct *game);


void	is_valid_characters(t_struct *game)
{
	int	i;
	int	j;
	int	p;

	i = -1;
	p = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
            || game->map[i][j] == 'E' || game->map[i][j] == 'W')
				p++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
				exit_printf(game, "Error: Map contains non valid character",
					 2);
		}
	}
	if (p != 1)
		exit_printf(game, "Error: One Player allowed", 2);
}


void	copy_map(t_struct *game)
{
	int	i;

	game->map_cpy = malloc(sizeof(char *) * (game->lines + 1));
	if (!game->map_cpy)
		exit(EXIT_FAILURE); //free_exit(game);
	i = 0;
	while (i < game->lines)
	{
		game->map_cpy[i] = ft_strdup(game->map[i]);
		if (!game->map_cpy[i])
			exit(EXIT_FAILURE); //free_exit(game);
		i++;
	}
	game->map_cpy[i] = NULL;
	return ;
}
