/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:36:36 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/04 15:21:20 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstnew(int nb, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->number = nb;
	new->index = index;
	new->cost = 0;
	new->cheapest = 0;
	new->middle_check = 0;
	new->first = NULL;
	new->min = NULL;
	new->max = NULL;
	new->target = NULL;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*aux;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	aux = *lst;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = new;
}

int find_size(t_stack *a)
{
	int size;
	t_stack *temp;
	
	size = 0;
	temp = a;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}
