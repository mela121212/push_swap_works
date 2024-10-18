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

/*	Pushes all the elements of stack a into stack b, except the three last.
	Smaller values first, then the larger values to help with efficiency.*/

static void	push_init(t_stack **stack_a, t_stack **stack_b)
{
	int	pushes_to_b;
	int	stack_size;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushes_to_b = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushes_to_b < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushes_to_b++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (stack_size - pushes_to_b > 3)
	{
		pb(stack_a, stack_b);
		pushes_to_b++;
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
	lowest_p = position_lowest_index(stack_a);
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

void    sort_3(t_stack **stack_a)
{
    if ((*stack_a)->next->index < (*stack_a)->index)
        sa(stack_a);
    if ((*stack_a)->next->next->index < (*stack_a)->next->index)
    {
        rra(stack_a);
        if ((*stack_a)->next->index < (*stack_a)->index)
            sa(stack_a);
    }
}

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
