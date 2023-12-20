/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_organize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:21:14 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/12/20 17:32:23 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_organize(t_stack *a, t_stack *b)
{
	//to_divide(a, b);
	if(find_size(a) == 2)
		sort_two(&a);
	if(find_size(a) == 3)
		sort_three(&a);
 else
		sort(a, b);
}
void	sort(t_stack *a, t_stack *b)
{
	t_stack *head;
	
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	head = a;
	while (a)
	{	
		while (a)
		{
			a->target = get_target(a, b);
			a->cost = find_cost(head, a, a->target);
			a = a->next;
		}
		move(a, b);
	}
}

t_stack	*get_target(t_stack *reference, t_stack *to_search)
{
	t_stack *target;
	
	target = to_search;
	while (to_search != NULL)
	{
		if (reference->number < to_search->number && \
			to_search->number < target->number)
			target = to_search;
		to_search = to_search->next;
	}
	return (target);
}

int	find_cost(t_stack *head, t_stack *a, t_stack *target)
{
	int size_a;
	int size_b;
	int cost_b;
	int cost_a;

	size_a = find_size(a);
	size_b = find_size(target);
	cost = 0;
	if (target->index > size_b / 2)
		cost = target->index - size_b;
	
}
