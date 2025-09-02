/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:11:04 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 16:02:45 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(int ac, char **av)
{
	if (ac == 1)
		exit(0);
	check_int(ac, av);
	check_int_size(ac, av);
}

void	check_int(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '\0')
			error_exit();
		while (j < (int)ft_strlen(av[i]))
		{
			if (!ft_isdigit(av[i][j]))
			{
				if (j == 0 && ft_strlen(av[i]) != 1 && (av[i][j] == '-'
					|| av[i][j] == '+'))
				{
					j++;
					continue ;
				}
				error_exit();
			}
			j++;
		}
		i++;
	}
}

void	check_int_size(int ac, char **av)
{
	long	num;
	int		i;

	i = 1;
	while (i < ac)
	{
		num = ft_atol(av[i]);
		if (num > INTMAX || num < INTMIN)
			error_exit();
		i++;
	}
}
