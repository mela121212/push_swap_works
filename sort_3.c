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