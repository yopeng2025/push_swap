/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:35:46 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 16:02:53 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stacks *stacks)
{
	ft_clearnodes_a(&stacks->head_a);
	ft_clearnodes_b(&stacks->head_b);
	free(stacks->move);
	free(stacks->value);
	free(stacks->fast);
}

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
