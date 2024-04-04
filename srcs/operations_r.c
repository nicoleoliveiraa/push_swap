/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:46:38 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/04 23:54:13 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*first;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = (*stack);
	temp = (*stack)->next;
	(*stack) = temp;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
	check_index((*stack));
}

void	ra(t_stack **stack_a, int i)
{
	rotate(stack_a);
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int i)
{
	rotate(stack_b);
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int i)
{
	rotate(stack_a);
	rotate(stack_b);
	if (i == 1)
		write(1, "rr\n", 3);
}
