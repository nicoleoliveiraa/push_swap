/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:21:31 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/05 20:14:39 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	to_sort(t_stack **a)
{
	t_stack	*b;
	int		a_size = 0;

	b = NULL;
	a_size = find_size(a);
	if (a_size-- > 3 && !is_sorted(*a))
		pb(a, &b, 1);
	if (a_size-- > 3 && !is_sorted(*a))
		pb(a, &b, 1);
	if (a_size > 3 && !is_sorted(*a))
		move_to_b(a, &b);
	sort_three(a);
	while (b)
	{
		init_b(a, &b);
		move_to_a(&b, a);
	}
	check_index(*a);
	free_stack(&b, free);
}

void	move_to_b(t_stack **a, t_stack **b)
{
	int		a_size;
	long	big;
	long	small;
	int		middle;

	a_size = find_size(a);
	while (a_size > 3 && !is_sorted(*a))
	{
		big = find_big(*a);
		small = find_small(*a);
		middle = small + ((big - small) / 2);
		push_middle(a, b, middle);
		a_size = find_size(a);
	}
}

void	push_middle(t_stack **a, t_stack **b, int middle)
{
	int	a_size;
	int	how_much;

	a_size = find_size(a);
	how_much = how_much_middle(*a, middle);
	while ((how_much > 0) && (a_size > 3) && !is_sorted(*a))
	{
		check_index(*a);
		before_push(a, under_node(*a, middle), 'a');
		if ((*a)->number < middle)
		{
			pb(a, b, 1);
			how_much--;
			a_size--;
		}
		else
			ra(a, 1);
	}
}

t_stack	*under_node(t_stack *stack, int middle)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->number < middle)
			return (temp);
		temp = temp->next;
	}
	return (stack);
}

int	how_much_middle(t_stack *a, int middle)
{
	int	how_much;

	how_much = 0;
	while (a)
	{
		if (a->number < middle)
			how_much++;
		a = a->next;
	}
	return (how_much);
}
