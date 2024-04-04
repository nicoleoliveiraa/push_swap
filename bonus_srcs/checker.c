/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:52:43 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/04 18:20:52 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
	{
		if (i == (n - 1))
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_and_do_moves(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "sa", 3))
		sa(*a);
	else if (!ft_strncmp(line, "sb", 3))
		sb(*b);
	else if (!ft_strncmp(line, "ss", 3))
		ss(*a, *b);
	else if (!ft_strncmp(line, "pa", 3))
		pa(b, a);
	else if (!ft_strncmp(line, "pb", 3))
		pb(a, b);
	else if (!ft_strncmp(line, "ra", 3))
		ra(a);
	else if (!ft_strncmp(line, "rb", 3))
		rb(b);
	else if (!ft_strncmp(line, "rr", 3))
		rr(a, b);
	else if (!ft_strncmp(line, "rra", 4))
		rra(a);
	else if (!ft_strncmp(line, "rrb", 4))
		rrb(b);
	else if (!ft_strncmp(line, "rrr", 4))
		rrr(a, b);
	else
		return (0);
	return (1);
}

int	check_moves(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_line(0);
	while (line)
	{
		if (!ft_strncmp(line, "", 1))
			return (1);
		if (!check_and_do_moves(a, b, line))
		{
			free(line);	
			return (0);
		}
		free(line);
		line = get_line(0);
	}
	if (!line)
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);

}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	if (!check_parameters(argc, argv))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	stack_a = get_elements(argc, argv);
	stack_b = NULL;
	if (!check_moves(&stack_a, &stack_b))
	{
		write(2, "Error\n", 6);
		free_stack(&stack_a, make_free);
		free_stack(&stack_b, make_free);
		exit(1);
	}
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a, make_free);
	return (0);
}