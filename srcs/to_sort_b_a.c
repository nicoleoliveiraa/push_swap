/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sort_b_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:36:13 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/05 00:01:24 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_cheapest(t_stack **stack)
{
	t_stack	*cheapest_node;
	long	cheapest;
	t_stack	*temp;

	if (!(*stack))
		return ;
	temp = *stack;
	cheapest = LONG_MAX;
	while (temp)
	{
		if (temp->cost < cheapest)
		{
			cheapest = temp->cost;
			cheapest_node = temp;
		}
		else
			temp->cheapest = 0;
		temp = temp->next;
	}
	cheapest_node->cheapest = 1;
}

t_stack	*find_cheapest_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	move_to_a(t_stack **b, t_stack **a)
{
	t_stack	*cheapest;

	cheapest = find_cheapest_node(*b);
	if (cheapest->middle_check == 1 && cheapest->target->middle_check == 1)
	{
		move_together_up(a, b, cheapest);
	}
	else if (cheapest->middle_check == 0 && cheapest->target->middle_check == 0)
	{
		move_together_down(a, b, cheapest);
	}
	before_push(a, cheapest->target, 'a');
	before_push(b, cheapest, 'b');
	pa(b, a, 1);
}

void	before_push(t_stack **stack, t_stack *cheapest, char stack_name)
{
	while ((*stack) != cheapest)
	{
		if (stack_name == 'a')
		{
			if (cheapest->middle_check == 1)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (stack_name == 'b')
		{
			if (cheapest->middle_check == 1)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}
