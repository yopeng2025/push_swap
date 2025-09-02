/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_max_min_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:42:00 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 12:52:35 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_max_min_b(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->move->rrb = 0;
	stacks->move->rb = 0;
	if (stacks->head_b->content == stacks->value->max_b)
		return ;
	i = find_index_stack_b(stacks, stacks->value->max_b);
	size = ft_listsize_b(stacks->head_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->move->rrb = (size - i);
		else
			stacks->move->rb = i;
	}
	else
	{
		if (i > size / 2)
			stacks->move->rrb = (size - i);
		else
			stacks->move->rb = i;
	}
}
