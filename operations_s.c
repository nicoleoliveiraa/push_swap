/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:36:27 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/12/04 12:35:51 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	s(t_stack *stack)
{
	int	nb_aux;

	if (stack->next == NULL || stack == NULL)
		return ;
	nb_aux = stack->number;
	stack->number = stack->next->number;
	stack->next->number = nb_aux;
}

void	sa(t_stack *stack_a)
{
	s(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	s(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
