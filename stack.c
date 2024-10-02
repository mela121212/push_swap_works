/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmelag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:58:01 by carmelag          #+#    #+#             */
/*   Updated: 2024/10/02 10:58:03 by carmelag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/*	Creates a element(nodo) in the stack with the provided value.
	Returns the newly created stack element. */

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

/*	Adds an element to the bottom of a stack. */

void	stack_add(t_stack **stack, t_stack *new)
{
	t_stack	*bottom;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	bottom = get_tail(*stack);
	bottom->next = new;
}

t_stack *get_tail(t_stack *stack)
{
    while (stack != NULL && (stack)->next != NULL)
        stack = (stack)->next;
    return(stack);
}

t_stack *before_tail(t_stack *stack)
{
    while (stack != NULL && (stack)->next->next != NULL)
        stack = (stack)->next;
    return(stack);
}

int	stack_size(t_stack	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
