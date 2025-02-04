/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:01:19 by abertran          #+#    #+#             */
/*   Updated: 2023/02/23 22:49:05 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Realiza rotaciones o rotaciones inversas en una pila hasta que el costo sea 0. */
static void rotate_stack(t_stack **stack, int *cost, void (*rotate)(t_stack **), void (*reverse_rotate)(t_stack **))
{
    while (*cost)
    {
        if (*cost > 0)
        {
            rotate(stack);
            (*cost)--;
        }
        else
        {
            reverse_rotate(stack);
            (*cost)++;
        }
    }
}

/* Realiza rotaciones inversas simultáneas en ambas pilas mientras los costos sean negativos. */
static void reverse_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
    while (*cost_a < 0 && *cost_b < 0)
    {
        (*cost_a)++;
        (*cost_b)++;
        rrr(a, b);
    }
}

/* Realiza rotaciones normales simultáneas en ambas pilas mientras los costos sean positivos. */
static void rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        (*cost_a)--;
        (*cost_b)--;
        rr(a, b);
    }
}

/* Ejecuta la estrategia óptima para mover el elemento correcto de B a A. */
void do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
    if (cost_a * cost_b > 0) // Ambos costos positivos o negativos
    {
        if (cost_a > 0)
            rotate_both(a, b, &cost_a, &cost_b);
        else
            reverse_both(a, b, &cost_a, &cost_b);
    }

    // Ajusta cada pila individualmente
    rotate_stack(a, &cost_a, ra, rra);
    rotate_stack(b, &cost_b, rb, rrb);

    // Empuja el elemento superior de B a A
    pa(a, b);
}

