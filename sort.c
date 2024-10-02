/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmelag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:56:28 by carmelag          #+#    #+#             */
/*   Updated: 2024/10/02 10:56:31 by carmelag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/*	Pushes all the elements of stack a into stack b, except the three last.
	Smaller values first, then the larger values to help with efficiency.*/

static void	push_init(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushes;
	int	i;

	size = stack_size(*stack_a);
	pushes = 0;
	i = 0;
	while (size > 6 && i < size && pushes < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			pushes++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (size - pushes > 3)
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
	int	size;

	size = stack_size(*stack_a);
	lowest_p = position_lowest_index(stack_a);
	if (lowest_p > size / 2)
	{
		while (lowest_p < size)
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
	sort_3(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		cost(stack_a, stack_b);
		cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		sort_stack(stack_a);
}
