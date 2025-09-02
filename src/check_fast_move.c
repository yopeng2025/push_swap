/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fast_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:02:18 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 17:11:44 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_fast_move(t_stacks *stacks)
{
	int			i;
	int			size;
	t_stack_a	*head_a;

	size = ft_listsize_a(stacks->head_a);
	head_a = stacks->head_a;
	i = 0;
	while (i++ < size)
	{
		get_top_stack_a(stacks, head_a, i - 1);
		if (head_a->content > stacks->value->max_b || \
			head_a->content < stacks->value->min_b)
			new_max_min_b(stacks);
		else
			new_elem_b(stacks, head_a->content);
		check_double_move(stacks);
		check_cost(stacks, i);
		head_a = head_a->next;
	}
}

void	get_top_stack_a(t_stacks *stacks, t_stack_a *head_a, int i)
{
	int	size;

	stacks->move->pb = 1;
	stacks->move->rra = 0;
	stacks->move->ra = 0;
	if (stacks->head_a->content == head_a->content)
		return ;
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

void	check_double_move(t_stacks *stacks)
{
	stacks->move->rr = 0;
	stacks->move->rrr = 0;
	while (stacks->move->ra != 0 && stacks->move->rb != 0)
	{
		stacks->move->ra--;
		stacks->move->rb--;
		stacks->move->rr++;
	}
	while (stacks->move->rra != 0 && stacks->move->rrb != 0)
	{
		stacks->move->rra--;
		stacks->move->rrb--;
		stacks->move->rrr++;
	}
}

void	check_cost(t_stacks *stacks, int i)
{
	stacks->move->cost = stacks->move->pb
		+ stacks->move->ra + stacks->move->rb
		+ stacks->move->rr + stacks->move->rrr
		+ stacks->move->rra + stacks->move->rrb;
	if (i == 1 || stacks->fast->cost > stacks->move->cost)
	{
		stacks->fast->cost = stacks->move->cost;
		stacks->fast->pb = stacks->move->pb;
		stacks->fast->ra = stacks->move->ra;
		stacks->fast->rb = stacks->move->rb;
		stacks->fast->rr = stacks->move->rr;
		stacks->fast->rra = stacks->move->rra;
		stacks->fast->rrb = stacks->move->rrb;
		stacks->fast->rrr = stacks->move->rrr;
	}
}
