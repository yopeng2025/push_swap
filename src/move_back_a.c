/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:58:28 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 12:45:06 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_back_a(t_stacks *stacks)
{
	while (stacks->head_b != NULL)
	{
		check_max_min_a(stacks);
		if (stacks->head_b->content > stacks->value->max_a)
			new_max_a(stacks);
		else if (stacks->head_b->content < stacks->value->min_a)
			new_min_a(stacks);
		else
			new_elem_a(stacks, stacks->head_b);
	}
	check_max_min_a(stacks);
	put_in_order(stacks);
}

void	put_in_order(t_stacks *stacks)
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
	move_order(stacks);
}

void	move_order(t_stacks *stacks)
{
	while (stacks->move->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	while (stacks->move->ra-- != 0)
		ft_rotate(stacks, 'a');
}
