/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:14:16 by albbermu          #+#    #+#             */
/*   Updated: 2024/10/23 16:36:11 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	if (!stack || stack->next == stack)
		return (1);
	while (current->next != stack)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	node_count;
	int	*array;

	node_count = get_node_count(*stack_a);
	if (is_sorted(*stack_a) == 1)
		return ;
	if (node_count <= 3)
		sort_three(stack_a);
	else if (node_count <= 5)
		sort_five(stack_a, stack_b, node_count);
	else
	{
		array = convert_stack_to_array(node_count, *stack_a);
		sort_int_array(array, node_count);
		assign_positions(*stack_a, array, node_count);
		free(array);
		radix_sort(stack_a, stack_b, node_count);
	}
}

void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && first > third)
		ra(stack);
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	min_position;

	while (count-- > 3)
	{
		min_position = get_position_of_min(*stack_a);
		while ((*stack_a)->value != min_position)
		{
			if (min_position <= get_node_count(*stack_a) / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int count)
{
	int		max_bits;
	int		i;
	int		j;
	t_stack	*current;

	max_bits = 0;
	i = 0;
	while ((count - 1) >> max_bits != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < count)
		{
			current = *stack_a;
			if (((current->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
