/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:55:38 by yopeng            #+#    #+#             */
/*   Updated: 2025/09/01 12:35:48 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_push(t_stacks *stacks, char c)
{
	t_stack_b	*head_b;

	head_b = stacks->head_b;
	if (c == 'a')
	{
		if (head_b == NULL)
			return ;
		else if (head_b->next == NULL)
			ft_push_a_last(stacks);
		else
			ft_push_a(stacks);
	}
	else if (c == 'b')
	{
		if (head_b == NULL)
			ft_push_b_empty(stacks);
		else
			ft_push_b(stacks);
	}
}

void	ft_push_a(t_stacks *stacks)
{
	t_stack_a	*tmp;

	tmp = stacks->head_a;
	stacks->head_a = stacks->head_b;
	stacks->head_b = stacks->head_b->next;
	stacks->head_a->next = tmp;
}

void	ft_push_b(t_stacks *stacks)
{
	t_stack_b	*tmp;

	tmp = stacks->head_b;
	stacks->head_b = stacks->head_a;
	stacks->head_a = stacks->head_a->next;
	stacks->head_b->next = tmp;
}

void	ft_push_a_last(t_stacks *stacks)
{
	t_stack_a	*tmp;

	tmp = stacks->head_a;
	stacks->head_a = stacks->head_b;
	stacks->head_a->next = tmp;
	stacks->head_b = NULL;
}

void	ft_push_b_empty(t_stacks *stacks)
{
	stacks->head_b = stacks->head_a;
	stacks->head_a = stacks->head_a->next;
	stacks->head_b->next = NULL;
}
