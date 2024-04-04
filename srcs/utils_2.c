/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:54:56 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/05 00:02:05 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_together_up(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while ((*b) != cheapest && (*a) != cheapest->target)
		rr(a, b, 1);
	check_index(*a);
	check_index(*b);
}

void	move_together_down(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while ((*a) != cheapest->target && (*b) != cheapest)
		rrr(a, b, 1);
	check_index(*a);
	check_index(*b);
}

void	print_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		printf("%d %ld %d %d %d\n", tmp->index, \
		tmp->number, tmp->cost, tmp->cheapest, tmp->middle_check);
		tmp = tmp->next;
	}
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
