/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:52:10 by albbermu          #+#    #+#             */
/*   Updated: 2024/10/23 17:22:54 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicates(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = i + 1;
		while (input[j])
		{
			if (ft_atoi(input[i]) == ft_atoi(input[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_input(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!is_number(input[i]) || ft_atol(input[i]) > 2147483647
			|| ft_atol(input[i]) < -2147483648)
			return (1);
		i++;
	}
	if (has_duplicates(input))
		return (1);
	return (0);
}
