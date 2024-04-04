/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:09:12 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/04 18:14:55 by nsouza-o         ###   ########.fr       */
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
		if ((unsigned char)str[i] == (unsigned char)c)
			return (0);
		i++;
	}
	return (1);
}

char	*get_line(int fd)
{
	char	*line;
	int bytes;
	int	i;

	i = 0;
	line = malloc(sizeof(char) * (5));
	if (!line)
		return (NULL);
	bytes = read(fd, line, 5);
	if (bytes == -1 || bytes == 5)
	{
		free(line);
		return (NULL);
	}
	while (line && line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	if (!line)
		return (NULL);
	return (line);
}
