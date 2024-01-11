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

void	to_organize(t_stack *a, t_stack *b)
{
	t_stack *temp;
	int size_b;

	size_b = 1;
	temp = b;
	sort_three(&a);
	while (size_b)
	{
		while (temp != NULL)
		{
			temp->target = get_target(temp, a);

			temp->cost = find_cost(temp, temp->target);
			temp = temp->next;
		}
		to_init_move(b->first);
		size_b = find_size(temp->first);
	}
/* 	while(b)
	{
		printf("b%ld, %ld, %d \n", b->number, b->target->number, b->cost);
		b = b->next;
	}
	temp = a->first;
	while(temp)
	{
		printf("%ld, %d \n", temp->number, temp->cost);
		temp = temp->next;
	} */
}
/* void	sort(t_stack *a, t_stack *b)
{
	//t_stack *head;
	
	pb(&a, &b);
	pb(&a, &b);
	//head = a;
	while (a)
	{	
		while (a)
		{
			a->target = get_target(a, b);
			a->cost = find_cost(a, a->target);
			printf("%d\n", a->cost);
			a = a->next;
		}
		//move(a, b);
	}
} */

t_stack	*get_target(t_stack *reference, t_stack *to_search)
{
	t_stack *target;
	t_stack *aux;
	
	target = to_search->first;
	aux = to_search->first;
	while (aux != NULL)
	{
		if (aux->number > reference->number)
			target = aux;
		aux = aux->next;
	}
	aux = to_search->first;
	while (aux != NULL)
	{
		if (reference->number < aux->number && \
			to_search->number < target->number)
			target = aux;
		aux = aux->next;
	}
	return (target);
}

int	find_cost(t_stack *ref, t_stack *target)
{
	int b_cost;

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

	ref->size = get_last(ref->first);
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


