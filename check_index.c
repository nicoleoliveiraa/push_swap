/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:10:59 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/01/03 15:13:48 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_index(t_stack **stack)
{
	int	i;

	i = 1;
	while ((*stack) != NULL)
	{
		(*stack)->index = i;
		i++;
		(*stack)->first = stack;
		(*stack)->middle_check = 0;
		(*stack)->max = find_max(stack);
		(*stack) = (*stack)->next;
	}
}

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
