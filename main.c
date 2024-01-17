/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:36:19 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/12/20 12:27:21 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!check_parameters(argc, argv))
		return (0);
	stack_a = get_elements(argc, argv);
	if(find_size(stack_a) == 2)
	{
		sort_two(&stack_a);
		return (0);
	}
	else if(find_size(stack_a) == 3)
	{
		sort_three(&stack_a);
		return (0);
	}
	else
		to_divide(&stack_a, &stack_b);
	while(stack_a)
	{
		printf("%ld\n", stack_a->number);
		stack_a = stack_a->next;
	}
	
	return (0);
}