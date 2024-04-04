/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2and3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:53:58 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/04 23:58:55 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->next->number > (*a)->number)
		return ;
	sa(*a, 1);
}

void	sort_three(t_stack **a)
{
	if ((*a)->number > (*a)->next->number && \
		(*a)->number > (*a)->next->next->number)
		ra(a, 1);
	if ((*a)->next->number > (*a)->number && \
	(*a)->next->number > (*a)->next->next->number)
		rra(a, 1);
	if ((*a)->number > (*a)->next->number)
		sa(*a, 1);
}
