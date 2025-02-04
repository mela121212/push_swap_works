/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:01:19 by abertran          #+#    #+#             */
/*   Updated: 2023/03/10 12:06:38 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Checks if a stack is sorted. 
    Returns 0 if the stack is not sorted, 1 if it is sorted. */

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* Sorts a stack of 3 elements by finding and positioning the largest element */
void	sort_three(t_stack **stack)
{
	int	biggest;
	t_stack	*tmp;

	if (is_sorted(*stack))
		return ;
	tmp = *stack;
	biggest = tmp->index;
	while (tmp)  // Encontrar el mayor índice
	{
		if (tmp->index > biggest)
			biggest = tmp->index;
		tmp = tmp->next;
	}
	if ((*stack)->index == biggest)
		ra(stack);
	else if ((*stack)->next->index == biggest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

/*	Pushes all the elements of stack a into stack b, except the three last.
	Smaller values first, then the larger values to help with efficiency.*/

static void	push_init(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushes;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushes = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushes < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushes++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (stack_size - pushes > 3)
	{
		pb(stack_a, stack_b);
		pushes++;
	}
}

/*	The stack a is almost sorted, rotate stack a until the lowest
	value is at the top. If it is in the bottom half of the stack, reverse
	rotate, otherwise rotate until it is at the top. */

static void	sort_stack(t_stack **stack_a)
{
	int	lowest_p;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_p = find_lowest_index_position(stack_a);
	if (lowest_p > stack_size / 2)
	{
		while (lowest_p < stack_size)
		{
			rra(stack_a);
			lowest_p++;
		}
	}
	else
	{
		while (lowest_p > 0)
		{
			ra(stack_a);
			lowest_p--;
		}
	}
}

/*	Sorting algorithm for a stack larger than 3.
	 Push everything but 3 numbers to stack B.
	 Sort the 3 numbers left in stack A.
	 Calculate the most cost-effective move.
	 Shift elements until stack A is in order. */

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_init(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		assign_target_positions(stack_a, stack_b);
		cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		sort_stack(stack_a);
}
