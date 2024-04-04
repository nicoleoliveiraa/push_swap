/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:12:16 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/04 15:21:41 by nsouza-o         ###   ########.fr       */
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

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (tmp->number < stack->number)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}

long	find_big(t_stack *stack)
{
	long big;
	
	big = stack->number;
	while(stack)
	{
		if(stack->number > big)
			big = stack->number;
		stack = stack->next;
	}
	return (big);
}

long	find_small(t_stack *stack)
{
	long small;
	
	small = stack->number;
	while(stack)
	{
		if(stack->number < small)
			small = stack->number;
		stack = stack->next;
	}
	return (small);
}

void	print_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		printf("%d %ld %d %d %d\n", tmp->index, tmp->number, tmp->cost, tmp->cheapest, tmp->middle_check);
		tmp = tmp->next;
	}
}