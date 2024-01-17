/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_organize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:21:14 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/01/03 16:35:40 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_organize(t_stack **a, t_stack **b)
{
	t_stack *temp;

	sort_three(a);
	while (b)
	{
		temp = *b;
		while (temp != NULL)
		{
			temp->target = get_target(temp, a);

			temp->cost = find_cost(temp, temp->target);
			temp = temp->next;
		}
		temp = *b;
		while(temp)
		{
			printf("b%ld %ld %d %d %d\n", temp->number, temp->target->number, temp->cost, temp->middle_check, temp->index);
			temp = temp->next;
		}
		temp = *a;
		check_middle(*a);
		while(temp)
		{
			printf("a%ld %d %d\n", temp->number, temp->middle_check, temp->index);
			temp = temp->next;
		}
		to_init_move(a, b);
		pa(b, a);
	}
	if(is_organized(a) == 1)
		final_move(a);
}

int	is_organized(t_stack **a)
{
	t_stack *temp;

	temp = *a;
	while ((temp))
	{
		if ((temp)->number > (temp)->next->number)
		{
			return (1);
		}
		(temp) = (temp)->next;
	}
	return (0);
}

void	final_move(t_stack **a)
{
	t_stack *first_number;
	int i;

	check_index(a);
	first_number = find_first(a);
	if (first_number->index < (find_size(*a) / 2))
		move_up(a, first_number->index);
	else
	{
		i = find_size(*a) - first_number->index + 1;
		move_down(a, i);
	}

}

t_stack	*find_first(t_stack **a)
{
	int big;
	t_stack *first;
	t_stack *temp;

	big = find_big(*a);
	temp = (*a);
	while (temp)
	{
		if (temp->number < big && temp->number < first->number)
			first = temp;
		temp = temp->next;
	}
	return (first);
}

t_stack	*get_target(t_stack *reference, t_stack **to_search)
{
	t_stack *target;
	t_stack *aux;
	
	target = *to_search;
	aux = *to_search;
	while (aux != NULL)
	{
		if (aux->number > reference->number)
			target = aux;
		aux = aux->next;
	}
	aux = *to_search;
	while (aux != NULL)
	{
		if (reference->number < aux->number && \
			aux->number < target->number)
			target = aux;
		aux = aux->next;
	}
	return (target);
}

int	find_cost(t_stack *ref, t_stack *target)
{
	int b_cost;

	if (ref->index == 1 && target->index == 1)
		return (1);
	get_middle_check(ref);
	get_middle_check(target);
	if (ref->middle_check == 1)
		b_cost = ref->size - ref->index + 2;
	else
		b_cost = ref->index;
	if (ref->middle_check == target->middle_check)
	{
		if (b_cost > target->cost)
			return (b_cost);
		else
			return (target->cost);
	}
	return(b_cost + target->cost);
} 

void get_middle_check(t_stack *ref)
{
	int middle;

	ref->size = get_last(ref);
	middle = ref->size / 2;
	if (ref->index > middle)
	{
		ref->cost = ref->size - ref->index + 1;
		ref->middle_check = 1;
	}
	else
	{
		ref->cost = ref->index;
		ref->middle_check = 0;
	}
}


