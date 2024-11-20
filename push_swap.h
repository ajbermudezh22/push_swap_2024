/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:04:19 by albbermu          #+#    #+#             */
/*   Updated: 2024/10/23 16:54:31 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// check_input
int		validate_input(char **input);

// stack_initialization
t_stack	*initialize_stack(int count, char **input);
int		get_node_count(t_stack *stack);

// push
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

// swap_rotate_rrotate
void	sa(t_stack **stack);
void	ra(t_stack **stack);
void	rra(t_stack **stack);

// sorting
int		is_sorted(t_stack *stack);
void	sort_stacks(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
void	sort_five(t_stack **stack_a, t_stack **stack_b, int count);
void	radix_sort(t_stack **stack_a, t_stack **stack_b, int count);

// stack_memory
void	release_memory(char **data);
void	clear_stack(t_stack *stack);
void	raise_error_and_cleanup(int count, char **input, char *message);

// stack_helpers
void	display_stack(t_stack *stack, char stack_name);
int		*convert_stack_to_array(int count, t_stack *stack);
void	sort_int_array(int *array, int size);
int		get_position_of_min(t_stack *stack);
void	assign_positions(t_stack *stack, int *array, int count);

#endif
