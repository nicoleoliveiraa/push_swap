/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:10:59 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/02 18:29:49 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	check_index(t_stack **stack)
{
	int	i;
	int median;

	i = 0;
	if (!(*stack))
		return ;
	median = find_size(*stack) / 2;
	while (*stack)
	{
		(*stack)->index = i;
		if (i <= median)
			(*stack)->middle_check = 1;
		else
			(*stack)->middle_check = 0;
		i++;		
		(*stack) = (*stack)->next;
	}
} */

t_stack *find_max(t_stack *stack)
{
	t_stack *max;

	max = stack;
	while (stack)
	{
		if (stack->number > max->number)
			max = stack;
		stack = stack->next;
	}
	return (max);
}
