/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_min_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:38:58 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 12:59:43 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_min_a(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->move->rra = 0;
	stacks->move->ra = 0;
	if (stacks->head_a->content != stacks->value->min_a)
	{
		i = find_index_stack_a(stacks, stacks->value->min_a);
		size = ft_listsize_a(stacks->head_a);
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				stacks->move->rra = (size - i);
			else
				stacks->move->ra = i;
		}
		else
		{
			if (i > size / 2)
				stacks->move->rra = (size - i);
			else
				stacks->move->ra = i;
		}
	}
	move_min_a(stacks);
}

void	move_min_a(t_stacks *stacks)
{
	while (stacks->move->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	while (stacks->move->ra-- != 0)
		ft_rotate(stacks, 'a');
	ft_push(stacks, 'a');
}
