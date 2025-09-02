/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:39:05 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 12:50:51 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stacks *stacks, char c)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (c == 'a')
		ft_swap_a(head_a, 1);
	else if (c == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		ft_swap_b(head_b, 1);
	}
	else
	{
		if (head_a == NULL || head_a->next == NULL
			|| head_b == NULL || head_b->next == NULL)
			return ;
		ft_swap_a(head_a, 0);
		ft_swap_b(head_b, 0);
		ft_printf("ss\n");
	}
}

void	ft_swap_a(t_stack_a *head_a, int flag)
{
	int	tmp;

	tmp = head_a->content;
	head_a->content = head_a->next->content;
	head_a->next->content = tmp;
	if (flag)
		ft_printf("sa\n");
}

void	ft_swap_b(t_stack_b *head_b, int flag)
{
	int	tmp;

	tmp = head_b->content;
	head_b->content = head_b->next->content;
	head_b->next->content = tmp;
	if (flag)
		ft_printf("sb\n");
}
