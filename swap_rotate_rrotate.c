/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate_rrotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:45:55 by albbermu          #+#    #+#             */
/*   Updated: 2024/10/23 15:07:59 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !(*stack) || (*stack)->next == *stack)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next->prev = first;
	second->prev = first->prev;
	first->prev->next = second;
	second->next = first;
	first->prev = second;
	*stack = second;
	ft_putendl_fd("sa", 1);
}

void	ra(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
	ft_putendl_fd("ra", 1);
}

void	rra(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
	ft_putendl_fd("rra", 1);
}
