/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:03:26 by albbermu          #+#    #+#             */
/*   Updated: 2024/10/23 16:13:48 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	release_memory(char **data)
{
	int	i;

	if (!data)
		return ;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
}

void	clear_stack(t_stack *stack)
{
	t_stack	*curremt_node;
	t_stack	*temp_node;

	if (!stack)
		return ;
	curremt_node = stack;
	while (curremt_node->next != stack)
	{
		temp_node = curremt_node->next;
		free(curremt_node);
		curremt_node = temp_node;
	}
	free(curremt_node);
}

void	raise_error_and_cleanup(int count, char **input, char *message)
{
	if (message)
		ft_putendl_fd(message, 2);
	if (count == 2)
		release_memory(input);
	exit(EXIT_FAILURE);
}
