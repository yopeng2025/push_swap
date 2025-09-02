/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:31:15 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 19:53:55 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stacks *stacks)
{
	if (check_list_order(stacks))
		return ;
	if (ft_listsize_a(stacks->head_a) == 2)
		sort_two(stacks);
	else if (ft_listsize_a(stacks->head_a) == 3)
		sort_three(stacks, 1);
	else if (ft_listsize_a(stacks->head_a) == 4)
		sort_four(stacks);
	ft_push(stacks, 'b');
	ft_push(stacks, 'b');
	move_fast(stacks);
	sort_three(stacks, 0);
	move_back_a(stacks);
}
