/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:09:12 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/04 15:42:52 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*get_line(int fd)
{
	char	*line;
	int bytes;

	line = malloc(sizeof(char) * (5));
	if (!line)
		return (NULL);
	bytes = 1;
	while ((!ft_strchr(line, '\n') || !ft_strchr(line, '\0')) && bytes != 0)
	{
		bytes = read(fd, line, 5);
		if (bytes == -1)
		{
			free(line);
			return (NULL);
		}
		line[bytes] = '\0';
		if (!line)
			return (NULL);
	}
	return (line);
}