/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:12:16 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/04 17:09:06 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	size;

	size = ft_strlen(s);
	write(fd, s, size);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	find_big(t_stack *stack)
{
	long	big;

	big = stack->number;
	while (stack)
	{
		if (stack->number > big)
			big = stack->number;
		stack = stack->next;
	}
	return (big);
}

long	find_small(t_stack *stack)
{
	long	small;

	small = stack->number;
	while (stack)
	{
		if (stack->number < small)
			small = stack->number;
		stack = stack->next;
	}
	return (small);
}
