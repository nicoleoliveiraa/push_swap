#include "push_swap.h"

void	to_init_move(t_stack **a, t_stack **b)
{
	t_stack *temp;
	int i;

	i = get_cheapest(b);
	temp = *b;
	if (find_size(*b) == 1)
		to_move_one(a, b);
	else
	{
		while (temp)
		{
			if (temp->index == i)
				break;
			temp = temp->next;
		}
		//printf("%ld\n\n", temp->number);
		to_move(a, b, temp);
	}
}

void	to_move_one(t_stack **a, t_stack **b)
{
	t_stack *target;
	int i;
	int size;

	target = (*b)->target;
	if (target->middle_check == 0)
	{
		i = target->index;
		move_up(a, i);
	}
	else
	{
		size = find_size(target);
		i = size - target->index + 1;
		move_down(a, i);
	}
}

void	start_stack(t_stack **b)
{
	check_index(b);
	check_middle(*b);
	while(*b)
	{
		(*b)->cheapest = 0;
		(*b) = (*b)->next;
	}
}

int	get_cheapest(t_stack **stack_b)
{
	t_stack *move;
	t_stack *temp;

	temp = *stack_b;
	move = *stack_b;
	while (temp)
	{
		//temp->cheapest = 0;
		if (temp->cost < move->cost)
			move = temp;
		temp = temp->next;
	}
	return (move->index);
}

void	check_middle(t_stack *stack)
{
	int size;
	t_stack *temp;

	size = find_size(stack);
	size = size / 2;
	temp = stack->first;
	while(size--)
	{
		temp->middle_check = 0;
		temp = temp->next;
	}
	while (temp)
	{
		temp->middle_check = 1;
		temp = temp->next;
	}
}

void to_move(t_stack **a, t_stack **b, t_stack *move)
{
	t_stack *target;

	target = move->target;
	if (move->middle_check == target->middle_check)
	{
		//printf("\n-1\n");
		move_together(move, target, a, b);
	}
	else
	{
		//printf("\n-2\n");
		move_apart(move, target, a, b);
	}
}

void	move_together(t_stack *move, t_stack *target, t_stack **a, t_stack **b)
{
	int m;
	int t;

	if(move->middle_check == 0)
	{
		m = move->index;
		t = target->index;
		move_together_up(m, t, a, b);
	}
	if(move->middle_check == 1)
	{
		m = find_size(move->first) - move->index + 2;
		t = find_size(target->first) - target->index + 2;
		move_together_down(m, t, a, b);
	}
}

void	move_together_up(int m, int t, t_stack **a, t_stack **b)
{
	while (m > 1 && t > 1)
	{
		rr((*a), (*b));
		m--;
		t--;
	}
	if (m > 1)
	{
		while (m > 1)
		{
			rb((*b));
			m--;
		}
	}
	if (t > 1)
	{
		while (t > 1)
		{
			ra((*a));
			t--;
		}
	}
}

void	move_together_down(int m, int t, t_stack **a, t_stack **b)
{
	while (m > 1 && t > 1)
	{
		rrr(a, b);
		m--;
		t--;
	}
	if (m > 1)
	{
		while (m > 1)
		{
			rrb(b);
			m--;
		}
	}
	else
	{
		while (t > 1)
		{
			rra(a);
			t--;
		}
	}
}

void move_apart(t_stack *move, t_stack *target, t_stack **a, t_stack **b)
{
	int m;
	int t;

	if(move->middle_check == 0 && target->middle_check == 1)
	{
		m = move->index;
		t = find_size(target->first) - target->index + 1;
		move_up(b, m);
		move_down(a, t);
	}
	else
	{
		m = find_size(move->first) - move->index + 1;
		t = target->index;
		move_up(a, t);
		move_down(b, m);
	}
}

void	move_up(t_stack **stack, int i)
{
	while (i > 1)
	{
		ra(*stack);
		i--;
	}
}

void	move_down(t_stack **stack, int i)
{

//	printf("e%d\n", i);
	while (i >= 1)
	{
		rra(stack);
		i--;
	}
}