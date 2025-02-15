/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:13:16 by abertran          #+#    #+#             */
/*   Updated: 2023/03/08 20:35:05 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Swaps the top 2 elements of a stack. 
    Does nothing if there is only one or no elements. */

static void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

/*	Swaps the top 2 elements of stack a. Prints "sa" to the standard output. */

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

/*	Swaps the top 2 elements of stack b. Prints "sb" to the standard output. */

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

/*	Swaps the top 2 elements of stack a and the top 2 elements
	of stack b. Prints "ss" to the standard output. */

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}
