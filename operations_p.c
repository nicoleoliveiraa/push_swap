/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:36:23 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/03 15:53:48 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **fst, t_stack **sec)
{
	t_stack	*aux;

	if (*fst == NULL)
		return ;
	aux = (*fst);
	(*fst) = (*fst)->next;
	aux->next = (*sec);
	(*sec) = aux;
	check_index((*fst));
	check_index((*sec));
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
