/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:08:38 by abertran          #+#    #+#             */
/*   Updated: 2023/03/08 20:42:12 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

/* Checks if the input is correct, in which case it initializes stacks a and b,
   assigns each value indexes and sorts the stacks. When sorting is done, frees
   the stacks and exits.
   system("leaks push_swap");  */

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	int		i;

	i = 1;
	stack_b = NULL;
	stack_a = NULL;
	while (i < ac)
	{
		fill_stack(av[i], &stack_a);
		i++;
	}
	if (is_duplicate(stack_a))
		error_exit(&stack_a, NULL);
	stack_size = get_stack_size(stack_a);
	get_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}