/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:08:55 by albbermu          #+#    #+#             */
/*   Updated: 2024/10/23 15:31:08 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_to_top(t_stack *new_node, t_stack **stack)
{
	if (*stack == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*stack = new_node;
	}
	else
	{
		new_node->prev = (*stack)->prev;
		new_node->next = *stack;
		(*stack)->prev->next = new_node;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	if ((*stack_b)->next == *stack_b)
		*stack_b = NULL;
	else
	{
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = temp->prev;
		(*stack_b)->prev->next = *stack_b;
	}
	add_to_top(temp, stack_a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	if ((*stack_a)->next == *stack_a)
		*stack_a = NULL;
	else
	{
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = temp->prev;
		(*stack_a)->prev->next = *stack_a;
	}
	add_to_top(temp, stack_b);
	ft_putendl_fd("pb", 1);
}
