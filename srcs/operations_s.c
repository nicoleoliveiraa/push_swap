/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:36:27 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/04 23:56:45 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	s(t_stack *stack)
{
	int	nb_aux;

	if (stack->next == NULL || stack == NULL)
		return ;
	nb_aux = stack->number;
	stack->number = stack->next->number;
	stack->next->number = nb_aux;
}

void	sa(t_stack *stack_a, int i)
{
	s(stack_a);
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b, int i)
{
	s(stack_b);
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int i)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}
