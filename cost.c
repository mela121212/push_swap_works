/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:01:19 by abertran          #+#    #+#             */
/*   Updated: 2023/02/23 22:49:05 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calcula el costo de mover cada elemento de la pila B a su posición correcta en la pila A. */
static void calculate_costs(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_b;
    int size_a;
    int size_b;

	size_a = get_stack_size(*stack_a);
	size_b = get_stack_size(*stack_b);
    tmp_b = *stack_b;
    while (tmp_b)
    {
        // Coste de mover a la cima de B
        tmp_b->cost_b = (tmp_b->pos > size_b / 2) ? (size_b - tmp_b->pos) * -1 : tmp_b->pos;

        // Coste de mover a la posición objetivo en A
        tmp_b->cost_a = (tmp_b->target > size_a / 2) ? (size_a - tmp_b->target) * -1 : tmp_b->target;

        tmp_b = tmp_b->next;
    }
}

/* Encuentra el movimiento con el menor costo para mover de B a A */
static t_stack *find_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheapest_node;
    t_stack *tmp;

	cheapest_node = NULL;
	tmp = *stack_b;
	calculate_costs(stack_a, stack_b);
    int cheapest_cost = INT_MAX;

    while (tmp)
    {
        int total_cost = abs(tmp->cost_a) + abs(tmp->cost_b);
        if (total_cost < cheapest_cost)
        {
            cheapest_cost = total_cost;
            cheapest_node = tmp;
        }
        tmp = tmp->next;
    }
    return cheapest_node;
}

/* Mueve el elemento con el costo más bajo a su posición correcta en A */
void cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheapest_node;
	
	cheapest_node = find_cheapest_move(stack_a, stack_b);
    if (cheapest_node)
    {
        do_move(stack_a, stack_b, cheapest_node->cost_a, cheapest_node->cost_b);
    }
}
