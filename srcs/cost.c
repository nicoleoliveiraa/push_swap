/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:53:02 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/05 20:10:26 by nsouza-o         ###   ########.fr       */
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
	t_stack	*temp_dst;
	t_stack	*temp_src;

	temp_src = *src;
	while ((temp_src))
	{
		best = LONG_MAX;
		temp_dst = *dst;
		while (temp_dst)
		{
			if (temp_dst->number > temp_src->number && temp_dst->number < best)
			{
				best = temp_dst->number;
				temp_src->target = temp_dst;
			}
			temp_dst = temp_dst->next;
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
	int		size_src;
	int		size_dst;
	t_stack	*temp;

	size_src = find_size(src);
	size_dst = find_size(dst);
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
