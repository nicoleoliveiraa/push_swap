/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2and3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:53:58 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/12/20 12:42:11 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if((*a)->next->number > (*a)->number)
		return ;
	sa(*a);
}

void	sort_three(t_stack **a)
{
	if ((*a)->number > (*a)->next->number && \
		(*a)->number > (*a)->next->next->number)
		ra(*a);
	if ((*a)->next->number > (*a)->number && \
	(*a)->next->number > (*a)->next->next->number)
		rra(a);
	if ((*a)->number > (*a)->next->number)
		sa(*a);
}
