/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:50:31 by abertran          #+#    #+#             */
/*   Updated: 2023/02/23 19:37:55 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack *find_min(t_stack **stack_a)
{
    t_stack *min_node;
    t_stack *stack;

    if (*stack_a == NULL)
        return NULL;
    min_node = *stack_a;
    stack = *stack_a;
    while (stack)
    {
        if (stack->value < min_node->value)
            min_node = stack;
        stack = stack->next;
    }
    return min_node;
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

static void    sort_4(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *min;

    min = find_min(stack_a);
    if (min == NULL)
        return;
    if ((*stack_a)->next->next->next->index == min->index)
        rra(stack_a);
    else if ((*stack_a)->next->next->index == min->index)
    {
        ra(stack_a);
        ra(stack_a);
    }
    else if ((*stack_a)->next->index == min->index)
        ra(stack_a);
    if(is_sorted(*stack_a) != -1)
    {
        pb(stack_a, stack_b);
	    sort_3(stack_a);
	    pa(stack_b, stack_a);
    }
}

static void    sort_5(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *min;

    min = *stack_a;
    while (min && min->index != 0)
        min = min->next;

    if (min == NULL)
        return;
    if ((*stack_a)->next->next->next->next->index == min->index)
        rra(stack_a);
    else if ((*stack_a)->next->next->next->index == min->index)
    {
        rra(stack_a);
        rra(stack_a);
    }
    else if ((*stack_a)->next->next->index == min->index)
    {
        ra(stack_a);
        ra(stack_a);
    }
    else if ((*stack_a)->next->index == min->index)
        ra(stack_a);
    if(is_sorted(*stack_a) != -1)
    {
        pb(stack_a, stack_b);
        sort_4(stack_a, stack_b);
        pa(stack_b, stack_a);
    }
}

void    simple_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
    if((size == 0) || (size == 1))
        return;
    if(size == 3)
        sort_3(stack_a);
    if(size == 4)
        sort_4(stack_a, stack_b);
    if(size == 5)
        sort_5(stack_a, stack_b);
}