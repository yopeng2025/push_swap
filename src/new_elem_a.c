/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:01:27 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 12:58:39 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_elem_a(t_stacks *stacks, t_stack_b *head_b)
{
	int	i;
	int	size;

	stacks->move->rra = 0;
	stacks->move->ra = 0;
	if (stacks->head_a->content != search_a(stacks, head_b->content))
	{
		size = ft_listsize_a(stacks->head_a);
		i = find_index_stack_a(stacks, search_a(stacks, head_b->content));
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
	move_elem_a(stacks);
}

void	move_elem_a(t_stacks *stacks)
{
	while (stacks->move->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	while (stacks->move->ra-- != 0)
		ft_rotate(stacks, 'a');
	ft_push(stacks, 'a');
}

int	search_a(t_stacks *stacks, int n)
{
	int			i;
	int			size;
	t_stack_a	*head_a;

	i = 0;
	size = ft_listsize_a(stacks->head_a);
	while (1)
	{
		n++;
		head_a = stacks->head_a;
		i = 0;
		while (i < size)
		{
			if (n == head_a->content)
				return (n);
			head_a = head_a->next;
			i++;
		}
	}
}
