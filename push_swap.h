/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:14:42 by abertran          #+#    #+#             */
/*   Updated: 2023/03/09 12:57:13 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

long		input_is_correct(char *av);
void		error_exit(t_stack **stack_a, t_stack **stack_b);
void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
void		get_index(t_stack *stack_a, int stack_size);
t_stack		*create_node(int value);
void		add_last(t_stack **stack, t_stack *new);
t_stack		*get_tail(t_stack *stack);
t_stack		*before_tail(t_stack *stack);
int			get_stack_size(t_stack	*stack);
int			is_sorted(t_stack *stack);
void		sort_3(t_stack **stack);
void		sa(t_stack **stack_a);
void		sa(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		ft_putstr(char *str);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		sort(t_stack **stack_a, t_stack **stack_b);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);
void		cost(t_stack **stack_a, t_stack **stack_b);
void		cheapest_move(t_stack **stack_a, t_stack **stack_b);
int			abs(int nb);
void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
int			position_lowest_index(t_stack **stack);
char		**ft_split(char const *s, char c);
void		get_numbers(char *argv, t_stack **stack_a);
int			is_duplicate(t_stack *column);
size_t		ft_strlen(const char *s);

#endif
