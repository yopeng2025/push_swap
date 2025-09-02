/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:32:53 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 13:03:47 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_stacks *stacks)
{
	t_fast	*fast;
	t_move	*move;
	t_value	*value;

	fast = ft_calloc(1, sizeof(t_fast));
	stacks->fast = fast;
	move = ft_calloc(1, sizeof(t_move));
	stacks->move = move;
	value = ft_calloc(1, sizeof(t_value));
	stacks->value = value;
	ft_push(stacks, 'b');
	sort_three(stacks, 0);
	move_back_a(stacks);
	free_all(stacks);
	exit(0);
}
