/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:04:38 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 12:51:50 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stacks *stacks, char c)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (c == 'a')
		ft_rotate_a(stacks, stacks->head_a, 1);
	else if (c == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		ft_rotate_b(stacks, stacks->head_b, 1);
	}
	else
	{
		if (head_a == NULL || head_a->next == NULL
			||head_b == NULL | head_b->next == NULL)
			return ;
		ft_rotate_a(stacks, stacks->head_a, 0);
		ft_rotate_b(stacks, stacks->head_b, 0);
		ft_printf("rr\n");
	}
}

void	ft_rotate_a(t_stacks *stacks, t_stack_a *head_a, int flag)
{
	t_stack_a	*tmp;

	tmp = head_a;
	stacks->head_a = head_a->next;
	while (head_a->next != NULL)
		head_a = head_a->next;
	head_a->next = tmp;
	tmp->next = NULL;
	if (flag)
		ft_printf("ra\n");
}

void	ft_rotate_b(t_stacks *stacks, t_stack_a *head_b, int flag)
{
	t_stack_b	*tmp;

	tmp = head_b;
	stacks->head_b = head_b->next;
	while (head_b->next != NULL)
		head_b = head_b->next;
	head_b->next = tmp;
	tmp->next = NULL;
	if (flag)
		ft_printf("rb\n");
}
