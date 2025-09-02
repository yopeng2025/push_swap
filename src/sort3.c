/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:33:02 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 13:04:08 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stacks *stacks, int flag)
{
	int			num1;
	int			num2;
	int			num3;
	t_stack_a	*head_a;

	head_a = stacks->head_a;
	num1 = head_a->content;
	num2 = head_a->next->content;
	num3 = head_a->next->next->content;
	move_three(stacks, num1, num2, num3);
	if (flag)
	{
		ft_clearnodes_a(&stacks->head_a);
		exit(0);
	}
}

void	move_three(t_stacks *stacks, int n1, int n2, int n3)
{
	if (n1 > n2 && n1 < n3 && n2 < n3)
		ft_swap(stacks, 'a');
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		ft_rotate(stacks, 'a');
	else if (n1 < n2 && n1 > n3 && n2 > n3)
		ft_rev_rotate(stacks, 'a');
	else if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		ft_swap(stacks, 'a');
		ft_rotate(stacks, 'a');
	}
	else if (n1 > n2 && n1 > n3 && n2 > n3)
	{
		ft_swap(stacks, 'a');
		ft_rev_rotate(stacks, 'a');
	}
}
