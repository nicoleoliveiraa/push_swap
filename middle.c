/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:31:45 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/01/03 15:41:54 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_big(t_stack *list)
{
	int big;

	big = 0;
	while (list)
	{
		if (list->number > big)
			big = list->number;
		list = list->next;
	}
	return (big);
}

int	find_min(t_stack *list)
{
	long int min;
	t_stack	*aux;

	min = find_big(list);
	aux = list->first;
	while (list)
	{
		if (list->middle_check == 0)
		{
			if (list->number < min)
				min = list->number;
		}
		list = list->next;
	}
	while (aux)
	{
		if (min == aux->number)
		{
			aux->middle_check = 1;
			break;
		}
		aux = aux->next;
	}
	return (min);
}

int	find_middle(t_stack *a, int size)
{
	int	middle;
	long int *v;
	int i;

	i = 0;
	middle = 0;
	v = (long int *)malloc(sizeof(long int) * size);
	while (i < size)
	{
		v[i] = find_min(a->first);
		i++;
	}
	middle = v[size / 2];
	free(v);
	return (middle);
}

int get_last(t_stack *a)
{
	int i;

	i = 0;
	while (a->next != NULL)
		a = a->next;
	i = a->index;
	return (i);
}
void	to_divide(t_stack **a, t_stack **b)
{
	long int	middle;
	int size;
	int i;

	i = 0;
	size = find_size(*a);
	while (size > 3)
	{
		middle = find_middle(*a, size);
		i = get_last(*a);
	 	while (i-- >= 0)
		{
			if ((*a)->first->number <= middle)
			{
				if(find_size(*a) > 3)
					pb(a, b);
			}
			else
				ra(*a);
		}
		check_index(a);
		size = find_size(*a);
	}
	to_organize(a, b);
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
		size--;
	}
}




