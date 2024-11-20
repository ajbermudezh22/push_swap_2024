/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:37:10 by albbermu          #+#    #+#             */
/*   Updated: 2024/10/23 16:44:14 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_stack *stack, char stack_name)
{
	t_stack	*temp;

	temp = stack;
	printf("Displaying stack %c:\n", stack_name);
	while (temp->next != stack)
	{
		printf("[%d] -> ", temp->value);
		temp = temp->next;
	}
	printf("[%d]\n", temp->value);
}

int	*convert_stack_to_array(int count, t_stack *stack)
{
	int	*array;
	int	i;

	array = malloc(count * sizeof(int));
	i = 0;
	if (!array)
		return (NULL);
	while (i < count && stack)
	{
		array[i] = stack->value;
		i++;
		stack = stack->next;
	}
	return (array);
}

void	sort_int_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	get_position_of_min(t_stack *stack)
{
	t_stack	*temp;
	int		min_value;

	temp = stack;
	min_value = stack->value;
	while (temp->next != stack)
	{
		if (temp->value < min_value)
			min_value = temp->value;
		temp = temp->next;
	}
	return (min_value);
}

void	assign_positions(t_stack *stack, int *array, int count)
{
	t_stack	*temp;
	int		i;

	i = 0;
	while (i < count)
	{
		temp = stack;
		while (temp)
		{
			if (temp->value == array[i])
			{
				temp->index = i;
				break ;
			}
			temp = temp->next;
		}
		i++;
	}
}
