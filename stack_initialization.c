/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:36:44 by albbermu          #+#    #+#             */
/*   Updated: 2024/10/23 17:22:18 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*initialize_head(char **input)
{
	t_stack	*head;

	head = (t_stack *)malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head->value = ft_atoi(input[0]);
	head->next = head;
	head->prev = head;
	return (head);
}

static void	add_node_to_stack(t_stack *head, char *value)
{
	t_stack	*new_node;
	t_stack	*tail;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = ft_atoi(value);
	tail = head->prev;
	new_node->prev = tail;
	new_node->next = head;
	tail->next = new_node;
	head->prev = new_node;
}

t_stack	*initialize_stack(int count, char **input)
{
	t_stack	*head;
	int		i;

	i = 1;
	head = initialize_head(input);
	if (!head)
		raise_error_and_cleanup(count, input, "Malloc error");
	while (i < count)
	{
		add_node_to_stack(head, input[i]);
		i++;
	}
	return (head);
}

int	get_node_count(t_stack *stack)
{
	int		count;
	t_stack	*iterator;

	count = 0;
	iterator = stack;
	if (!stack)
		return (count);
	while (iterator->next != stack)
	{
		count++;
		iterator = iterator->next;
	}
	count++;
	return (count);
}
