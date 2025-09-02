/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:09:45 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 18:19:22 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_elem_b(t_stacks *stacks, int num_a)
{
	int	num_b;
	int	size;
	int	i;

	stacks->move->rrb = 0;
	stacks->move->rb = 0;
	num_b = search_num_stack_b(stacks, num_a);
	size = ft_listsize_b(stacks->head_b);
	i = find_index_stack_b(stacks, num_b);
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

int	search_num_stack_b(t_stacks *stacks, int num_a)
{
	int			flag;
	int			size;
	int			i;
	t_stack_b	*head_b;

	i = 0;
	flag = 0;
	size = ft_listsize_b(stacks->head_b);
	head_b = stacks->head_b;
	while (flag == 0)
	{
		i = 0;
		num_a--;
		head_b = stacks->head_b;
		while (i < size)
		{
			if (head_b->content == num_a)
				flag = 1;
			head_b = head_b->next;
			i++;
		}
	}
	return (num_a);
}
