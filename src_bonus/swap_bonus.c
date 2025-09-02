/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:55:58 by yopeng            #+#    #+#             */
/*   Updated: 2025/09/01 12:44:09 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap(t_stacks *stacks, char c)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (c == 'a')
		ft_swap_a_bonus(head_a);
	else if (c == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		ft_swap_b_bonus(head_b);
	}
	else
	{
		if (head_a == NULL || head_a->next == NULL
			|| head_b == NULL || head_b->next == NULL)
			return ;
		ft_swap_a_bonus(head_a);
		ft_swap_b_bonus(head_b);
	}
}

void	ft_swap_a_bonus(t_stack_a *head_a)
{
	int	tmp;

	tmp = head_a->content;
	head_a->content = head_a->next->content;
	head_a->next->content = tmp;
}

void	ft_swap_b_bonus(t_stack_b *head_b)
{
	int	tmp;

	tmp = head_b->content;
	head_b->content = head_b->next->content;
	head_b->next->content = tmp;
}
