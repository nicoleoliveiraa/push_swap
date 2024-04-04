/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:36:02 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/04 15:20:45 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long int	ft_atol(char *nptr)
{
	int			i;
	long int	signal;
	long int	number;

	signal = 1;
	i = 0;
	number = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signal = -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		number = (number * 10) + (nptr[i] - 48);
		i++;
	}
	return (signal * number);
}

t_stack	*get_elements(int argc, char **argv)
{
	int			i;
	long int	nb;
	t_stack		*a;
	t_stack		*aux;

	i = 1;
	a = NULL;
	while (i < argc)
	{
		nb = ft_atol(argv[i]);
		aux = ft_lstnew(nb, i);
		ft_lstadd_back(&a, aux);
		i++;
	}
	check_index(a);
	return (a);
}
