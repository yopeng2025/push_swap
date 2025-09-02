/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:18:55 by yopeng            #+#    #+#             */
/*   Updated: 2025/09/01 13:00:31 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
			error_exit_bonus();
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
				error_exit_bonus();
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
			error_exit_bonus();
		i++;
	}
}

void	check_double_int(t_stack_a *head_a)
{
	t_stack_a	*tmp1;
	t_stack_a	*tmp2;
	int			n;

	tmp1 = head_a;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1;
		n = tmp2->content;
		tmp2 = tmp2->next;
		while (tmp2 != NULL)
		{
			if (tmp2->content == n)
			{
				ft_putstr_fd("Error\n", 2);
				ft_clearnodes_a(&head_a);
				exit(1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
