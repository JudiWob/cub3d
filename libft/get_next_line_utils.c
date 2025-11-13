/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:31:16 by jpaselt           #+#    #+#             */
/*   Updated: 2025/05/06 16:22:09 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*duplicate(char **result, char **leftovers)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(*leftovers);
	*result = malloc((len + 1));
	if (!*result)
		return (NULL);
	if (!*leftovers)
	{
		*result[0] = '\0';
		return (*result);
	}
	while ((*leftovers)[i])
	{
		(*result)[i] = (*leftovers)[i];
		i++;
	}
	result[0][i] = '\0';
	free(*leftovers);
	*leftovers = NULL;
	return (*result);
}

ssize_t	nl_check(char *s)
{
	ssize_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*join(char **result, char *buffer)
{
	char	*joined;

	joined = malloc(ft_strlen(buffer) + ft_strlen(*result) + 1);
	if (!joined)
	{
		free(*result);
		*result = NULL;
		return (*result);
	}
	ft_strcpy(joined, *result);
	ft_strcpy(&joined[ft_strlen(*result)], buffer);
	free(*result);
	*result = joined;
	return (*result);
}
