/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:10:18 by abertran          #+#    #+#             */
/*   Updated: 2023/02/23 18:34:18 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Counts and returns the number of nodes in the stack. */
int get_stack_size(t_stack *stack)
{
    int count;

    count = 0;
    while (stack)
    {
        stack = stack->next;
        count++;
    }
    return (count);
}

/* Creates a new node for the stack with the given value. */
t_stack *create_node(int value)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->value = value;
    node->index = 0;
    node->pos = -1;
    node->target = -1;
    node->cost_a = -1;
    node->cost_b = -1;
    node->next = NULL;
    return (node);
}

/* Adds a node to the bottom of the stack. */
void add_node(t_stack **stack, t_stack *new_node)
{
    t_stack *tail;

    if (!new_node)
        return;
    if (!*stack)
    {
        *stack = new_node;
        return;
    }
    tail = get_last_node(*stack);
    tail->next = new_node;
}

/* Returns the last node in the stack. */
t_stack *get_last_node(t_stack *stack)
{
    while (stack && stack->next)
        stack = stack->next;
    return (stack);
}

/* Returns the node before the last node in the stack. */
t_stack *get_second_last_node(t_stack *stack)
{
    while (stack && stack->next && stack->next->next)
        stack = stack->next;
    return (stack);
}
