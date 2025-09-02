/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_min_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:41:48 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 13:02:11 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_max_min_a(t_stacks *stacks)
{
	check_max_a(stacks, stacks->head_a);
	check_min_a(stacks, stacks->head_a);
}

void	check_max_a(t_stacks *stacks, t_stack_a *head_a)
{
	int	i;
	int	size;

	i = 0;
	size = ft_listsize_a(head_a);
	stacks->value->max_a = head_a->content;
	while (i < size)
	{
		if (stacks->value->max_a < head_a->content)
			stacks->value->max_a = head_a->content;
		head_a = head_a->next;
		i++;
	}
}

void	check_min_a(t_stacks *stacks, t_stack_a *head_a)
{
	int	i;
	int	size;

	i = 0;
	size = ft_listsize_a(head_a);
	stacks->value->min_a = head_a->content;
	while (i < size)
	{
		if (stacks->value->min_a > head_a->content)
			stacks->value->min_a = head_a->content;
		head_a = head_a->next;
		i++;
	}
}
