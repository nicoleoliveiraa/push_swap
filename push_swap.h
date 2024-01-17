/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:36:31 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/12/21 11:43:51 by nsouza-o         ###   ########.fr       */
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

/* typedef struct s_info
{
	t_stack *first;
}	t_info; */

//sort algorithm
void		sort_two(t_stack **a);
void		sort_three(t_stack **a);

void		check_index(t_stack **stack);

//midle
void	to_divide(t_stack **a, t_stack **b);
void	move(t_stack *a, t_stack *b, int size);
int	find_middle(t_stack *a, int size);
int find_size(t_stack *a);

void	to_organize(t_stack **a, t_stack **b);
t_stack	*get_target(t_stack *reference, t_stack **to_search);




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
int			check_parameters(int argc, char **argv);

//utils
size_t		ft_strlen(char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);



//cost
int	find_cost(t_stack *reference, t_stack *target);
void get_middle_check(t_stack *ref);

int get_last(t_stack *stack);
int	find_min(t_stack *list);
t_stack *find_max(t_stack *stack);

//move
void	to_init_move(t_stack **a, t_stack **b);
void to_move(t_stack **a, t_stack **b, t_stack *move);
void	move_together(t_stack *move, t_stack *target, t_stack **a, t_stack **b);
void	move_together_up(int m, int t, t_stack **a, t_stack **b);
void	move_together_down(int m, int t, t_stack **a, t_stack **b);
void move_apart(t_stack *move, t_stack *target, t_stack **a, t_stack **b);
void	move_up(t_stack **stack, int i);
void	move_down(t_stack **stack, int i);

void	start_stack(t_stack **b);
int	get_cheapest(t_stack **stack_b);
void	check_middle(t_stack *stack);
void	to_move_one(t_stack **a, t_stack **b);

t_stack	*find_first(t_stack **a);
void	final_move(t_stack **a);
int	is_organized(t_stack **a);
int find_big(t_stack *list);

#endif