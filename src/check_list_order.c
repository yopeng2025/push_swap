/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_order.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:03:26 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 15:47:37 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_list_order(t_stacks *stacks)
{
	t_stack_a	*head_a;
	int			n;
	int			i;

	i = 1;
	head_a = stacks->head_a;
	n = head_a->content;
	while (i < ft_listsize_a(stacks->head_a))
	{
		head_a = head_a->next;
		if (n > head_a->content)
			return (0);
		n = head_a->content;
		i++;
	}
	ft_clearnodes_a(&stacks->head_a);
	exit(0);
}
