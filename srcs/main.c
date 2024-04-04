/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:36:19 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/04 15:20:49 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void final_move(t_stack **stack_a)
{
	t_stack *small;

	small = find_node(*stack_a, find_small(*stack_a));
	while ((*stack_a) != small)
	{
		if (small->middle_check == 1)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		exit(1);
	if (!check_parameters(argc, argv))
		return (0);
	stack_a = get_elements(argc, argv);
	if(find_size(stack_a) == 2)
		sort_two(&stack_a);
	else if(find_size(stack_a) == 3)
		sort_three(&stack_a);
	else
		to_sort(&stack_a);
	final_move(&stack_a);
	free_stack(&stack_a, free);
	return (0);
}
