/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_min_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:48:45 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 19:54:12 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_max_min_b(t_stacks *stacks)
{
	if (stacks->head_b != NULL)
	{
		check_max_b(stacks, stacks->head_b);
		check_min_b(stacks, stacks->head_b);
	}
}

void	check_max_b(t_stacks *stacks, t_stack_b *head_b)
{
	int	i;
	int	size;

	i = 0;
	size = ft_listsize_b(head_b);
	stacks->value->max_b = head_b->content;
	while (i < size)
	{
		if (stacks->value->max_b < head_b->content)
			stacks->value->max_b = head_b->content;
		head_b = head_b->next;
		i++;
	}
}

void	check_min_b(t_stacks *stacks, t_stack_b *head_b)
{
	int	i;
	int	size;

	i = 0;
	size = ft_listsize_b(head_b);
	stacks->value->min_b = head_b->content;
	while (i < size)
	{
		if (stacks->value->min_b > head_b->content)
			stacks->value->min_b = head_b->content;
		head_b = head_b->next;
		i++;
	}
}
