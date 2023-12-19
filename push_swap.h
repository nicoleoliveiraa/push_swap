/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:36:31 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/12/19 15:16:09 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <strings.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_stack
{
	long int		number;
	int				index;
	int				cost;
	int				middle_check;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

t_stack		*get_elements(int argc, char **argv);
long int	ft_atol(char *nptr);
t_stack		*ft_lstnew(int nb, int index);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack **stack_b, t_stack **stack_a);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		check_index(t_stack *stack);
int			check_parameters(int argc, char **argv);

//utils
size_t		ft_strlen(char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);

//sort algorithm
void		sort_two(t_stack **a);
void		sort_three(t_stack **a);

//t_stack		*get_target(t_stack *a, t_stack *b);

//midle
void	to_organize(t_stack *a, t_stack *b);
void	to_divide(t_stack *a, t_stack* b);
void	move(t_stack *a, t_stack *b, int size);
int	find_middle(t_stack *a);
int find_size(t_stack *a);

#endif