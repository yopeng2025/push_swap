/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:55:52 by yopeng            #+#    #+#             */
/*   Updated: 2025/09/01 12:44:40 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rotate(t_stacks *stacks, char c)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (c == 'a')
		ft_rotate_a_bonus(stacks, stacks->head_a);
	else if (c == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		ft_rotate_b_bonus(stacks, stacks->head_b);
	}
	else
	{
		if (head_a == NULL || head_a->next == NULL
			||head_b == NULL | head_b->next == NULL)
			return ;
		ft_rotate_a_bonus(stacks, stacks->head_a);
		ft_rotate_b_bonus(stacks, stacks->head_b);
	}
}

void	ft_rotate_a_bonus(t_stacks *stacks, t_stack_a *head_a)
{
	t_stack_a	*tmp;

	tmp = head_a;
	stacks->head_a = head_a->next;
	while (head_a->next != NULL)
		head_a = head_a->next;
	head_a->next = tmp;
	tmp->next = NULL;
}

void	ft_rotate_b_bonus(t_stacks *stacks, t_stack_a *head_b)
{
	t_stack_b	*tmp;

	tmp = head_b;
	stacks->head_b = head_b->next;
	while (head_b->next != NULL)
		head_b = head_b->next;
	head_b->next = tmp;
	tmp->next = NULL;
}
