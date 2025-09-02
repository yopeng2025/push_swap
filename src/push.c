/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:15:07 by yopeng            #+#    #+#             */
/*   Updated: 2025/08/28 16:20:11 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("pa\n");
}

void	ft_push_b(t_stacks *stacks)
{
	t_stack_b	*tmp;

	tmp = stacks->head_b;
	stacks->head_b = stacks->head_a;
	stacks->head_a = stacks->head_a->next;
	stacks->head_b->next = tmp;
	ft_printf("pb\n");
}

void	ft_push_a_last(t_stacks *stacks)
{
	t_stack_a	*tmp;

	tmp = stacks->head_a;
	stacks->head_a = stacks->head_b;
	stacks->head_a->next = tmp;
	stacks->head_b = NULL;
	ft_printf("pa\n");
}

void	ft_push_b_empty(t_stacks *stacks)
{
	stacks->head_b = stacks->head_a;
	stacks->head_a = stacks->head_a->next;
	stacks->head_b->next = NULL;
	ft_printf("pb\n");
}
