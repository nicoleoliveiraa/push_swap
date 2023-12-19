/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:21:24 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/12/04 12:36:34 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	check_index(*stack);
}

void	rra(t_stack **stack_a)
{
	r_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	r_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	write(1, "rrr\n", 4);
}
