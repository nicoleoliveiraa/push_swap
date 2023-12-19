/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:10:59 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/12/01 14:52:09 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_index(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack != NULL)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
}
