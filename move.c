#include "push_swap.h"

void	to_init_move(t_stack *b)
{
	t_stack *move;
	
	move = NULL;
	while (b)
	{
		if (b->cost < move->cost)
			move = b;
		b = b->next;
	}
	to_move(move);
}

void to_move(t_stack *move)
{
	t_stack *target;

	target = move->target;
	if (move->middle_check == target->middle_check)
		move_together(move, target);
	else
		move_apart(move, target);
	pa(&move->first, &target->first);
}

void	move_together(t_stack *move, t_stack *target)
{
	int m;
	int t;

	if(move->middle_check == 0)
	{
		m = move->index;
		t = target->index;
		move_together_up(move, target, m, t);
	}
	else
	{
		m = find_size(move->first) - move->index + 1;
		t = find_size(target->first) - target->index + 1;
		move_together_down(move, target, m, t);
	}
}

void	move_together_up(t_stack *move, t_stack *target, int m, int t)
{
	while (m > 1 && t > 1)
	{
		rr(target->first, move->first);
		m--;
		t--;
	}
	if (m > 1)
	{
		while (m > 1)
		{
			rb(move->first);
			m--;
		}
	}
	else
	{
		while (t > 1)
		{
			ra(target->first);
			t--;
		}
	}
}

void	move_together_down(t_stack *move, t_stack *target, int m, int t)
{
	while (m > 1 && t > 1)
	{
		rrr(&target->first, &move->first);
		m--;
		t--;
	}
	if (m > 1)
	{
		while (m > 1)
		{
			rrb(&move->first);
			m--;
		}
	}
	else
	{
		while (t > 1)
		{
			rra(&target->first);
			t--;
		}
	}
}

void move_apart(t_stack *move, t_stack *target)
{
	int m;
	int t;

	if(move->middle_check == 0 && target->middle_check == 1)
	{
		m = move->index;
		t = find_size(target->first) - target->index + 1;
		move_up(move, m);
		move_down(target->first, t);
	}
	else
	{
		m = find_size(move->first) - move->index + 1;
		t = target->index;
		move_up(target, t);
		move_down(move->first, m);
	}
}

void	move_up(t_stack *move, int i)
{
	while (i > 1)
	{
		ra(move->first);
		i--;
	}
}

void	move_down(t_stack *move, int i)
{
	while (i > 1)
	{
		rra(&move->first);
		i--;
	}
}