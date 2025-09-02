/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:17:57 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 19:48:19 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_fast(t_stacks *stacks)
{
	t_fast	*fast;
	t_move	*move;
	t_value	*value;

	fast = ft_calloc(1, sizeof(t_fast));
	move = ft_calloc(1, sizeof(t_move));
	value = ft_calloc(1, sizeof(t_value));
	stacks->fast = fast;
	stacks->move = move;
	stacks->value = value;
	while (ft_listsize_a(stacks->head_a) != 3)
	{
		check_max_min_b(stacks);
		check_fast_move(stacks);
		do_move_fast(stacks);
	}
}

void	do_move_fast(t_stacks *stacks)
{
	while (stacks->fast->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->fast->rb-- != 0)
		ft_rotate(stacks, 'b');
	while (stacks->fast->rr-- != 0)
		ft_rotate(stacks, 'r');
	while (stacks->fast->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	while (stacks->fast->rrb-- != 0)
		ft_rev_rotate(stacks, 'b');
	while (stacks->fast->rrr-- != 0)
		ft_rev_rotate(stacks, 'r');
	while (stacks->fast->pb-- != 0)
		ft_push(stacks, 'b');
}
