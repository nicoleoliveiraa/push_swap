/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:10:59 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/01/03 15:13:48 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_index(t_stack *stack, t_stack **head)
{
	int	i;

	i = 1;
	while (stack != NULL)
	{
		stack->index = i;
		stack->first = (*head);
		i++;
		stack = stack->next;
	}
}
