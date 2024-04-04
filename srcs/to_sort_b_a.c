/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sort_b_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:36:13 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/04 15:21:24 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_b(t_stack **a, t_stack **b)
{
	check_index(*a);
	check_index(*b);
	find_target(b, a);
	find_cost(b, a);
	find_cheapest(b);
}

void	find_target(t_stack **src, t_stack **dst)
{
	long	best;
	t_stack	*temp;
	t_stack	*temp_src;

	temp_src = *src;
	while ((temp_src))
	{
		best = LONG_MAX;
		temp = *dst;
		while (temp)
		{
			if (temp->number > (temp_src)->number && temp->number < best)
			{
				best = temp->number;
				(temp_src)->target = temp;
			}
			temp = temp->next;
		}
		if (best == LONG_MAX)
		{
			best = find_small(*dst);
			(temp_src)->target = find_node(*dst, best);
		}
		(temp_src) = (temp_src)->next;
	}
}

t_stack	*find_node(t_stack *stack, long number)
{
	while (stack)
	{
		if (stack->number == number)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	find_cost(t_stack **src, t_stack **dst)
{
	int	size_src;
	int	size_dst;
	t_stack	*temp;

	size_src = find_size(*src);
	size_dst = find_size(*dst);
	temp = *src;
	while (temp)
	{
		get_cost(temp, size_src, size_dst);
		temp = temp->next;
	}
}

void	get_cost(t_stack *src, int size_src, int size_dst)
{
	src->cost = src->index;
	if (src->middle_check == 0)
		src->cost = size_src - src->index;
	if (src->target->middle_check == 1)
	{
		if (src->middle_check == 0)
			src->cost = src->target->index + size_src - src->index;
		else if (src->cost < src->target->index)
			src->cost = src->target->index;
	}
	else
	{
		if (src->middle_check == 1)
			src->cost += size_dst - src->target->index;
		else if (src->cost < (size_dst - src->target->index))
			src->cost = size_dst - src->target->index;
	}
}

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
	t_stack *cheapest;
	
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
	pa(b, a);
}

void	before_push(t_stack **stack, t_stack *cheapest, char stack_name)
{
	while ((*stack) != cheapest)
	{
		if (stack_name == 'a')
		{
			if (cheapest->middle_check == 1)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (cheapest->middle_check == 1)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_together_up(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while ((*b) != cheapest && (*a) != cheapest->target)
		rr(a, b);
	check_index(*a);
	check_index(*b);
}

void	move_together_down(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while ((*a) != cheapest->target && (*b) != cheapest)
		rrr(a, b);
	check_index(*a);
	check_index(*b);
}