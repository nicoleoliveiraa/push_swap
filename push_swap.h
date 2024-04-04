/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:36:31 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/04 15:27:37 by nsouza-o         ###   ########.fr       */
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
# include <stdbool.h>

typedef struct s_stack
{
	long int		number;
	int				index;
	int				cheapest;
	int				cost;
	int				middle_check;
	int				size;
	struct s_stack	*max;
	struct s_stack	*min;
	struct s_stack	*first;
	struct s_stack	*target;
	struct s_stack	*next; 
}	t_stack;

//check parameters
int	check_number(int argc, char **argv);
int	check_rep(int argc, char **argv);
int	check_int(int argc, char **argv);
int	check_order(int argc, char **argv);
int	check_parameters(int argc, char **argv);

//sort algorithm
void		sort_two(t_stack **a);
void		sort_three(t_stack **a);

//get elements
t_stack		*get_elements(int argc, char **argv);
long int	ft_atol(char *nptr);

//operations
void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack **stack_b, t_stack **stack_a);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

//stack
t_stack	*ft_lstnew(int nb, int index);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int find_size(t_stack *a);

//to_sort_b_a
void	init_b(t_stack **a, t_stack **b);
void	find_target(t_stack **src, t_stack **dst);
t_stack	*find_node(t_stack *stack, long number);
void	find_cost(t_stack **src, t_stack **dst);
void	get_cost(t_stack *src, int size_src, int size_dst);
void	find_cheapest(t_stack **stack);
t_stack	*find_cheapest_node(t_stack *stack);
void	move_to_a(t_stack **b, t_stack **a);
void	before_push(t_stack **stack, t_stack *cheapest, char stack_name);
void	move_together_up(t_stack **a, t_stack **b, t_stack *cheapest);
void	move_together_down(t_stack **a, t_stack **b, t_stack *cheapest);

//to_sort
void	to_sort(t_stack **a);
void	move_to_b(t_stack **a, t_stack **b);
void	check_index(t_stack *stack);
void	push_middle(t_stack **a, t_stack **b, int middle);
int	how_much_middle(t_stack *a, int middle);
void	free_stack(t_stack **stack, void(*del)(void *));
void	make_free(void *ptr);
t_stack	*under_node(t_stack *stack, int middle);

//utils
size_t		ft_strlen(char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);
t_stack *find_max(t_stack *stack);
int	is_sorted(t_stack *stack);
long	find_big(t_stack *stack);
long	find_small(t_stack *stack);
void	print_stack(t_stack **stack);


void final_move(t_stack **stack_a);

//bonus
int	check_moves(t_stack **a, t_stack **b);
int	check_and_do_moves(t_stack **a, t_stack **b, char *line);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_line(int fd);
int	ft_strchr(char *str, char c);










#endif