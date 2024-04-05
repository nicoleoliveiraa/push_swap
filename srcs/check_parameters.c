/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:54:34 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/05 20:51:06 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if ((argv[i][j] == '+' || argv[i][j] == '-') && \
					ft_isdigit(argv[i][j + 1]) && j == 0)
					j++;
				else
				{
					return (0);
				}
			}
			if (ft_isdigit(argv[i][j]))
				j++;
		}
	}
	return (1);
}

int	check_rep(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
			{
				return (0);
			}
			j++;
		}
	}
	return (1);
}

int	check_int(int argc, char **argv)
{
	long int	n;
	int			i;

	i = 0;
	while (++i < argc)
	{
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			return (0);
		}
	}
	return (1);
}

int	check_order(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		if (ft_atol(argv[i]) > ft_atol(argv[j]))
			return (1);
		i++;
	}
	return (0);
}

int	check_parameters(int argc, char **argv)
{
	if (!check_int(argc, argv))
		return (0);
	if (!check_number(argc, argv))
		return (0);
	if (!check_rep(argc, argv))
		return (0);
	return (1);
}
