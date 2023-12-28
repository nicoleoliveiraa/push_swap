/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:31:45 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/12/20 14:54:37 by nsouza-o         ###   ########.fr       */
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
	printf("\n");
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

int	find_middle(t_stack *a)
{
	int	middle;
	long int *v;
	int i;
	int size;

	i = 0;
	middle = 0;
	size = find_size(a);
	v = (long int *)malloc(sizeof(long int) * size);
	while (i < size)
	{
		v[i] = find_min(a->first);
		printf("%ld\n", v[i]);
		i++;
	}
	middle = v[size / 2];
	free(v);
	return (middle);
}

void	to_divide(t_stack *a, t_stack* b)
{
	long int	middle;
	int size;
	int i;

	i = 0;
	size = find_size(a);
	while (size > 2)
	{
		middle = find_middle(a);
		//printf("%d", middle);
	 	while ((size / 2) > i)
		{
			if (a->first->number < middle)
			{
				pb(&a, &b);
			}
			else
				ra(a);
			i++;
		}
		//temp = temp->first;
		//printf("%d!", middle);
		//size = find_size(a->first);
		//size--;
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
		//printf("%d", aux->middle_check);
		//aux = aux->next;
		size--;
	}
}

//t_stack	*find_cost()




