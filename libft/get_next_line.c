/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:28:54 by jpaselt           #+#    #+#             */
/*   Updated: 2025/05/18 15:03:38 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*leftover(char **leftovers, char *result)
{
	ssize_t	len;
	ssize_t	i;

	i = nl_check(result);
	len = ft_strlen(&result[i]);
	if (len == 0)
	{
		return (result);
	}
	*leftovers = malloc(len + 1);
	if (!*leftovers)
		return (NULL);
	ft_strcpy(*leftovers, &result[i]);
	(result)[i] = '\0';
	return (result);
}

char	*read_save(int fd, char **buffer, int *bytesread, char **result)
{
	*bytesread = read(fd, *buffer, BUFFER_SIZE);
	if (*bytesread == 0 && (*result)[0] == '\0')
	{
		free(*result);
		*result = NULL;
		free(*buffer);
		return (*result);
	}
	if (*bytesread == 0)
		return (free(*buffer),*result);
	(*buffer)[*bytesread] = '\0';
	join(result, *buffer);
	return (*result);
}

char	*get_next_line(int fd)
{
	int			bytesread;
	char		*buffer;
	char		*result;
	static char	*leftovers;

	result = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		if (leftovers)
		{
			free(leftovers);
			leftovers = NULL;
		}
		return (result);
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (result);
	buffer[BUFFER_SIZE] = '\0';
	if (!duplicate(&result, &leftovers))
		return (result);
	while (nl_check(result) == 0)
		if (!read_save(fd, &buffer, &bytesread, &result) || bytesread == 0)
			return (result);
	return (free (buffer), leftover(&leftovers, result));
}
