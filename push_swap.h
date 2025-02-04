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

// Structure Definition
typedef struct s_stack
{
    int value;
    int index;
    int pos;
    int target;
    int cost_a;
    int cost_b;
    struct s_stack *next;
} t_stack;

// Main Function
int main(int argc, char **argv);

// Stack Operations
void sa(t_stack **stack);
void sb(t_stack **stack);
void ss(t_stack **stack_a, t_stack **stack_b);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);
void ra(t_stack **stack);
void rb(t_stack **stack);
void rr(t_stack **stack_a, t_stack **stack_b);
void rra(t_stack **stack);
void rrb(t_stack **stack);
void rrr(t_stack **stack_a, t_stack **stack_b);

// Stack Utilities
void add_node(t_stack **stack, t_stack *new_node);
t_stack *create_node(int value);
t_stack *get_last_node(t_stack *stack);
t_stack *get_second_last_node(t_stack *stack);
int get_stack_size(t_stack *stack);
void free_stack(t_stack **stack);

// Sorting Functions
int	is_sorted(t_stack *stack);
void sort(t_stack **stack_a, t_stack **stack_b);
void sort_three(t_stack **stack);
void assign_target_positions(t_stack **stack_a, t_stack **stack_b);
int find_lowest_index_position(t_stack **stack);
void cheapest_move(t_stack **stack_a, t_stack **stack_b);
void do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

// Input Handling
void	fill_stack(char *input, t_stack **stack_a);
long	input_is_correct(char *str);
int		is_duplicate(t_stack *column);

// Error Handling
void error_exit(t_stack **stack_a, t_stack **stack_b);

// Index and Position Management
void get_index(t_stack *stack_a, int stack_size);

// Utility Functions
long int ft_atoi(const char *str);
void ft_putstr(char *str);
int abs(int nb);
char **ft_split(char const *s, char c);
size_t ft_strlen(const char *s);

#endif
