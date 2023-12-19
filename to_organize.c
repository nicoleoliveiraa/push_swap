/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_organize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:31:45 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/12/19 15:15:40 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_v(int *v, int size)
{
	int i;
	int swap;

	i = 0;
	while (i < size)
	{
		if (v[i] > v[i + 1])
		{
			swap = v[i];
			v[i] = v[i + 1];
			v[i + 1] = swap;
			i = 0;
		}
		else
			i++;		
	}
}

int find_size(t_stack *a)
{
	int size;
	t_stack *temp;
	
	temp = a;
	while (temp->next != NULL)
		temp = temp->next;
	size = temp->index;
	return (size);
}

int	find_middle(t_stack *a)
{
	int	middle;
	int *v;
	int i;
	int size;

	i = 0;
	middle = 0;
	size = find_size(a);
	v = malloc(sizeof(int) * (size));
	while (a != NULL)
	{
		v[i] = a->number;
		a = a->next;
		i++;
	}
	order_v(v, size);
	middle = v[size / 2];
	return (middle);
}

void	to_divide(t_stack *a, t_stack* b)
{
	int	middle;
	t_stack *temp;
	int size;

	temp = a;
	size = find_size(a);
	while (size > 3)
	{
		middle = find_middle(a);
		printf("%d", middle);
		while (temp != NULL)
		{
			if (temp->number <= middle)
				temp->middle_check = 1;
			else
				temp->middle_check = 0;
			temp = temp->next;
		}
		temp = a;
		move(a, b, size);
		size = find_size(a);
	}
}

void move(t_stack *a, t_stack *b, int size)
{
	t_stack *aux;
	
	aux = a;
	while (size > 0)
	{
		if (aux->middle_check == 1)
			pb(&a, &b);
		else
			ra(a);
		//aux = aux->next;
		size--;
	}
}

//t_stack	*find_cost()

/* t_stack	*get_target(t_stack *reference, t_stack *to_search)
{
	t_stack *target;
	
	while (b != NULL)
	{
		if (reference->number > to_search->number && \
			to_search->number > target->number)
		{
			target = to_search;
		}
		to_search = to_search->next;
	}
	return (target);
} */

void	to_organize(t_stack *a, t_stack *b)
{
	to_divide(a, b);
	/* pa(&b, &a);
	pa(&b, &a);
	while (b)
	{	
		while (b != NULL)
		{
			b->target = get_target(b, a);
			b->cost = find_cost(reference, target);
			b = b->next;
		}
		move(a, b);
	}
	
	
	 */	
}
