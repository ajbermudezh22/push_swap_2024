/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:04:02 by albbermu          #+#    #+#             */
/*   Updated: 2024/10/23 16:47:42 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_and_init_stacks(int argc, char **input, t_stack **stack_a,
	t_stack **stack_b)
{
	if (validate_input(input) == 1)
	{
		if (argc == 2)
			release_memory(input);
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	*stack_a = initialize_stack(argc - 1, input);
	if (*stack_a == NULL)
	{
		if (argc == 2)
			release_memory(input);
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	*stack_b = NULL;
}

char	**parse_input(int argc, char *argv[])
{
	char	**input;

	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		if (input == NULL || *input == NULL)
		{
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
	}
	else
		input = &argv[1];
	return (input);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**input;

	if (argc < 2)
		return (0);
	input = parse_input(argc, argv);
	validate_and_init_stacks(argc, input, &stack_a, &stack_b);
	if (argc == 2)
		release_memory(input);
	sort_stacks(&stack_a, &stack_b);
	clear_stack(stack_a);
	return (0);
}
