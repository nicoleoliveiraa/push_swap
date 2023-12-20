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
	to_organize(stack_a, stack_b);
	//to_organize(stack_a, stack_b);
	//pb(&stack_a, &stack_b);
	//sort_three(&stack_a);
	//rra(&stack_a);
	/* stack_b = NULL;
	rr(stack_a, stack_b);
	//sa(stack_a);
	//pb(&stack_a, &stack_b);*/
/* 	while (stack_a != NULL)
	{
		printf("%ld %d\n", stack_a->number, stack_a->index);
		stack_a = stack_a->next;
	} */
 	/* while (stack_a != NULL)	
	{
		printf("stack_A %ld\n", stack_a->number);
		stack_a = stack_a->next;
	}
	//sb(stack_b);
 	while (stack_b != NULL)
	{
		printf("stack_B %ld\n", stack_b->number);
		stack_b = stack_b->next;
	} */
	return (0);
}