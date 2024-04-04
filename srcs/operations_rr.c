/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:21:24 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/04 23:55:06 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	r_rotate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*previous;
	t_stack	*first;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = (*stack);
	current = (*stack);
	while (current->next != NULL)
	{
		previous = (*stack);
		current = (*stack)->next;
		(*stack) = (*stack)->next;
	}
	current->next = first;
	previous->next = NULL;
	(*stack) = current;
	check_index(first);
}

void	rra(t_stack **stack_a, int i)
{
	r_rotate(stack_a);
	if (i == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int i)
{
	r_rotate(stack_b);
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int i)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	if (i == 1)
		write(1, "rrr\n", 4);
}
