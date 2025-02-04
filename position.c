/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:01:19 by abertran          #+#    #+#             */
/*   Updated: 2023/02/23 22:49:05 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

/* Asigna una posición a cada elemento de una pila de arriba a abajo. */
static void assign_positions(t_stack **stack)
{
    t_stack *tmp;
    int i;

    tmp = *stack;
    i = 0;
    while (tmp)
    {
        tmp->pos = i;
        tmp = tmp->next;
        i++;
    }
}

/* Determina la posición objetivo en stack A para un elemento dado de stack B. */
static int find_target_position(t_stack **stack_a, int index_b)
{
    t_stack *tmp;
    int target_position;
    int target_index;

    tmp = *stack_a;
    target_position = 0;
    target_index = INT_MAX;

    while (tmp)
    {
        if (tmp->index > index_b && tmp->index < target_index)
        {
            target_index = tmp->index;
            target_position = tmp->pos;
        }
        tmp = tmp->next;
    }

    if (target_index != INT_MAX)
        return target_position;

    tmp = *stack_a;
    while (tmp)
    {
        if (tmp->index < target_index)
        {
            target_index = tmp->index;
            target_position = tmp->pos;
        }
        tmp = tmp->next;
    }
    return target_position;
}

/* Encuentra la posición del elemento con el índice más bajo en la pila. */
int find_lowest_index_position(t_stack **stack)
{
    t_stack *tmp;
    int lowest_index;
    int lowest_position;

    tmp = *stack;
    lowest_index = INT_MAX;
    assign_positions(stack);
    lowest_position = tmp->pos;

    while (tmp)
    {
        if (tmp->index < lowest_index)
        {
            lowest_index = tmp->index;
            lowest_position = tmp->pos;
        }
        tmp = tmp->next;
    }
    return lowest_position;
}

/* Asigna una posición objetivo en stack A a cada elemento de stack B. */
void assign_target_positions(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;

    assign_positions(stack_a);
    assign_positions(stack_b);

    tmp = *stack_b;
    while (tmp)
    {
        tmp->target = find_target_position(stack_a, tmp->index);
        tmp = tmp->next;
    }
}

