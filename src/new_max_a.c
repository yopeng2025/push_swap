/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_max_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:38:38 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 13:01:19 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_max_a(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->move->ra = 0;
	stacks->move->rra = 0;
	if (ft_listlast_a(stacks->head_a)->content != stacks->value->max_a)
	{
		i = find_index_stack_a(stacks, stacks->value->max_a);
		size = ft_listsize_a(stacks->head_a);
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				stacks->move->rra = (size - i) - 1;
			else
				stacks->move->ra = i + 1;
		}
		else
		{
			if (i > size / 2)
				stacks->move->rra = (size - i) - 1;
			else
				stacks->move->ra = i + 1;
		}
	}
	move_max_a(stacks);
}

void	move_max_a(t_stacks *stacks)
{
	while (stacks->move->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->move->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
	ft_rotate(stacks, 'a');
}

int	find_index_stack_a(t_stacks *stacks, int n)
{
	t_stack_a	*head_a;
	int			size;
	int			i;

	size = ft_listsize_a(stacks->head_a);
	head_a = stacks->head_a;
	i = 0;
	while (i < size)
	{
		if (head_a->content == n)
			break ;
		head_a = head_a->next;
		i++;
	}
	return (i);
}
